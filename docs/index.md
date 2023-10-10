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

Loops allow you to repeat a block of code multiple times. In Zinc, you can use the `loop` function to create loops. Here's an example:

```rust
main() {
    loop(5, i) {
        println("Hello, Zinc!");
    }
}
```

In this code, we are using the `loop` function to print "Hello, Zinc!" five times. The `i` inside the loop represents an integer that increments with each iteration. It lets you control how many times the loop runs and access the current iteration's value. This is especially useful for nested loops when you want to use the value of the outer loop in the inner loop.

Here's another example that demonstrates nested loops and a custom function:

```rust
using zincstd;

fn hello() {
    println("hello");
}

main() {
    loop(100, i) {
        loop(i, j) {
            print(" ");
        }
        hello();
    }
}
```

In this code, we define a custom function called `hello()` that prints the line "hello". In the `main()` function, there's a loop that runs 100 times with the integer variable `i`. Inside that loop, we have another loop that runs the number of times specified by `i`, and it introduces its own variable `j`. This structure creates a pattern of spaces followed by "hello" that repeats. The output looks like:

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

This code showcases how loops and nested loops can be used to create more complex patterns and behaviors in Zinc.

## Input

You can get input from the user using the `input` function. Here's how it works:

```rust
main() {
    string name = input("Enter your name: ");
    println("Hello, " + name + "!");
}
```

The `input` function prompts the user to enter their name and stores the input in the `name` variable.
