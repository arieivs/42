# Minitalk
A client and a server want to have a chat.
👉 Follow [Maria's amazing Wiki](https://github.com/mlanca-c/Minitalk/wiki#intro).

<br />

## 🔀 UNIX Processes
```
ps -f			// process status with more detailed information
exec			// replace a process for another (the child for its parent once it ends)
<cmd> &			// run command/start process in the background
jobs			// jobs table
fg %<job ID>	// bring that particular job to the foreground
bg				// put process in the background
kill -l			// list of all kill signals one can use/send
kill -2 <PID>	// 2 corresponds to SIGINT, same as doing ctrl + C
kill -20 <PID>	// 20 (or 18, double check in your machine!) corresponds to SIGTSTP, so suspending, same as doing ctrl + Z
kill -18 <PID>	// 18 (or 19, double check in your machine!) corresponds to SIGCONT, so continue
```

### 🔪 Killing Processes
Applications are listening to signals and can be programmed to do whatever they want with them.
In other words, an application may ignore a SIGTERM (```kill``` or ```kill -15```) signal.
When that happens, we can force an application to quit using ```kill -9```, which will take the kernel to remove that process from the processes table, without even going through the application.

More on [Engineer Man's video](https://www.youtube.com/watch?v=TJzltwv7jJs)
