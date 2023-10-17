# ZINC
Zero-cost INtegrated C++
--------------------------------------------------------

ZINC is a programming language written in C++ and C and aims to provide the same (if not more) functionality of these languages, but is easier to understand and a lot quicker to develop.

ZINC is for Linux/UNIX systems, but a windows port is planned. ZINC uses the ncurses library, and makes it a lot easier to use. 

C or C++ libraries are compatable with ZINC, however can only be programmed using their native syntax.

--------------------------------------------------------
## Compile from source

### Fedora/redhat

Insall dependnecies
```shell
sudo dnf install g++ ncurses-devel
```

clone repository
```shell
git clone https://github.com/Talleeenos69/ZINC/
```

cd into ZINC
```shell
cd ./ZINC
```

Build
```shell
g++ zinc.cpp -o zinc -lncurses
```

### ubuntu/debian

Insall dependnecies
```shell
sudo apt install g++ libncurses5-dev
```
clone repository
```shell
git clone https://github.com/Talleeenos69/ZINC/
```
cd into ZINC
```shell
cd ./ZINC
```

Build
```shell
g++ zinc.cpp -o zinc -lncurses
```

### Arch/Manjaro

Insall dependnecies
```shell
sudo pacman -Syu g++ lib32-ncurses
```
clone repository
```shell
git clone https://github.com/Talleeenos69/ZINC/
```
cd into ZINC
```shell
cd ./ZINC
```

Build
```shell
g++ zinc.cpp -o zinc -lncurses
```

### Windows
[Install the WSL](https://learn.microsoft.com/en-us/windows/wsl/install) and follow the instructions for your distribution.


## Usage
(The default ZINC file format is .zc but is not required.)

```shell
[zinc executable] {zinc script} [flags]
```

Certainly! Here's the documentation for the `-k`, `-v`, and optimization flags as per your outline:

### Flags

#### `-k` or `--keep-translation`
Description: This flag allows you to keep the generated C++ file even after compilation. By default, the generated C++ file is removed after compilation.

Usage:
```shell
-k
--keep-translation
```

#### `-v` or `--verbose`
Description: This flag enables verbose output, providing detailed information about what's happening during the execution of your program. Useful for debugging and gaining insight into the compilation process.

Usage:
```shell
-v
--verbose
```

#### `-O0`, `-O1`, `-O2`, `-O3`, `-Os`, `-Ofast`
Description: These flags control the level of optimization applied during compilation. The higher the optimization level, the more aggressive the compiler will be in optimizing your code. Use `-O0` for no optimization, and `-Ofast` for the highest level of optimization.

Usage:
```shell
-O0
-O1
-O2
-O3
-Os
-Ofast
```

#### `-asm` or `--assembly`
Description: This flag instructs the compiler to generate assembly code rather than an executable. It's used in conjunction with other flags to control the compilation process.
  
Usage:
```shell
-asm
--assembly
```

The `-k` and `-v` flags are used independently, while the optimization flags (`-O0`, `-O1`, `-O2`, `-O3`, `-Os`, `-Ofast`) determine the level of optimization applied to the compilation process. The `-asm` flag is placed after the `-k` and `-v` flags, as specified in your request.

### Example Usage
```shell
./zinc /home/$USER/Documents/ZINC/main.zc -k -v -O2
```

## Example Code
```c++
using zincstd;

main(){
    string name = input("Enter name : ");
    loop(100, i){
        print("HI ");
        println(name);
    }
}
```
