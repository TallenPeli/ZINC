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
#include <vector>
#include <bits/stdc++.h>
#include "flag_handler.h"
#include "add_standard_functions.h"
#include "tokenizer.h"
#include "translator.h"

using namespace std;

// Variable declaration

bool isZincFile;

vector<string> translatedCode;

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

int main(int argc, char **argv) {
    // Pass the arguments to the flaghandler function found in '/src/flag_hander.cpp'
    flagHandler(argc, argv);

    // Defne a list of characters for the current working directory
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

    // Read and process each line of the input script
    string line;

    translatedCode.push_back(addFunctions());

    while (getline(zincFile, line)){
        int main_pos = line.find("main(");
        int find_print = line.find("print(");
        int find_println = line.find("println(");
        int find_loop = line.find("loop(");

        if ((main_pos == 0 || (main_pos != string::npos && (line[main_pos - 1] == ' ' || line[main_pos - 1] == ';' || line[main_pos - 1] == '}' || line[main_pos - 1] == '{')))) {
            string new_line = translate_main(line);
            translatedCode.push_back(new_line);

        } else if ((find_print == 0 || (find_print != string::npos && (line[find_print - 1] == ' ' || line[find_print - 1] == ';' || line[find_print - 1] == '}' || line[find_print - 1] == '{')))) {
            string new_line = translate_print(tokenize_print(line));
            translatedCode.push_back(new_line);

        } else if ((find_println == 0 || (find_println != string::npos && (line[find_println - 1] == ' ' || line[find_println - 1] == ';' || line[find_println - 1] == '}' || line[find_println - 1] == '{')))) {
            string new_line = translate_print(tokenize_println(line));
            translatedCode.push_back(new_line);

        } else if ((find_loop == 0 || (find_loop != string::npos && (line[find_loop - 1] == ' ' || line[find_loop - 1] == ';' || line[find_loop - 1] == '}' || line[find_loop - 1] == '{')))) {
            string new_line = translate_print(tokenize_loop(line));
            translatedCode.push_back(new_line);
        } else {
            // None of the conditions matched, so just add the line to the translated code
            translatedCode.push_back(line);
        }
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