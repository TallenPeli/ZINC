#include <iostream>
#include <string>
#include <type_traits>

//Standard Zinc functions from zincstd
template <typename T>
void print(const T& input){std::cout << input;}
void print(std::string input){std::cout << input;}
template <typename T>
void println(const T& input = T()) { if constexpr (!std::is_void_v<T>) std::cout << input << std::endl; }
void println(){std::cout << std::endl;}
void newline(){std::cout << std::endl;}
std::string input(std::string prompt){std::string Input;std::cout << prompt;std::cin >> Input;return Input;}
std::string getline(std::string prompt){std::string Input;std::cout << prompt;getline(std::cin, Input);return(Input);}


int main(){
    std::cout << "Hello" << std::endl;
}
