# Minitalk
A client and a server want to have a chat.

👉 Follow [Maria's amazing Wiki](https://github.com/mlanca-c/Minitalk/wiki#intro).

<br />

## 🔀 UNIX Processes
A process is an instance of running a programme.
Processes are usually created by another process, which is then the Parent process of that Child process.
They can then be identified by their Process ID (PID) or Parent Process ID (PPID).
When the computer boots, one of the last things the kernel does is to call the init process (e.g.'s: systemd, launchd, upstart), parent of all processes, which has the PID 1. 
If a Parent process is terminated before its Child, the Child process will be an Orphan and its Parent will now be the init process.

* *Foreground Process*: By default, a process runs in the foreground, meaning that while it is running, the prompt is not available.
* *Background Process*: One can execute other commands while this process runs in the background.
* *Daemon Process*: System-related background process.

Some useful commands:

```
ps -f           // process status with more detailed information
exec            // replace a process for another (the child for its parent once it ends)
<cmd> &         // run command/start process in the background
jobs            // jobs table
fg %<job ID>    // bring that particular job to the foreground
bg %<job ID>    // put process in the background
kill <PID>      // terminated process
```

### 🤔 Why use Processes in our Programmes?
If a programme needs to run more than one function simultaneously, then we need to create a Child Process.
This way both functions are running simultaneously.
We can do this by using the fork() function.

Learn more on [UNIX Processes here](https://www.tutorialspoint.com/unix/unix-processes.htm) and check [Engineer Man's video about it](https://www.youtube.com/watch?v=TJzltwv7jJs).

<br />

## 🚨 UNIX Signals
Blabla

### 🔪 Killing Processes
Applications are listening to signals and can be programmed to do whatever they want with them.
In other words, an application may ignore a SIGTERM (```kill``` or ```kill -15```) signal.
When that happens, we can force an application to quit using ```kill -9```, which will take the kernel to remove that process from the processes table, without even going through the application.

```
kill -l         // list of all kill signals one can use/send
kill -2 <PID>   // 2 = SIGINT, interrupting (ctrl + C)
kill -20 <PID>  // 20 (or 18, double check in your machine!) = SIGTSTP, suspending (ctrl + Z)
kill -18 <PID>  // 18 (or 19, double check in your machine!) = SIGCONT, continue
```

