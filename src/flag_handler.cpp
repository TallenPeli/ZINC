#include <iostream>

using namespace std;

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

// Variable declaration

bool keepTranslation;
bool verboseOutput;
bool compileToAsssembly;

string optimizationList[6] = {"-O0", "-O1", "-O2", "-O3", "-Os", "-Ofast"};

int optimization = 0;

void flagHandler(int FlagAmt, char **flag){
    string file = flag[1];
    if (file.substr(0, 2) == "./") {
        file = file.substr(2);
    }

    for (int i = 2; i < FlagAmt; i++) {
        string arg = flag[i];
        if (arg == "-k" || arg == "--keep-translation") {
            keepTranslation = true;
        }else if(arg == "-v" || arg == "--verbose") {
            verboseOutput = true;
        }else if(arg == "-O0"){
            optimization = 0;
        }else if(arg == "-O1"){
            optimization = 1;
        }else if(arg == "-O2"){
            optimization = 2;
        }else if(arg == "-O3"){
            optimization = 3;
        }else if(arg == "-Os"){
            optimization = 4;
        }else if(arg == "-Ofast"){
            optimization = 5;
        }else if(arg == "-asm" || arg == "--assembly"){
            compileToAsssembly = true;
        }
    }

    if(verboseOutput){
        cout << "| Verbose output: [" << GREEN << "True" << RESET << "]" << endl;
        cout << "| Assembly Output: [" << (compileToAsssembly ? GREEN : RED) << (compileToAsssembly ? "True" : "False") << RESET << "]" << endl;
        cout << "| Keep translation: [" << (keepTranslation ? GREEN : RED) << (keepTranslation ? "True" : "False") << RESET << "]" << endl;
        cout << "| Optimization : [" << MAGENTA << optimizationList[optimization] << RESET << "]" << endl;
    }
}