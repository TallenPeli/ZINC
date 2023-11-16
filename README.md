# ZINC

[![GitHub](https://img.shields.io/github/license/Ananto30/cap-em)](/LICENSE)

Zero-cost INtegrated C++
--------------------------------------------------------

ZINC is a programming language written in C++ that aims to provide the same (if not more) functionality, but is easier to learn and has a faster development cycle.

ZINC is for Linux/UNIX systems. (Windows port is planned, although it works well in WSL)

C++ libraries are compatable with ZINC.

--------------------------------------------------------

# Install

## Compile from source

### Fedora/RHEL

Insall dependnecies
```shell
sudo dnf install make g++ gcc
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
make
```

### Ubuntu/Debian

Install dependnecies
```shell
sudo apt-get install make g++ gcc
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
make
```

### Arch/Manjaro

Insall dependnecies
```shell
sudo pacman -S make gcc
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
make
```

### Windows
[Install the WSL](https://learn.microsoft.com/en-us/windows/wsl/install) and follow the instructions for your distribution.


## Usage
[Documentation](/docs/index.md)

(The default ZINC file format is .zc but is not required.)

```shell
[zinc executable] {zinc script} [flags]
```

Certainly! Here's the documentation for the `-k`, `-v`, and optimization flags as per your outline:

### Flags

```
-k or --keep-translation (Keeps the generated C++ file even after compilation)
```

```
-v or --verbose (Verbose output - tells you exactly what's going on)
```

```
-O0, -O1, -O2, -O3, -Os, -Ofast (Control the level of optimization during compilation)
```

```
-asm or --assembly (Generate assembly code instead of an executable)
```

### Example Usage
```shell
./zinc /home/$USER/Documents/ZINC/main.zc -k -v -O2
```

## Example Code
```c++
using zincstd;

main(){
    let zinc_version = 0.0.2;
    string name = input("Enter name : ");
    loop(2, i){
        print("HI ");
        println(name);
    }
    rest(1s);
    print("Zinc Version : ");
    println(zinc_version);
    return 0;
}
```
