# Lox Interpreter

A C++ implementation of the Lox programming language interpreter, following the "Crafting Interpreters" book by Robert Nystrom.

## Overview

This project implements a tree-walking interpreter for the Lox programming language. Lox is a dynamically typed, object-oriented scripting language with C-style syntax.

### Features

- **Lexical Analysis**: Complete tokenization of Lox source code
- **Syntax Analysis**: Recursive descent parser
- **Runtime Evaluation**: Tree-walking interpreter
- **Error Handling**: Comprehensive error reporting with line numbers
- **Data Types**: Numbers, strings, booleans, and nil
- **Variables**: Variable declaration and assignment
- **Control Flow**: If statements, while loops, and for loops
- **Functions**: First-class functions with closures
- **Classes**: Object-oriented programming with inheritance

## Language Features

### Data Types

```lox
// Numbers
var pi = 3.14159;
var answer = 42;

// Strings
var greeting = "Hello, World!";

// Booleans
var isAwesome = true;

// Nil
var nothing = nil;
```

### Variables and Scoping

```lox
var global = "I'm global";

{
    var local = "I'm local";
    print local;
}
```

### Control Flow

```lox
// If statements
if (condition) {
    print "It's true!";
} else {
    print "It's false!";
}

// While loops
var i = 0;
while (i < 10) {
    print i;
    i = i + 1;
}

// For loops
for (var j = 0; j < 5; j = j + 1) {
    print j;
}
```

### Functions

```lox
fun greet(name) {
    print "Hello, " + name + "!";
}

greet("Alice");

// Functions are first-class
fun makeCounter() {
    var count = 0;
    fun counter() {
        count = count + 1;
        return count;
    }
    return counter;
}

var counter = makeCounter();
print counter(); // 1
print counter(); // 2
```

### Classes and Inheritance

```lox
class Animal {
    init(name) {
        this.name = name;
    }

    speak() {
        print this.name + " makes a sound";
    }
}

class Dog < Animal {
    speak() {
        print this.name + " barks";
    }
}

var dog = Dog("Rex");
dog.speak(); // Rex barks
```

## Getting Started

### Prerequisites

- C++23 compatible compiler (GCC 14+, Clang 15+, or MSVC 2022+)
- CMake 3.13 or higher
- Make or MinGW32-make (depending on your platform)

### Building

#### Linux/macOS

```bash
git clone https://github.com/yourusername/lox-interpreter.git
cd lox-interpreter
chmod +x your_program.sh
./your_program.sh tokenize examples/hello.lox
```

#### Windows (MinGW/MSYS2)

```bash
git clone https://github.com/yourusername/lox-interpreter.git
cd lox-interpreter
./your_program.sh tokenize examples/hello.lox
```

#### Manual Build

```bash
# Create build directory
mkdir build && cd build

# Configure with CMake
cmake -G "MinGW Makefiles" ..  # On Windows with MinGW
# or
cmake ..                       # On Linux/macOS

# Build
cmake --build .

# Run
./interpreter tokenize test.lox
```

### Usage

The interpreter supports different modes of operation:

#### Tokenization

```bash
./your_program.sh tokenize source.lox
```

#### Parse Tree (if implemented)

```bash
./your_program.sh parse source.lox
```

#### Evaluation (if implemented)

```bash
./your_program.sh evaluate source.lox
```

#### Running a Lox file

```bash
./your_program.sh run source.lox
```

## Project Structure

```
lox_interpreter/
├── src/
│   ├── main.cpp           # Entry point
│   ├── Scanner.hpp        # Lexical analyzer
│   ├── Scanner.cpp
│   ├── TokenHelper.hpp    # Token utilities
│   ├── TokenHelper.cpp
│   ├── Parser.hpp         # Syntax analyzer (if implemented)
│   ├── Parser.cpp
│   ├── Interpreter.hpp    # Runtime evaluator (if implemented)
│   └── Interpreter.cpp
├── examples/              # Example Lox programs
├── tests/                 # Test files
├── CMakeLists.txt        # Build configuration
├── your_program.sh       # Build and run script
└── README.md
```

## Implementation Progress

- [x] Lexical Analysis (Scanner)
- [x] Token representation
- [ ] Syntax Analysis (Parser)
- [ ] Abstract Syntax Tree
- [ ] Runtime Evaluation
- [ ] Error Recovery
- [ ] Standard Library Functions

## Examples

### Hello World

```lox
print "Hello, World!";
```

### Fibonacci

```lox
fun fibonacci(n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

for (var i = 0; i < 10; i = i + 1) {
    print fibonacci(i);
}
```

### Calculator

```lox
fun add(a, b) { return a + b; }
fun multiply(a, b) { return a * b; }

var result = multiply(add(5, 3), 2);
print result; // 16
```

## Testing

Create test files in the `tests/` directory and run:

```bash
./your_program.sh tokenize tests/test_file.lox
```

## Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## Resources

- [Crafting Interpreters](https://craftinginterpreters.com/) by Robert Nystrom
- [Lox Language Grammar](https://craftinginterpreters.com/appendix-i.html)
- [CodeCrafters](https://codecrafters.io/) - Build your own interpreter challenge

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Robert Nystrom for the excellent "Crafting Interpreters" book
- CodeCrafters for the hands-on learning experience
- The open-source community for inspiration and support
