# **PIPEX**

<!--
    1-> what the subject all about;
    2-> the subject;
    3-> the fundimantels of the project [SHOULD KNOW!];
        1=> what is a proces;
        2=> how does it work;
    4-> my way of solving the project with explaining;
    5-> the finale note;
    6-> auther to contact me;
-->

1. [*The assignment.*](#the-assignment)
    1. [Mandatory part.](#mandatory-part)
    1. [Bonus part.](#bonus-part)
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
- The Bonus part is about multipel pipes and repreducing the HERE_DOC bihavior so it should work like:;
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
