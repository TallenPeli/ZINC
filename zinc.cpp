#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

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

    string line;
    while (getline(zincFile, line)) {
        cout << line << endl;
    }

    zincFile.close();

    return 0;
