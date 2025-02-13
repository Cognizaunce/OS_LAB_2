# OS_LAB_2
crn: 74025
group 17
contributors: rivka sagi (100780926), rhea mathias(100825543), iqra zahid(100824901), julian olano medina (100855732)

## overview:
the purpose of this to use "myshell" which is a unix/linux based shell command-line application that can be used to execute commands involving features such as changing a directory, clearing the screen, listing the contents of the directory and so on.To do so, two main files were created to use the internal shell command and launch the external program on the terminal called utility.c and myshell.c respectively. A makefile was created to run the files of the program with ease. The shell is also able to use batch mode which executes commands from a file.

## key concepts in linux/unix:
i/o redirection: redirects input and output to/from a file or process using "<" for input redirection and ">" for output redirection. In order to appens an output, ">>" is used.

program environment: affects the behavior of processes through a collection of variables which have specific functions such as holding the current working dorectory or defining the path to certain files.

background program execution: functions such as fork() allow for background programs to function where different processes can run in the background through the child process while the parent process continues working in the command line (if the parent does not wait for the child)


## installation instructions:
step 1: make sure you are using a linux based system to run this lab on such as ubuntu.

step 2: clone the files into a directory of your choice that will be used to run the makefile 

step 3: open the command line terminal and navigate to the directory containing the files using the cd command (eg cd directory_name)

step 4: once in the directory, type the "make" command in the command line to run the makefile. Ths will create an executable file called myshell.exe. The file will not run if make and gcc are not already downloaded in the system, to download them type "sudo apt gcc" or "sudo apt make". 

step 5: run the exectutable file using the command "./myshell" in the command line. once the file is successfully run, you will be presented with a prompt.

step 6: type any internal command mentioned in features below or run program in batch mode.


## features:
running the myshell file will give the user the following features:

cd directory: change the current directory to the directory of choice. if the directory argument is not present, then the current directory will be displayed. If the directory stated does not exist within the system, a respective error message will pop up

clr: clears all contents on the command line screen

dir directory: lists the content in te directory specified

environ: lists all environment strings in the current directory

echo comment: prints the given comment in the display followed by a new line

help: displays the user manual

pause: pauses the shell operations until "enter" is pressed

quit: quits the current shell

if the command given is not one of the internal commands above, the shell is forked to create a child process to run the command before returning back for more user input.

batch processing is also allowed using the command "myshell batchfile"


## file functionalities:

myshell.c:
this c file contains the main() function and is the file that deals with user input and output. 

utility.c:
this c file deals with the main logic used in the myshell.c file to interpret and get outputs for the different internal commands.

myshell.h:
this is the header file used by both myshell.c and utility.c to inititate the different parameters used by both files

makefile:
the makefile automates the compilation process of the c files by using gcc internally.


## usage examples:

myshell> cd /home/user/desktop
myshell> dir
example1.txt example2.txt
myshell> echo "hello world"
hello world



