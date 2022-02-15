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

* **Foreground Process**: By default, a process runs in the foreground, meaning that while it is running, the prompt is not available.
* **Background Process**: One can execute other commands while this process runs in the background.
* **Daemon Process**: System-related background process.

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
Signals are a way to communicate with a process.
When a signal is sent to a process, it stops whatever it is doing to handle the signal immediately.
We can define how a process deals with a specific signal by coding a signal handler, and assigning it to that signal using the ```signal``` or ```sigaction``` functions.
Watch [this video on signals](https://www.youtube.com/watch?v=83M5-NPDeWs) and learn more about [handling signals](http://www.cs.kent.edu/~ruttan/sysprog/lectures/signals.html). 
We can also use the ```trap``` command to perform actions (such as removing temporary files) when the process is interrupted.
Learn more about [traps here](https://www.tutorialspoint.com/unix/unix-signals-traps.htm).

### 🔪 Killing Processes
You may code a signal handler so that the application ignores a SIGTERM (```kill``` or ```kill -15```) signal, or a SIGINT, or many others.
When that happens, we can force an application to quit using ```kill -9```, which will take the kernel to remove that process from the processes table, without even going through the application.

```
kill -l         // list of all kill signals one can use/send
kill -2 <PID>   // 2 = SIGINT, interrupting (ctrl + C)
kill -20 <PID>  // 20 (or 18, double check in your machine!) = SIGTSTP, suspending (ctrl + Z)
kill -18 <PID>  // 18 (or 19, double check in your machine!) = SIGCONT, continue
```

### 🎭 Masking and Sigaction
If a signal is sent while the previous one is still being handled, we can get into trouble.
In order to avoid this, we can block signals from being processed until the handler is free.
For that we can use Masks: we create a signal set, where we define to which signals the mask is to be applied, and then use it in the ```struct sigaction``` that we give to the ```sigaction function```.
```sigaction``` is more recent than ```signal``` and it blocks new signals from arriving while the respective handler is busy, with masking, by default.
Learn more about the [difference between signal() and sigaction()](https://stackoverflow.com/questions/231912/what-is-the-difference-between-sigaction-and-signal).

<br />

## 💬 Converting Characters <-> Binary
Why not the plain old ASCII (decimal) to binary conversion?
[Unicode](https://techterms.com/definition/unicode) is a universal character encoding standard.
It's broader than ASCII, including special characters (and even emojis! 😎) and it can use up to 4 bytes per character.
The easiest way to convert Unicode characters is to look at them byte by byte, this way we don't need to care whether a character actually takes 1 or 4 bytes.
A way to dissecate each byte into its 8 bits is by using Bitwise operations.

### Converting ASCII to Binary
* Compare your byte with 10000000 (128) using the & (and) operator: if there are no common 1's (so the bit further to the left is a 0) it will return 0; else (so the bit further to the left is a 1) it will return something other than 0;
* Shift 10000000 (128) into 01000000 (64) with the >> (shift right) operator: 128 >> 1 = 64;
* Compare and shift, until you've analized each bit.

### Converting Binary to ASCII
* Set the initial character as 00000000 (0);
* For each bit received, compare it with the current version of your character using the | (or) operator: if none have 1's (meaning the bit you just received is a 0) it will return 0; else (so the bit you just received is a 1) it will return something different than 0;
* Alter the last bit of the character according to the previous result, and shift that bit to the left with << (shift left);

<br />

## 🗣 Minitalk Project Overview

### 🤖 Server side
* Assign your handler function to SIGUSR1 and SIGUSR2 signals with sigaction and its appropriate sigaction struct. Mask SIGUSR1 and SIGUSR2 signals so that they wait for the previous ones to be handled and use sa_sigaction function instead of sa_handler, so that you can access the client's PID in sig_info.
* Display server's PID and call pause() inside an infinite loop, so that the server is continuously waiting for new signals.
* The handler function will be called after each signal, so for each bit of the message. In order to be able to combine the bits into characters and then into a message, we need some of our variables to keep their value between function calls - we need static variables. I used static variables to store the number of bits received, the current character, the message and the client PID (after a while, the client PID wasn't sent anymore, thus becoming 0, so the server weren't able to send the confirmation signal to the client and sent it to himself, entering an infinite loop).
* For each bit received, the character is updated accordingly. Once 8 bits have been received, the character is added to the message and reset.
* The client will always end its message with a 0, so if the character is a 0, the message is printed on the terminal and reset.
* After each bit is processed, a SIGUSR1 signal is sent to the client as a confirmation that the signal was received.
* If an error occurs, a SIGUSR2 signal is sent tot the client notifying it that something went wrong.

### 👩‍💻 Client side
* Assign your handler function to the user signals, which will call the send_message function if the signal is SIGUSR1 or terminate the programme if the signal is SIGUSR2.
* Call the send_message function for the first time, providing it the message to be sent and the server's PID. Then call pause() inside an infinite loop so that the programme is continuously waiting for signals from the server until the whole message has been sent.
* Once again, we will need to preserve the value of some variables in the send_message function between function calls, so we will store the server's PID, the message and the number of bits sent as static variables.
* Analize each character and send the appropriate signal for each bit (I associated SIGUSR1 to 1 and SIGUSR2 to 0).
* Once the whole message has been sent, send 8 times the signal corresponding to zero (a static variable will be needed to keep track of it as well). Once that is done, successfully terminate the programme.

<br />

## 📬 A word on Pipex
Watch [Code Vault's videos on pipes](https://code-vault.net/course/46qpfr4tkz:1603732431896/lesson/16non3fdoh:1603732431950) and read [this tutorial on pipex](https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901) (watch it, some things are mentioned in a wrong way).

A pipe has two ends, one to be read and another one to be written, and is used to send information from one process to another one.
It should be used in a single direction, meaning, if process 1 is sending information via a pipe to process 2, the same pipe should not be used to send information from process 2 to process 1.
A second pipe should be opened for that.

On pipex, we will use at least two processes: process 1 reads from infile, executes cmd1 and writes the output to the writing end of the pipe, here mentioned as fd[1]; process 2 reads from the reading end of the pipe, here referred to as fd[0], executes cmd2 and writes the output to the outfile.
The actions to be performed in the two processes are very similar.
One should close the end of the pipe which will not be used - as long as one of the sides of the pipe is open, it will keep on waiting on information from it and won't stop executing.
Using ```dup2``` one must swap the file descriptor from the infile (or fd[0]) for STDIN_FILENO, meaning that by reading from file descriptor 0 we will no longer be reading from stdin but from the infile (or fd[0]).
Similarly, we'll swap the file descriptor from fd[1] (or outfile) for STDOUT_FILENO, meaning that by writing to the file descriptior 1 we will no longer be writing to stdout but to fd[1] (or outfile).
Once this was done, it's a matter of finding the right path to the given command and to execute it with ```execve```, which will replace the current process with a new one to run the given command (which is why you need one process per command).

For more on pipex, check out [Ben's repo](https://github.com/IamTheKaaZZ/pipex), [José's repo](https://github.com/J0Santos/42-pipex) or my future minishell partner [Knulpinette's repo](https://github.com/Knulpinette/Cursus42/tree/main/02-pipex).

