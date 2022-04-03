

# StudyMaterial Linux
* Printf is defined in standard C library 
* memory mapping is stored in .out file
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

# Kernal
* It is a program that links CPU & Memory

# Kernal Types 
* Monolithic Kernal
    * User and Kernal services implemented under same address space

* Micro Kernal (For Embedded boards)
    * Minimum no.of functions that are required to implement OS

* Modular Kernal
    * Some part of system core will get allocated in independent files called Modules
    * ___ Dynamic modules ___ : Loaded /Unloaded anytime
    * ___ Static modules ___ : Loaded /Unloaded with system Boot

# Dual Mode have 2 modes (Differentiated by Mode Bit)
* User Mode
    * By default it is 3 GB
* Kernal Mode (Super Mode/Admin Mode/Root mode)
    * By default it is 1 GB

# Interrupt (no blocking calls)
* It is an event which stops / ends execution of current process then it jumps to interrupt handler

# System Call
* This is basically a method that allows a program to request service from the kernal
* System calls are known by their numbers not addresses

# File Descriptor (fd)
* File descriptor describe the type of file
* FD will create file descriptor table maintained by kernel
* File descriptor used by any process
    * fd = 0 (stdin)(read)
    * fd = 1 (stdout)(write)
    * fd = 2 (stderr)
