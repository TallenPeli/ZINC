#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

// Tokenize 'print();'
vector<string> tokenize_print(string line) {
    vector<string> tokens;

    // Remove comments
    int comment_pos = line.find("//");
    if (comment_pos != string::npos) {
        line = line.substr(0, comment_pos);
    }

    // This piece of code finds the whitespace for indentation for the line and allocates the first element in the vector to store this data.
    int white_space = 0;
    while (white_space < line.size() && line[white_space] == ' ') {
        white_space++;
    }

    tokens.push_back(to_string(white_space));

    // Remove the 'print(' at the beginning of the line
    int print_pos = line.find("print(");
    if (print_pos != string::npos) {
        line = line.substr(print_pos + 6); // Move forward by the length of "print("
    }

    // Logic to check if the string is in quotes. If true, ignore any commas in the line
    bool is_in_quotes = false;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '"') {
            is_in_quotes = !is_in_quotes;
        }

        // If string is not in quotations, find the comma and add the token to the vector
        if (line[i] == ',' && !is_in_quotes) {
            tokens.push_back(line.substr(0, i));
            line.erase(0, i + 1); // Move forward by the length of the token and the comma
            i = -1;  // Reset the loop counter to 0 to analyze the modified line again
        }
    }

    // Handle the last token
    tokens.push_back(line);

    // Handle the ';' in the last token
    int lastIndex = tokens.size() - 1;
    int last_token_length = tokens[lastIndex].length();
    for (int i = last_token_length - 1; i >= 0; i--) {
        if (tokens[lastIndex][i] == ')') {
            tokens[lastIndex].erase(i);  // Erase from ';' to the end
            break;
        }
    }

    return tokens;
}

// Tokenize 'println();'
vector<string> tokenize_println(string line) {
    vector<string> tokens;

    // Remove comments
    int comment_pos = line.find("//");
    if (comment_pos != string::npos) {
        line = line.substr(0, comment_pos);
    }

    // This piece of code finds the whitespace for indentation for the line and allocates the first element in the vector to store this data.
    int white_space = 0;
    while (white_space < line.size() && line[white_space] == ' ') {
        white_space++;
    }

    tokens.push_back(to_string(white_space));

    // Remove the 'println(' at the beginning of the line
    int print_pos = line.find("println(");
    if (print_pos != string::npos) {
        line = line.substr(print_pos + 8); // Move forward by the length of "println("
    }

    // Logic to check if the string is in quotes. If true, ignore any commas in the line
    bool is_in_quotes = false;

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '"') {
            is_in_quotes = !is_in_quotes;
        }

        if (line[i] == ',' && !is_in_quotes) {
            tokens.push_back(line.substr(0, i));
            line.erase(0, i + 1); // Move forward by the length of the token and the comma
            i = -1;  // Reset the loop counter to 0 to analyze the modified line again
        }
    }

    // Handle the last token
    tokens.push_back(line);

    // Handle the ';' in the last token
    int lastIndex = tokens.size() - 1;
    int last_token_length = tokens[lastIndex].length();
    for (int i = last_token_length - 1; i >= 0; i--) {
        if (tokens[lastIndex][i] == ')') {
            tokens[lastIndex].erase(i);  // Erase from ';' to the end
            break;
        }
    }

    tokens.push_back("\"\\n\"");

    return tokens;
}

// Tokenize 'loop();'
vector<string> tokenize_loop(string line) {
    vector<string> tokens;

    // Remove comments
    int comment_pos = line.find("//");
    if (comment_pos != string::npos) {
        line = line.substr(0, comment_pos);
    }

    // This piece of code finds the whitespace for indentation for the line and allocates the first element in the vector to store this data.
    int white_space = 0;
    while (white_space < line.size() && line[white_space] == ' ') {
        white_space++;
    }

    tokens.push_back(to_string(white_space));

    // Remove the 'loop(' at the beginning of the line
    int print_pos = line.find("loop(");
    if (print_pos != string::npos) {
        line = line.substr(print_pos + 5); // Move forward by the length of "loop("
    }

    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ',') {
            tokens.push_back(line.substr(0, i));
            line.erase(0, i + 1); // Move forward by the length of the token and the comma
            i = -1;  // Reset the loop counter to 0 to analyze the modified line again
        }
    }

    // Handle the last token
    tokens.push_back(line);

    // Handle the ';' in the last token
    int lastIndex = tokens.size() - 1;
    int last_token_length = tokens[lastIndex].length();
    for (int i = last_token_length - 1; i >= 0; i--) {
        if (tokens[lastIndex][i] == ')') {
            tokens[lastIndex].erase(i);  // Erase from ';' to the end
            break;
        }
    }

    int var_pos = tokens[2].find_first_not_of(" "); // Find the position of the first non-space character
    if (var_pos != string::npos) {
        tokens[2] = tokens[2].substr(var_pos); // Extract from the first non-space character till the end
    }

    return tokens;
}