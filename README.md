# C-check-permissions
A C code to run shell commands to check file permissions

Generates the following commands to run: 
```bash
if [ -f "file.txt" ]; then echo file exists; else echo file does not exist; fi 
if [ -r "file.txt" ]; then echo can read; else echo cannot read; fi 
if [ -w "file.txt" ]; then echo can write; else echo cannot write; fi
```
And executes them using the system() method.

The original purpose is to check the setuid bit of files.
 
