# Minishell1
*Unix System Programming | Epitech | Tek1*

##### Purpose of the project :
- [x] Create a UNIX command interpreter
- [x] Create cd, setenv, unsetenv, env and exit commands

## Build
```
$ make
```

## Usage
Execute `./mysh` to run the shell.  
You can directely execute a command with:
```
echo [your_command] | ./mysh
```

## Cd command
### Usage
```
$ cd [directory]
```
### Example
```
$ cd Documents
$ pwd
/home/louis/Documents
$ cd ~
$ pwd
/home/louis
$ cd -
$ pwd
/home/louis/Documents
```

## Setenv command
### Usage
```
$ setenv [name] [value]
```
### Example
```
$ env
PATH=/usr/bin
$ setenv TEST value
$ env
PATH=/usr/bin
TEST=value
```
## Unsetenv command
### Usage
```
$ unsetenv [name]
```
### Example
```
$ env
PATH=/usr/bin
TEST=value
$ unsetenv TEST
$ env
PATH=/usr/bin
```

## Exit command
### Usage
```
$ exit [error_value]
```
### Example
```
$ exit 22
$ echo $?
22
```
