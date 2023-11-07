// Copyright (c) 2023 ZINC-Studios
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS," WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
// OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT, OR OTHERWISE, ARISING FROM, OUT OF,
// OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include <cstdlib>
#include <functional>
#include "tokenizer.h"
#include "flag_handler.h"

using namespace std;

// Variable declaration

bool isZincFile = false;

// Colour definitions

/*======================*/
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
/*======================*/

// Add functions at the top of the translated C++ file
string addFunctions(){
    string code;
    code.append("#include <iostream>\n#include <string>\n#include <type_traits>\n#include <thread>\n#include <chrono>");
    code.append("\n//Standard Zinc functions from zincstd\n");
    code.append("using namespace std::chrono_literals;\n");
    code.append("template <typename T>\nvoid print(const T& input){std::cout << input;std::cout.flush();}\n");
    code.append("void print(std::string input){std::cout << input;std::cout.flush();}\n");
    code.append("template <typename T>\nvoid println(const T& input = T()) { if constexpr (!std::is_void_v<T>) std::cout << input << std::endl;std::cout.flush();}\n");
    code.append("void println(){std::cout << std::endl;std::cout.flush();}\n");
    code.append("void newline(){std::cout << std::endl;}\n");
    code.append("std::string input(std::string prompt){std::string Input;std::cout << prompt;std::cin >> Input;return Input;}\n");
    code.append("std::string getline(std::string prompt){std::string Input;std::cout << prompt;getline(std::cin, Input);return(Input);}\n");
    code.append("template <typename Rep, typename Period>\nvoid rest(const std::chrono::duration<Rep, Period>& duration){std::this_thread::sleep_for(duration);}");
    code.append("");

    return code;
}

void runCode(){
    if(verboseOutput){
        cout << "| " << CYAN << "Running the program..." << RESET << endl;
    }
    system("./zinc_output");
}

void compileCode(){
    string compilerFlags = optimizationList[optimization];
    
    if(verboseOutput == true){
        if(compileToAsssembly == false){
            cout << "| Compiling with [" << MAGENTA << compilerFlags << RESET << "]" << endl;
        }else{
            cout << "| Compiling to assembly. [" << MAGENTA << "zinc_to.asm" << RESET << "] " << "[" << MAGENTA << compilerFlags << RESET << "]"<< endl;
        }
    }

    if(compileToAsssembly == false){
        string command = "g++ -o zinc_output zinc_to.cpp " + compilerFlags;

        int compileResult = system(command.c_str());

        if (compileResult == 0) {
            if(verboseOutput){
                cout << "| " << GREEN << "Compilation successful." << RESET << endl;
            }
            runCode();
            if(keepTranslation){
                if(verboseOutput){
                    cout << "\n| " << MAGENTA << "Kept c++ translation.\n" << RESET;
                }
            }else{
                system("rm ./zinc_to.cpp");
            }

        } else {
            // Compilation failed
            cerr << "| " << RED << "Compilation failed. Please check the code for errors." << RESET << endl;
        }
    }else{
        string command = "g++ -S -o zinc_to.asm zinc_to.cpp " + compilerFlags;
        system(command.c_str());
    }
}

string join(const vector<string>& elements, const string& delimiter) {
    string result;
    for (size_t i = 0; i < elements.size(); ++i) {
        result += elements[i];
        if (i < elements.size() - 1) {
            result += delimiter;
        }
    }
    return result;
}


// Tokenizer returns a list of strings
string tokenize(string input){
    string tokens;
    size_t commaPos = input.find(",");
    if (commaPos != string::npos){
        string tokens = input.substr(0, commaPos);
    }
    return tokens;
}

