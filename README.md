# minishell

## Overview
This project uses C to construct a simple shell; it is based on the Ecole 42 minishell project.

### Contributors
- Y. Kawakita (https://github.com/yuuuuki15)
- M. Evonuk (https://github.com/mevonuk)

## Tools
- Coding language: C
- Function Library: libft (library of C functions)

## Main Features
- displays prompt when waiting for a new command
- has a working history
- searches and launches correct executable based on PATH variable or using a relative or absolte path
- uses at most one globabl variable to indicate a recieved signal
- handles single quotes (prevents shell from interpretng metacharacters in quoted sequence)
- handles double quotes (prevents shell from interpreting metacharacters in quoted sequence, except dollar sign)
- implements following redirections: < redirects input; > redirects output; << is given a delimiter and then read until reaching delimiter; and >> redirects output in append mode
- implements pipes
- handles environment variables
- handles $? to expand exit status of most recently executed foreround pipe
- handles ctrl-C, ctrl-D, and ctrl-\ to behave as in bash

### built-in commands:
- echo with option -n
- cd with relative or absolute path
- pwd with no options
- export with no options
- unset with no options
- env with no options of arguments
- exit with no options

### Bonus
- implements && and || with parenthesis for priorities

## Installation and Setup
- Clone the repository
- Run Makefile
