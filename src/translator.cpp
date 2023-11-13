#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
bool isZincFile;

string join(const vector<string>& elements, const string& delimiter) {
    string result;
    for (int i = 0; i < elements.size(); ++i) {
        result += elements[i];
        if (i < elements.size() - 1) {
            result += delimiter;
        }
    }
    return result;
}
*/

// Takes the tokens from tokenize_print() and tokenize_println() and makes it a std::cout statement.
string translate_print(vector<string> tokens){
    string output;

    if (tokens.size() > 0) {
        int spacesCount = std::stoi(tokens[0]);

        // Append the specified number of spaces to the output string
        for (int i = 0; i < spacesCount; i++) {
            output.append(" ");
        }
    }

    output.append("std::cout << ");

    // For every token, add it to the output string.
    for(int i = 1; i < tokens.size(); i++){
        output.append(tokens[i]);
            
        // if not the last token add it to output string
        if(i + 1 != tokens.size()){
            output.append(" << ");
        } else{
            output.append(";");
        }
    }
    return output;
}

string translate_main(string line){
    int mainPos = line.find("main(");

    if (mainPos == 0 || (mainPos != string::npos && (line[mainPos - 1] == ' ' || line[mainPos - 1] == ';' || line[mainPos - 1] == '}'|| line[mainPos - 1] == '{'))) {
        line.replace(mainPos, 0, "int ");
    }

    return line;
}

string translate_fn(string line){
    int fnPos = line.find("fn ");

    if (fnPos == 0 || (fnPos != string::npos && (line[fnPos - 1] == ' ' || line[fnPos - 1] == ';' || line[fnPos - 1] == '}'|| line[fnPos - 1] == '{'))) {
        line.replace(fnPos, 3, "void ");
    }

    return line;
}

string translate_loop(vector<string> tokens){
    string line;
    if (tokens.size() > 0) {
        int spacesCount = std::stoi(tokens[0]);

        // Append the specified number of spaces to the output string
        for (int i = 0; i < spacesCount; i++) {
            line.append(" ");
        }
    }

    cout << tokens[0] << tokens[1] << tokens[2] << endl;
    string loop = "for(int " + tokens[2] + " = 0; " + tokens[2] + " < " + tokens[1] + "; " + tokens[2] + "++){";
    line.append(loop);
    return line;
}

/*
void translate(string line){
    // Comment handler
        int commentPos = line.find("//");
        if (commentPos != string::npos) {
            line = line.substr(0, commentPos);
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

        int letPos = line.find("let ");
        if(letPos == 0 || (letPos != string::npos && (line[letPos - 1] == ' ' || line[letPos - 1] == ';' || line[letPos - 1] == '}' || line[letPos - 1] == '{'))){
            int equalsPos = line.find("=");

            if((line[equalsPos + 1] == ' ' && line[equalsPos + 2] == '"') || line[equalsPos + 1] == '"'){
                int startQuotePos = line.find('"');
                if (startQuotePos != string::npos) {
                    int endQuotePos = line.find('"', startQuotePos + 1);
                
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

        int stringPos = line.find("string");
        if (stringPos == 0 || (stringPos != string::npos && (line[stringPos - 1] == ' ' || line[stringPos - 1] == ';' || line[stringPos - 1] == '}'|| line[stringPos - 1] == '{'))) {
            line.replace(stringPos, 6, "std::string");
        }

        // Translate loops
        int loopPos = line.find("loop(");
        if (loopPos == 0 || loopPos != string::npos && (line[loopPos - 1] == ' ' || line[loopPos - 1] == ';' || line[loopPos - 1] == '}' || line[loopPos - 1] == '{')) {
            // Check if there is an opening parenthesis
            int openParenthesisPos = line.find("(", loopPos);

            if (openParenthesisPos != string::npos) {
                // Extract the argument inside the loop function call
                int variableCommaSplitPos = line.find(",", openParenthesisPos);
                if (variableCommaSplitPos != string::npos) {
                    string loopArgument = line.substr(openParenthesisPos + 1, variableCommaSplitPos - openParenthesisPos - 1);

                    // Check the nesting level to determine the loop variable name
                    
                    int closeParenthsisPos = line.find(")", variableCommaSplitPos);
                    
                    string loopVarName = line.substr(variableCommaSplitPos + 1, closeParenthsisPos - variableCommaSplitPos - 1);

                    // Replace the loop function call with a for loop
                    line.replace(loopPos, closeParenthsisPos - loopPos + 1,
                        "for(int " + loopVarName + " = 0; " + loopVarName + " < " + loopArgument + "; " + loopVarName + "++)");
                }
            }
        }

        // Translate lists
        int listPos = line.find("list ");
        if (listPos != string::npos) {
            // Find the list name 
            int spaceAfterList = line.find("[", listPos + 5);
            // Make a variable to determine the type of variable that the list is composed of
            string listType;

            if (spaceAfterList != string::npos) {
                string listName = line.substr(listPos + 5, spaceAfterList - listPos - 5);

                // Find the opening bracket of the list
                int openBracketPos = line.find("[");
                if (openBracketPos != string::npos) {
                    // Find the closing bracket of the list
                    int closeBracketPos = line.find("]", openBracketPos);
                    if (closeBracketPos != string::npos) {
                        // Extract the list contents
                        string listContents = line.substr(openBracketPos + 1, closeBracketPos - openBracketPos - 1);

                        // Tokenize the list contents by comma
                        vector<string> items;
                        int start = 0;
                        int commaPos;
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

        // Add the translated line to the vector
        translatedCode.push_back(line);
}
*/