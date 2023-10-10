# Getting Started with Zinc

Welcome to the Zinc programming language! This documentation will guide you through the basics of writing and running Zinc programs.

## Installation

Before you can start using Zinc, you'll need to install the Zinc interpreter. You can download the zinc translator from [Zinc's official website](https://github.com/Talleeenos69/ZINC/blob/main/) and follow the installation instructions for your operating system.

## Hello, Zinc!

Let's start with a simple "Hello, World!" example. Create a new file with the ".zc" extension, e.g., `hello.zc`, and add the following code:

```rust
main() {
    println("Hello, Zinc!");
}
```

Save the file and open your terminal. Navigate to the directory where you saved `hello.zc` and run the following command to execute the Zinc program:

```shell
zinc hello.zc
```

You should see the following output:

```shell
Hello, Zinc!
```

Congratulations! You've just run your first Zinc program.

## Variables

Zinc supports variables for storing and manipulating data. Here's an example of declaring and using variables:

```rust
main() {
    string name "Tallen";
    int age = 27;
    bool isHuman = false;
    const int birthday = 26;
    double testDouble = 19.99;
    char letter = 'a';
    
    println("Name: " + name);
    println("Age: " + age);
}
```

In this example, we've defined two variables, `name` and `age`, and printed their values.

## Functions

Functions allow you to organize your code into reusable blocks. Here's how you can define and call a function in Zinc:

```rust
// Define a function
fn greet(name) {
    println("Hello, " + name + "!");
}

main() {
    // Call the function
    greet("Bob");
    greet("Alice");
}
```

This code defines a `greet` function that takes a `name` parameter and prints a greeting.

## Loops

You can use loops to repeat code multiple times. Here's an example of a loop in Zinc:

```rust
main() {
    loop(5, i) {
        println("Hello, Zinc!");
    }
}
```

In this code, we use the `loop` function to print "Hello, Zinc!" five times. The "i" is the integer that is being used to loop. This allows for nested loops to use the value of the previous loop for more complex functions.

```rust
using zincstd;

fn hello(){
    println("hello");
}

main(){
    loop(100,i){
        loop(i, j){
            print(" ");
        }
        hello();
    }
}
```
This code defines a "hello()" function which prints the line "hello". In the main() function, there is a loop that runs 100 times with the integer value "i". The code then defines a loop that runs the amount of times as the value "i", then it defines it's own variable "j". The code gives this output:

```shell
hello
 hello
  hello
   hello
    hello
     hello
      hello
       hello
        hello
         hello
          hello
           hello
            hello
             hello
              hello
               hello
                hello...
```


## Input

You can get input from the user using the `input` function. Here's how it works:

```rust
main() {
    string name = input("Enter your name: ");
    println("Hello, " + name + "!");
}
```

The `input` function prompts the user to enter their name and stores the input in the `name` variable.
