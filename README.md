# Simple Shell

This project is an implementation of a basic UNIX command-line interpreter written in C.

## Features
- Display a prompt and wait for user input.
- Execute commands in PATH.
- Handle command arguments.
- Works in interactive and non-interactive modes.
- Builtin commands: `exit`, `env`.

## Compilation
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage
### Interactive mode:
```
./hsh
$ ls
$ exit
```

### Non-interactive:
```
echo "ls" | ./hsh
```

## Files
- main.c
- execute.c
- read_line.c
- tokenize.c
- builtins.c
- shell.h

## Authors
See AUTHORS file.

