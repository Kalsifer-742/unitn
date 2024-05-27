# Appunti laboratorio

## Random

- non serve using namespace std
- in C non esiste passare per riferimento
- è obbligatorio mettere i permessi dopo i flag se si usa O_CREAT
- SIGCHLD sempre poter essere utile e importante
- per sicurezza lavorando con più processi è meglio lavorare con i file descriptor
- 0777 come permesso nel dubbio
- gestisci gli errori con errno e perror
- exit come fare return dal main (se nello stesso processo)
- le cose sono persistenti tra programmi diversi

<div style="page-break-after: always;"></div>

## C

##### Passare array come parametro

```C
//When passing an array as a parameter, this         
void arraytest(int a[])
//means exactly the same as
void arraytest(int *a)
//so you are modifying the values in main. (For historical reasons, arrays are not first class citizens and cannot be passed by value)
```

##### String Read Only
```C
char* string = “ciao;  //  READ-ONLY
```

##### Fork
```C
if(child == 0)
{
    exit(0); //uscire dai figli con exit() e non return (ricordati cosa diceva stackoverflow).
}
```

##### Segnali
```C
signal(SIGINT,SIG_IGN);  //Ignore signal
```

<div style="page-break-after: always;"></div>

## Segnali

Signal | Default action | Description
--- | --- | ---
SIGABRT|Terminate (core dump)|Process abort signal
SIGALRM|Terminate|Alarm clock
SIGBUS|Terminate (core dump)|Access to an undefined portion of a memory object
SIGCHLD|Ignore|Child process terminated, stopped, or continued
SIGCONT|Continue|Continue executing, if stopped
SIGFPE|Terminate (core dump)|Erroneous arithmetic operation
SIGHUP|Terminate|Hangup
SIGILL|Terminate (core dump)|Illegal instruction
SIGINT|Terminate|Terminal interrupt signal (Ctrl+C)
SIGKILL|Terminate|Kill (cannot be caught or ignored)
SIGPIPE|Terminate|Write on a pipe with no one to read it
SIGPOLL|Terminate|Pollable event
SIGPROF|Terminate|Profiling timer expired
SIGQUIT|Terminate (core dump)|Terminal quit signal
SIGSEGV|Terminate (core dump)|Invalid memory reference
SIGSTOP|Stop|Stop executing (cannot be caught or ignored)
SIGSYS|Terminate (core dump)|Bad system call
SIGTERM|Terminate|Termination signal
SIGTRAP|Terminate (core dump)|Trace/breakpoint trap
SIGTSTP|Stop|Terminal stop signal
SIGTTIN|Stop|Background process attempting read
SIGTTOU|Stop|Background process attempting write
SIGUSR1|Terminate|User-defined signal 1
SIGUSR2|Terminate|User-defined signal 2
SIGURG|Ignore|Out-of-band data is available at a socket
SIGVTALRM|Terminate|Virtual timer expired
SIGXCPU|Terminate (core dump)|CPU time limit exceeded
SIGXFSZ|Terminate (core dump)|File size limit exceeded
SIGWINCH|Ignore|Terminal window size changed 