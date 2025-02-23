# **PIPEX**

This project is about understanding what processes and pipes are and how they work and this documentation should give you the basics and help you start the project.

1. [*The assignment.*](#the-assignment)
    1. [Mandatory part.](#mandatory-part)
    1. [Bonus part.](#bonus-part)
1. [*Process.*](#process)
    1. [What is a process?](#what-is-a-process)
    1. [Process states.](#process-states)
1. [*Pipe.*](#pipe)
    1. [What is a Pipe?](#what-is-a-pipe)
    1. [How does it work?](#how-does-it-work)

1. [*Authors & Final mark:*](#authors--final-mark)


1. [*Subject*](./en.subject.pdf)

---

## **The assignment.**

### ***Mandatory part.***

- You must create a program that act exactly as bash:

``` bash
    < infile cmd[1] | cmd[2] > outfile
```

- Your program must only take 4 parameters as follows:

``` bash
    ./pipex infile cmd[1] cmd[2] outfile
```

---

### ***Bonus part.***

- The Bonus part is about multiple pipes and reproducing the HERE_DOC behavior so it should work like:

``` bash
    < infile cmd[1] | ... | cmd[n] > outfile
```

or:

``` bash
    << LIMITER cmd[1] | ... | cmd[n] >> outfile
```

- Your program will be called as:

``` bash
    ./pipex_bonus infile cmd[1] ... cmd[n] outfile
```

or :

``` bash
    ./pipex_bonus here_doc LIMITER cmd[1] ... cmd[n] outfile
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

## **Pipe.**

### ***What is a Pipe?***

>In computer programming, a pipe is a technique for passing information from one [*process*](#process) to another in a oneway direction.

![img](https://cdn.ttgtmedia.com/rms/onlineimages/how_pipes_work-h.png)

### ***How does it work?***

> The pipe works by creating a buffer in the kernel and returning two file descriptors (FDs) that refer to it.

## **Authors & Final mark::**

This project was done by [**jaguar-ks**](https://github.com/jaguar-ks):

![mark](https://github.com/jaguar-ks/ft_IRC/blob/main/final_mark.png?raw=true)
