#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    char cwd[1024];

    string argument = argv[1];

    if (argument.substr(0, 2) == "./") {
        argument = argument.substr(2);
    }

    string tmpcwd = getcwd(cwd, sizeof(cwd));
    string fullcwd = tmpcwd + "/" + argument;
    cout << "Full path: " << fullcwd << endl;

    ifstream zincFile(fullcwd.c_str());
    if (!zincFile.is_open()) {
        cerr << "Error: File '" << fullcwd << "' does not exist." << endl;
        return 1;
    }

    // Create a vector to store the translated C++ code
    std::vector<std::string> translatedCode;

    translatedCode.push_back("#include <iostream>\nusing namespace std;");

    // Read and process each line of the input script
    std::string line;
    while (std::getline(zincFile, line)) {
        // Translate 'using zinc;' to a comment in C++
        if (line.find("using zincstd;") != std::string::npos) {
            translatedCode.push_back("// Translated: using zinc;");
            line.erase();
            
        }

        // Translate 'fn ' to 'int ' for function declarations
        size_t fnPos = line.find("fn ");
        if (fnPos != std::string::npos) {
            line.replace(fnPos, 3, "int ");
        }

        // Translate 'println(' to 'std::cout << ' with newline
        size_t printlnPos = line.find("println(");
        if (printlnPos != std::string::npos) {
            line.replace(printlnPos, 8, "cout << ");
            line.replace((line.length() - 2), line.length(), " << endl;");
        }

        // Translate 'print(' to 'std::cout << '
        size_t printPos = line.find("print(");
        if (printPos != std::string::npos) {
            line.replace(printPos, 6, "cout << ");
            line.replace((line.length() - 2), (line.length() - 2), "");
            line.insert(line.length(), ";");
        }

        size_t mainPos = line.find("main()");
        if (mainPos != std::string::npos) {
            line.replace(mainPos, 0, "int ");
        }

        // Add the translated line to the vector
        translatedCode.push_back(line);
    }

    // Close the input script file
    zincFile.close();

    // Output the translated C++ code to a file
    std::ofstream outputFile("zinc_to.cpp");
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to create output file." << std::endl;
        return 1;
    }

    for (const std::string& translatedLine : translatedCode) {
        outputFile << translatedLine << std::endl;
    }

    // Close the output file
    outputFile.close();

    // Compile the saved C++ code
    int compileResult = system("g++ -o zinc_output zinc_to.cpp");

    if (compileResult == 0) {
        // Compilation was successful
        std::cout << "Compilation successful. Running the program..." << std::endl;
        system("./program"); // Run the compiled program
    } else {
        // Compilation failed
        std::cerr << "Compilation failed. Please check the code for errors." << std::endl;
    }

    return 0;
}
