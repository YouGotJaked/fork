# Lab 1 - Jake Day

This project is designed to help the user gain a better understanding of the creation of processes with Unix-like operating systems by using the fork() system call. All programs are written in C.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

To compile and run these programs, your machine must be running a Unix-based operating system such as Linux or macOS.

### Compiling with GCC

To compile a .c file, open up Terminal and navigate to the project directory:

```
cd /home/username/yourdirectory
```

Once in the correct directory, type in the following command with "program" being the name of the file being compiled:
```
gcc -o program program.c
```

To run your program, execute the following command:

```
./program
```

## File Descriptions

### fork_1.c

This program acts as a simple shell. It takes an input string from stdin and attempts to launch a program using execve(). If the string "exit" is entered, the shell terminates. Users should test this program by entering one of the other files' executables (e.g. "./fork_2", "./fork_3", "./hello_world", etc.)

### fork_2.c

This program creates exactly eight child processes (not including the initial program itself). A single procress is not allowed to create more than two processes. Each child and its parent is printed to stdout.

### fork_3.c

This program creates exactly twelve child processes. No single process which creates children is allowed to create less than two child processes or more than three. Each child and its parent is printed to stdout.

### fork_4.c

This program creates exactly seventeen child processes. No single process which creates children is allowed to create less than two child processes or more than three. Each child and its parent is printed to stdout.

### hello_world.c

This program simply prints out "Hello world." It can be used as a test program inside the shell of fork_1.
