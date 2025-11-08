# Simple Shell

This project is a simple UNIX command interpreter written in C.  
It replicates basic behavior of a shell, including executing commands, handling arguments, forking processes, and waiting for child processes.

## Features
- Displays a prompt and waits for user input
- Executes simple commands using `execvp`
- Handles multiple arguments
- Uses `fork` to create child processes
- Waits for executed commands to finish
- Built-in command: `exit`
- Follows Betty coding style

## Files
- `main.c` – Entry point, reads input and manages shell loop
- `parse_line.c` – Splits input into arguments
- `execute.c` – Handles execution of commands
- `shell.h` – Header file with function prototypes
- `man_1_simple_shell` – Manual page for the program
- `AUTHORS` – List of project contributors

## Compilation
Use the following command:

