# **PIPEX**

<!--
    D|1-> what the subject all about;
    D|2-> the subject;
    3-> the fundimantels of the project [SHOULD KNOW!];
        1=> what is a proces;
        2=> how does it work;
    4-> my way of solving the project with explaining;
    5-> the finale note;
    6-> auther to contact me;
-->
This project is about understanding what processes and pipes are and how they work and this documentation should give you the basics and help you start the project.
1. [*The assignment.*](#the-assignment)
    1. [Mandatory part.](#mandatory-part)
    1. [Bonus part.](#bonus-part)
1. [*Process.*](#process)
    1. [What is a process?](#what-is-a-process)
    1. [Process states.](#process-states)
---
## **The assignment.**

### ***Mandatory part.***
- You must create a programme that act exactly as bash:
``` bash
    < infile cmd1 | cmd2 > outfile
```
- Your programme must only take 4 parametres as follows:
``` bash
    ./pipex infile cmd1 cmd2 outfile
```
---
### ***Bonus part.***
- The Bonus part is about multipel pipes and repreducing the HERE_DOC bihavior so it should work like:
``` bash
    < infile cmd1 | ... | cmdn > outfile
```
or:
``` bash
    << LIMITER cmd1 | ... | cmdn >> outfile
```
- Your programme will be called as:
``` bash
    ./pipex_bonus infile cmd1 ... cmdn outfile
```
or :
``` bash
    ./pipex_bonus here_doc LIMITER cmd1 ... cmdn outfile
```

Check out the subject for more understanding. [**here**.](./en.subject.pdf)

## **Process**

### ***What is a process?***

> A process is basically a program in execution, To put it in simple terms, we write our computer programs in a text file and when we execute this program, it becomes a process which performs all the tasks mentioned in the program, when a program is loaded into the memory and it becomes a process.

### ***Process states:***

| State | Description |
|-------|-------------|
| Start | This is the initial state when a process is first started/created.|
| Ready |The process is waiting to be assigned to a processor. Ready processes are waiting to have the processor allocated to them by the operating system so that they can run. Process may come into this state after Start state or while running it by but interrupted by the scheduler to assign CPU to some other process. |
| Running | Once the process has been assigned to a processor by the OS scheduler, the process state is set to running and the processor executes its instructions.|
| Waiting |Process moves into the waiting state if it needs to wait for a resource, such as waiting for user input, or waiting for a file to become available. |
| Terminated | Once the process finishes its execution, or it is terminated by the operating system, it is moved to the terminated state where it waits to be removed from main memory.|



