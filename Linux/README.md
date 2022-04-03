
# StudyMaterial Linux
* Printf is defined in standard C library 
* memory mapping is stored in .out file
* .out
    * .bss
    * .data
    * .text, etc.
* Path types
    * Absolute : From root 
    * Reelative : from current Directory

* GNU (Not Unix) : Initiated by __Richard M stallman__
* Linux (man ls) : written by __Richard M stallman and David MacKenzie__ 
* ls cpu : gives details about CPU cores and Threads usage per core
* When Function is called Stack space is created


# OS (operating system)
* A mother program to schedule and run other programs
* OS contains a core (Mother Program) called Kernal

# SMP (Symetric Multi Processing) 
* EG: Snapdragon chip

# AMP (ASymetric Multi Processing)
* EG: GPU (Graphical Processing Unit)


# Dual Mode have 2 modes (Differentiated by Mode Bit)
* User Mode
    * By default it is 3 GB
* Kernal Mode (Super Mode/Admin Mode/Root mode)
    * By default it is 1 GB


# Kernal
* It is a program that links CPU & Memory

## Kernal Types 
* Monolithic Kernal
    * User and Kernal services implemented under same address space

* Micro Kernal (For Embedded boards)
    * Minimum no.of functions that are required to implement OS

* Modular Kernal
    * Some part of system core will get allocated in independent files called Modules
    * ___ Dynamic modules ___ : Loaded /Unloaded anytime
    * ___ Static modules ___ : Loaded /Unloaded with system Boot

# Interrupt (no blocking calls)
* It is an event which stops / ends execution of current process then it jumps to interrupt handler

# System Call
* This is basically a method that allows a program to request service from the kernal
* System calls are known by their numbers not addresses
* return value convectoins of system calls can be found in header file <sys/syscalls.h>

## File Descriptor (fd)
* File descriptor describe the type of file
* FD will create file descriptor table maintained by kernel
* File descriptor used by any process
    * fd = 0 (stdin)(read)
    * fd = 1 (stdout)(write)
    * fd = 2 (stderr)
    * fd < 0 (returns in case error)

* nbytes == maxlen (read all content at one go)
* nbytes < maxlen (read content until provided maxlen then consider other contents as NULL)
* nbytes == 0 (Indicates End of file/ file empty)

## File system calls
* open(const *pathname, int flags);
* open(const *pathname, int flags, mode_t mode);
* This system call opens file specified by pathname if the specified sile doesn't exists it may operationally (if O_CREATE is apecified in flags)

## Fork System Call
* fork() is a system call which is used to create child process
* Duplicate resources from parent to child
* __In parent process fork() returns non zero value(mostly child ID)__
* __In chile process fork() returns zero__
* It will execute lines after fork()
* Parent and Child will run concurrently according to architecture
* USE getpid() function for child USE getppid() function for parent process

|perror|printf|
|---|---|
| It is a Library Call | It is executab;e program or Shell commands |
|prints a system error message|prints only our message|
|writes to stderror|writes to stdout|
|Non buffered (prints immediatly)|Buffered (prints when hits\n)|

# Process
* it is a program under execution
* Program is passive entity and process is an active entity
* Every process has its own independence stack
* Kernel maintains process list table in form of double linked list 
* Each process has a unique ID(pid)

* Preemption (if the CPU resource is forcefully taken then it is Preemption)

* process table is maintained by Kernal


# Context Switch
* Switching CPU from one process to another process
* Context Saving
    * Copy Data from CPU to SAVE AREA
* Context Loaading
    * Copy Data from SAVE AREA
* Context Switching
    * Combination of context saving and context loading  
    * Occurs on interrupts or system call or preemption 

# Process Commands in terminal
* To start process in Background use & symbol in commands (eg: cat filename.txt __&__)
* To check different process that are running in background use (__jobs__)
* To switch process from background to foreground use (__fg__)
* To terminate a process we use kill -9 <PID>
    * Here -9 is SUREKILL
* To get process id (PID) and to get parent Process id (PPID) 

## Orphan Process
* Orphan Process is one whose parent is Killed/Terminated before itself 
* Orphan Process  are adopted By init process

## __init__ process is considered as the  Origin of Linux Process Hierarchy
* __pstree__ command will give process ID tree
* __top__ command will give CPU and Memory utilisation
* __pgrep__ command is used to search process (eg: pgrap ./a.out)
* kill is used to kill the process

## Zombie Process
*  Process which completed the execution but still have entry in Process Table

## Deamon Process
* Process that runs in the backgrounds

## waitpid()
* Wait Until child is terminated
* If process is completed then remove the entity in the process table (so that if memory is cleared for other processes)
* collects exit status in a variable
*  pid_t waitpid(pid_t pid, int *wstatus, int options);
* eg : waitpid(-1,&status,0);
* here -1 is for current child process and 0 is no options

## WEXITSTATUS
* The status variable has some extra informantion along with exit status 
* to only get exit status we use WEXITSTATUS(status)
