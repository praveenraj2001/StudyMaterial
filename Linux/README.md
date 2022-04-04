# By Manju and Praveen
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

# Special Purpose Registers
* Program counter
* PSW/Flags
* Stack Pointer
* Frame / Base pointer

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
* This system call opens file specified by pathname if the specified file doesn't exists it may operationally (if O_CREATE is specified in flags)

## Fork System Call
* fork() is a system call which is used to create child process
* Duplicate resources from parent to child
* __In parent process fork() returns non zero value(mostly child ID)__
* __In child process fork() returns zero__
* It will execute lines after fork()
* Parent and Child will run concurrently according to architecture
* USE getpid() function to get current process ID USE getppid() function for parent process ID

|perror|printf|
|---|---|
| It is a Library Call | It is executable program or Shell commands |
|prints a system error message|prints only our message|
|writes to stderror|writes to stdout|
|Non buffered (prints immediatly)|Buffered (prints when hits\n)|

# Process
* it is a program under execution
* Program is passive entity and process is an active entity
* Every process has its own independence stack
* Kernel maintains process list table in form of double linked list 
* Each process has a unique ID(pid)
![img1](https://user-images.githubusercontent.com/64356812/161424339-62f577b3-339b-4d7f-b6c1-a75c56f594c2.png)

* Preemption (Whenever the time is completed the CPU might stop the process forcefully This time is known as quantum or time slice)

* process table is maintained by Kernal


# Context Switch
* Switching CPU from one process to another process
* Context Saving
    * Copy Data from CPU to SAVE AREA
* Context Loaading
    * Copy Data from SAVE AREA to CPU
* Context Switching
    * Combination of context saving and context loading  
    * Occurs on interrupts or system call or preemption 

# Process Commands in terminal
* To start process in Background, use "&" symbol in commands (eg: cat filename.txt __&__)
* To check different process that are running in background use (__jobs__)
* To switch process from background to foreground use (__fg__)
* To terminate a process we use kill -9 <P.I.D>
    * Here -9 is SUREKILL
* To get process id (PID) and to get parent Process id (PPID) 

## Orphan Process
* Orphan Process is one whose parent is Killed/Terminated before itself 
* Orphan Process  are adopted By init process

## __init__ process is considered as the  Origin of Linux Process Hierarchy
* __pstree__ command will give process ID tree
* __top__ command will give CPU and Memory utilisation
* __pgrep__ command is used to search process (eg: pgrep a.out)
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

## exec
* If we want to execute a different executable file then we use exec, #include <unistd.h>
* all commands (execl,execlp,execle,execv,execvp,execvpe)
* syntax : execl(char *pathname, const char *arg);
    * execl("/usr/bin/ls", "ls",args....,NULL);
* syntax : execlp(char *filename, const char *arg);
    * execlp("ls", "ls",args....,NULL);
* syntax : execvp(char *filename, const char *arg[]);
    * char* arggs[] = "cp file1.txt file2.txt" 
    * execvp("cp", arggs);

## Command Line argunemts
* int main(int args,char* argv[]){}

# ABI (Application Binary Interface)
* Identify System call number
* Save user mode context
* store system call number in a register
* store parameter in other General Purpose Register
* call the trap instruction

# Signals 
* It always Operates at process level 
* Signal communicates between application at user level
* used for communication of abnormal termination
* __Signals are considered as software interrupts but there is no vector table__
* Signals between process
    * SENDER (sends signals from one process to another)
    * TARGET (will set corresponding bit based on senders's signal bit)
* target will look-up in the signal handler table for handler address for each of the signal handler

* Process Descriptor (PD) / Process Control Block (PCB) has signal related fields
* Most of the  default signal handlers will cause abnormal termination

* __to get all the signals available in the system use (kill -l) Command__

|Signal Name|Description|
|---|---|
|SIGINT|User sends Interrupt (ctrl + c)|
|SIGQUIT|User sends QUIT signal(ctrl + \ )|
|SIGTSTP|User sends SUSPEND signal(ctrl + z)|
|SIGTERM|User sends TERMINATION signal (kill <p.i.d>)|
|SIGCHLD|Child Process stopped|
|SIGFPE|Floating Point Exception|
|SIGCONT|resum process|
|SIGSEGV|null pointer exception(segmentation error)|

* Custom handlers can override the default handler

# Non Maskable Signals
* Have No custom Handlers
* SIGKILL, SIGSTOP

## kill command
* syntax : kill <signal_number> <PID(process ID)>
    * eg: kill -9 183, here -9 is SIGKILL and 183 is process id
* for information about using kill as function in code, use in cmd (__man 2 kill__) for information
* for types of kill refer command (man kill)

# Threads
* They are various sub-activities within application
* They are refered as Light Weight Process (LWP)
* Multiple threads running concurrently
* Threads have seperate thread control block

## Note Important:
* Threads have same Code and Data files but different registers and Stack
* Private/ local data is not shared
* If any one thread makes a blocking call, whole process gets blocked
* to use threads use (-lpthread), Eg: ( gcc filename.c -lpthread )

## Significance of threads
* Concurrent execution
* Resource sharing
* Child process will have own resources, but threads will have shared resources
* Scheduled threads interchangebly use cpu based on time sharing
* Faster than fork
* __Every Process is run initially as a single thread then multiple threads spawn__

## Types of Threads
* User Threads
    * Threads used by application programmers above kernel , __without kernel support__
* Kernel Threads
    * Supported within Kernel performs multiple simultaneous tasks to serve multiple kernel system calls

## Models
* Used to map user threads to kernel threads
* MANY-TO-ONE : Threads management is handled by thread library in user space
* ONE-TO-ONE : Limitaion is the count of threads that can be created
* MANY-TO-MANY

## POSIX (Portable Operating System Information Xchange)
* These are application / user level threads
* Commands (pthread_create,pthread_join,pthread_self,pthread_equal,pthread_yeild,pthread_cancel)

## Some Useful Commands 
* PWD -> Present Working Directory
* whoami -> user(prints user name)
* ~ -> gives absolute path
* echo $PATH -> It will chow all the executable files Directories that are there
* uname -a -> to get the name of operating system (i.e. GNU/Linux) with some additional information
* uname -o -> to get only operating system name
* mv -> to rename file
* where is pwd -> to know PWD executable file path

## File syntax
* OPEN:
    * syntax :  int open(const char *pathname, int flags, mode_t mode);
    * eg: open("filename",O_WRONLY,0666)

* READ:
    *  ssize_t read(int fd, void *buf, size_t count);
    * eg: read(fd, buf, length);

* WRITE
    * syntax :  ssize_t write(int fd, void *buf, size_t count);
    * write(fd,buf,length);
    * To print on Console replace fd with 1

* CLOSE
    * syntax : int close(int fd);
    * eg: close (fd);
# Check out examples in gealearn after comlpetion of reading this file
