# cpipe - color pipe

cpipe is a program that colorize the input from stdin to stout (like lolcat). 
cpipe is written fully in c and can be used as a library.

There are two color-modes available (more coming):

* Rainbow: colors like a rainbow
* Linebow: color every line in a other color
* Columnbow: color every column in a other color
* Brainfuck: insane colorizing

##usage

Show help page:
```
cpipe --help
```
Show available colors:
```
cpipe --test-colors
```
Show available modes (default mode is 'rainbow'):
```
cpipe --test-modes
```
Some examples:
```
ls -la | cpipe --brainfuck
ls -la | cpipe --columnbow
dmesg  | cpipe --linebow
```
