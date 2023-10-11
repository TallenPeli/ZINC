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

### Flags
```shell
-k or --keep-translation (Keeps the generated c++ file even after compilation)
```
```shell
-v or --verbose (Verbose output - tells you exactly what's going on)
```

### Example Usage
```shell
./zinc /home/$USER/Documents/ZINC/main.zc -k -v
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
