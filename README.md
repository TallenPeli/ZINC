# ZINC
Zero-cost INtegrated C++
--------------------------------------------------------

ZINC is a programming language written in C++ and C and aims to provide the same (if not more) functionality of these languages, but is easier to understand and a lot quicker to develop.

ZINC is for Linux/UNIX systems, but a windows port is planned. ZINC uses the ncurses library, and makes it a lot easier to use. 

C or C++ libraries are compatable with ZINC, however can only be programmed using their native syntax.

--------------------------------------------------------
Compile from source

Fedora/redhat

Insall dependnecies
```shell
sudo dnf install g++ ncurses-devel
```

ubuntu/debian

Insall dependnecies
```shell
sudo apt install g++ libncurses5-dev
```

Arch/Manjaro

Insall dependnecies
```shell
sudo pacman -Syu g++ lib32-ncurses
```

Example Code
```c++
using zincstd;

main(){
    string name = input("Enter name : ");
    loop(100){
        print("HI ");
        println(name);
    }
}
```
