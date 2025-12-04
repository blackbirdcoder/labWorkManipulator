# Robot manipulator 🦾

![Demo](demo/move.gif)

This project is a simple example of a robotic manipulator implemented using the raylib library.
It was created as a basic assignment for my variant.

## ⚙️ How to Clone and Build (Linux 🐧)

### 1. Clone the repository

```bash
git clone <your-repo-url>
cd <your-repo-folder>
```

### 2. Compile using clang++

```
clang++ src/*.cpp -std=c++17 -g -o main \
    -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

### 3. Run the program

```
./main
```
