# Philosophers
To eat or not to eat, that is the question

## 🧵 Threads
Watch [Code Vault's videos](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2) on threads.
A process can have multiple threads, which run in parallel (or concurrency), as long as your CPU power allows it.
If multiple threads need to use the same data, we can run into race conditions: a thread reads the value of a variable but then is put on hold while another one uses that same variable.
So when the first thread resumes activity, the value it uses is not updated.
How to prevent this?
Enter [mutexes](https://stackoverflow.com/questions/34524/what-is-a-mutex/34558#34558).
By protecting a critical section (a section where you are accessing and altering shared memory) with a mutex, once a thread arrives to that section it needs to wait until the mutex is unlocked to be able to lock it and run that section.

## 🚦 Semaphores (Bonus)
Code Vault's videos on semaphores (same playlist as above) are nice for the concepts but use deprecated functions.
Watch [this video on semaphores](https://www.youtube.com/watch?v=ukM_zzrIeXs) to complement it.
In case you question yourself about it, [here's the definition of an Atomic type](http://www.gnu.org/software/libc/manual/html_node/Atomic-Types.html).

Semaphores are counters.
When the counter is at 0, the thread or process has to wait until the value is increased by another thread.
The main difference between mutexes and semaphores is that mutexes have a sense of ownership: if you lock a mutex in a thread and unlock it in another thread, it leads to undefined behaviour. With a semaphor, that is not an issue.

## 🍝 Implementation

Advice from msessa: Be careful of odd philosopher number (ex: ./philo 5 800 200 200), this introduce odd forks and add priorities issues that can land in philosophers dying when they are not supposed to. This issue has been fixed here by adding a small mandatory time of thinking after sleep (this naturally gives philosophers thinking since more time priority over the just-released forks without breaking encapsulation).


Compiling: https://stackoverflow.com/questions/23250863/difference-between-pthread-and-lpthread-while-compiling

Testers:

https://github.com/newlinuxbot/Philosphers-42Project-Tester/blob/master/start.sh

https://github.com/mikysett/philosophers_tester

Visualiser: https://nafuka11.github.io/philosophers-visualizer/

