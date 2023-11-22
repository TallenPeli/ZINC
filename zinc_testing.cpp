#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include <cstdlib>
#include <functional>
#include <sys/ioctl.h>
#include <cstring>

using namespace std;

class _console{
    public:
        void clear(){
            system("clear");
        }

        void out(std::string input){
            std::cout << input;
        }

        char* listen(){
            char* heard = new char[256];
            std::cin >> heard;
            return heard;
        }

        void writeLine(const char* input = new char[512]){
            out(input);
            out("\n");
        }

        char* getLine() {
            char* line = new char[256];  // Allocate memory for the line
            std::cin.getline(line, 256); // Read user input into the buffer
            return line;
        }

        void runCommand(const char* input) {
            if (input != nullptr && strlen(input) > 0) {
                system(input);
            }
            delete[] input; // Deallocate the memory
        }
};

int main(){
    // this is a test comment hehehe
    _console console;
    console.out(console.getLine());
    console.clear();
    console.writeLine("Hello, world!");
    console.writeLine("This is a test");
    console.runCommand(console.getLine());
    console.clear();
    return 69;
}
