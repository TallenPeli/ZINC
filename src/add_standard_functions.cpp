#include <iostream>

using namespace std;

// Add functions at the top of the translated C++ file
string addFunctions(){
    string code;
    code.append("#include <iostream>\n#include <string>\n#include <type_traits>\n#include <thread>\n#include <chrono>\n");
    code.append("\n//Standard Zinc functions from zincstd\n");
    code.append("using namespace std::chrono_literals;\n");
    code.append("\nvoid newline(){\n    std::cout << std::endl;\n}\n");
    code.append("\nstd::string input(std::string prompt){\n    std::string Input;\n    std::cout << prompt;\n    std::cin >> Input;\n    return Input;\n}\n");
    code.append("\nstd::string getline(std::string prompt){\n    std::string Input;\n    std::cout << prompt;\n    getline(std::cin, Input);\n    return(Input);\n}\n");
    code.append("\ntemplate <typename Rep, typename Period>\nvoid rest(const std::chrono::duration<Rep, Period>& duration){\n    std::this_thread::sleep_for(duration);\n}\n");
    code.append("");

    return code;
}