int main(int argc, char **argv) {

    flagHandler(argc, argv);

    char cwd[1024];

    string argument = argv[1];

    string tmpcwd = getcwd(cwd, sizeof(cwd));
    string fullcwd = tmpcwd + "/" + argument;

    if(verboseOutput){
        cout << "| Full path [" << fullcwd << "]" << endl;
    }

    ifstream zincFile(fullcwd.c_str());
    if (!zincFile.is_open()) {
        cerr << "Error: File '" << fullcwd << "' does not exist." << endl;
        return 1;
    }

    // Create a vector to store the translated C++ code
    vector<string> translatedCode;

    // Read and process each line of the input script
    string line;

    while (getline(zincFile, line)) {
        // Comment handler
        size_t commentPos = line.find("//");
        if (commentPos != string::npos) {
            line = line.substr(0, commentPos);
        }

        size_t printPos = line.find("print(");
        if (printPos != string::npos){
            size_t close_bracket = line.find("\\)\\", printPos);
            if (close_bracket != string::npos) {
                string to_tokenize = line.substr(printPos + 6, close_bracket - printPos + 6);
                cout << tokenize(to_tokenize) << endl;
            }
        }

        // Check if the input file is a valid zinc file
        if(line == "using zincstd;" && !isZincFile){
            isZincFile = true;
            line.erase();
            line.append(addFunctions());
        }else if (!isZincFile){
            cout << "Error : Not a valid ZINC file [2]" << endl;
            exit(2);
        }

        // Translate 'fn ' to 'int ' for function declarations
        size_t fnPos = line.find("fn");
        if (fnPos == 0 || (fnPos != string::npos && (line[fnPos - 1] == ' ' || line[fnPos - 1] == ';' || line[fnPos - 1] == '}'|| line[fnPos - 1] == '{'))) {
            line.replace(fnPos, 2, "void ");
        }


        size_t letPos = line.find("let ");
        if(letPos == 0 || (letPos != string::npos && (line[letPos - 1] == ' ' || line[letPos - 1] == ';' || line[letPos - 1] == '}' || line[letPos - 1] == '{'))){
            size_t equalsPos = line.find("=");

            if((line[equalsPos + 1] == ' ' && line[equalsPos + 2] == '"') || line[equalsPos + 1] == '"'){
                size_t startQuotePos = line.find('"');
                if (startQuotePos != string::npos) {
                    size_t endQuotePos = line.find('"', startQuotePos + 1);
                
                    if (endQuotePos != string::npos) {
                        int length = endQuotePos - startQuotePos - 1;
                        if(length > 1){
                            line.replace(letPos, 4, "std::string ");
                        }else{
                            line.replace(letPos, 4, "auto ");
                        }
                    }
                }
            }else{
                line.replace(letPos, 4, "auto ");
            }
        }

        // Translate main
        size_t mainPos = line.find("main()");
        if (mainPos == 0 || (mainPos != string::npos && (line[mainPos - 1] == ' ' || line[mainPos - 1] == ';' || line[mainPos - 1] == '}'|| line[mainPos - 1] == '{'))) {
            line.replace(mainPos, 0, "int ");
        }

        size_t stringPos = line.find("string");
        if (stringPos == 0 || (stringPos != string::npos && (line[stringPos - 1] == ' ' || line[stringPos - 1] == ';' || line[stringPos - 1] == '}'|| line[stringPos - 1] == '{'))) {
            line.replace(stringPos, 6, "std::string");
        }

        // Translate loops
        size_t loopPos = line.find("loop(");
        if (loopPos == 0 || loopPos != string::npos && (line[loopPos - 1] == ' ' || line[loopPos - 1] == ';' || line[loopPos - 1] == '}' || line[loopPos - 1] == '{')) {
            // Check if there is an opening parenthesis
            size_t openParenthesisPos = line.find("(", loopPos);

            if (openParenthesisPos != string::npos) {
                // Extract the argument inside the loop function call
                size_t variableCommaSplitPos = line.find(",", openParenthesisPos);
                if (variableCommaSplitPos != string::npos) {
                    string loopArgument = line.substr(openParenthesisPos + 1, variableCommaSplitPos - openParenthesisPos - 1);

                    // Check the nesting level to determine the loop variable name
                    
                    size_t closeParenthsisPos = line.find(")", variableCommaSplitPos);
                    
                    string loopVarName = line.substr(variableCommaSplitPos + 1, closeParenthsisPos - variableCommaSplitPos - 1);

                    // Replace the loop function call with a for loop
                    line.replace(loopPos, closeParenthsisPos - loopPos + 1,
                        "for(int " + loopVarName + " = 0; " + loopVarName + " < " + loopArgument + "; " + loopVarName + "++)");
                }
            }
        }

        // Translate lists
        size_t listPos = line.find("list ");
        if (listPos != string::npos) {
            // Find the list name 
            size_t spaceAfterList = line.find("[", listPos + 5);
            // Make a variable to determine the type of variable that the list is composed of
            string listType;

            if (spaceAfterList != string::npos) {
                string listName = line.substr(listPos + 5, spaceAfterList - listPos - 5);

                // Find the opening bracket of the list
                size_t openBracketPos = line.find("[");
                if (openBracketPos != string::npos) {
                    // Find the closing bracket of the list
                    size_t closeBracketPos = line.find("]", openBracketPos);
                    if (closeBracketPos != string::npos) {
                        // Extract the list contents
                        string listContents = line.substr(openBracketPos + 1, closeBracketPos - openBracketPos - 1);

                        // Tokenize the list contents by comma
                        vector<string> items;
                        size_t start = 0;
                        size_t commaPos;
                        while ((commaPos = listContents.find(",", start)) != string::npos) {
                            items.push_back(listContents.substr(start, commaPos - start));
                            start = commaPos + 2;  // Skip the comma and the space
                        }
                        // Add the last item
                        items.push_back(listContents.substr(start));

                        // Generate the C++ array declaration
                        line = listName + "[" + to_string(items.size()) + "] = {" + join(items, ", ") + "};";
                    }
                }
            }
        }

        // Translate wait()
        size_t waitPos = line.find("wait(");
        if (waitPos == 0 || (waitPos != string::npos && (line[waitPos - 1] == ' ' || line[waitPos - 1] == ';' || line[waitPos - 1] == '}'|| line[waitPos - 1] == '{'))) {
            
        }

        // Add the translated line to the vector
        translatedCode.push_back(line);
    }

    // Close the input script file
    zincFile.close();

    // Output the translated C++ code to a file
    ofstream outputFile("zinc_to.cpp");

    if (!outputFile.is_open()) {
        cerr << "Error: Unable to create output file." << endl;
        return 1;
    }

    for (const string& translatedLine : translatedCode) {
        outputFile << translatedLine << endl;
    }

    compileCode();

    // Close the output file
    outputFile.close();

    return 0;
}