# Philosophers
To eat or not to eat, that is the question

<br/>

## 🧵 Threads
Watch [Code Vault's videos](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2) on threads.
A process can have multiple threads, which run in parallel (or concurrency), as long as your CPU power allows it.
If multiple threads need to use the same data, we can run into race conditions: a thread reads the value of a variable but then is put on hold while another one uses that same variable.
So when the first thread resumes activity, the value it uses is not updated.
How to prevent this?
Enter [mutexes](https://stackoverflow.com/questions/34524/what-is-a-mutex/34558#34558).
By protecting a critical section (a section where you are accessing and altering shared memory) with a mutex, once a thread arrives to that section it needs to wait until the mutex is unlocked to be able to lock it and run that section.

<br/>

## 🚦 Semaphores (Bonus)
Code Vault's videos on semaphores (same playlist as above) are nice for the concepts but use deprecated functions.
Watch [this video on semaphores](https://www.youtube.com/watch?v=ukM_zzrIeXs) to complement it.
In case you question yourself about it, [here's the definition of an Atomic type](http://www.gnu.org/software/libc/manual/html_node/Atomic-Types.html).

Semaphores are counters.
When the counter is at 0, the thread or process has to wait until the value is increased by another thread.
The main difference between mutexes and semaphores is that mutexes have a sense of ownership: if you lock a mutex in a thread and unlock it in another thread, it leads to undefined behaviour. With a semaphor, that is not an issue.

<br/>

## 🍝 Implementation
The flag ```-pthread``` is required for compilation.
If in doubt, check [this for pthread vs lpthread](https://stackoverflow.com/questions/23250863/difference-between-pthread-and-lpthread-while-compiling).

### 🏃‍♂️ Avoiding race conditions
When there's an odd number of philosophers, we need to make sure the one who didn't eat the longest manages to grab the forks instead of another one.
Imagine the following: there's 5 philosophers; 1 and 3 eat; 2 and 4 eat; 5 and either 1 or 3 should start eating now, but instead 1 and 3 start eating again and 5 starves.
In order to avoid this, a small mandatory thinking time was added when the number of philosophers is odd.
In this way, the ones who just finished sleeping and started thinking will be in disadvantage in comparison to those who are thinking the longest (and thus not eating the longest).
[This visualiser](https://nafuka11.github.io/philosophers-visualizer/) helped me understanding this a lot.
If you're following you might be thinking... but that only works in time_to_eat and time_to_sleep are the same. If time_to_sleep is significantly smaller, that small mandatory thinking time won't make a difference.
True!
So if time_to_sleep is smaller than time_to_eat, my philosophers need to think for the difference between the two plus that small buffer.

### ☠️ Avoiding more than one death announcement
What if more than one philosopher die at exactly the same time?
There will always be a small difference in the times of death, but it won't be enough for the system to update.
Adding a small delay before printing the death message solved the issue for me.
I believe that due to usleep() unaccuracy it enlarges the gap between the printing function calls.

### 🖥 Hardware matters! ⚠️
On my computer, sometimes philosophers died when they shouldn't.
There were small delays, which accumulated and led to premature deaths.
However, the same code worked perfectly fine, without any delays, on school's computers.
Why?
Because school's computers have more CPU power.
Mine has a double core while the school's has a 6 core, and it's faster.
So while mine needed to put some threads on hold even with 4 or 5 philosophers, thus having delays, at school that issue only appeared with a larger number of philosophers.

<br/>

### ⏱ Testers and Visualiser
Check [this simple tester](https://github.com/newlinuxbot/Philosphers-42Project-Tester) and [Michele's tester](https://github.com/mikysett/philosophers_tester).
Once again, [this visualiser](https://nafuka11.github.io/philosophers-visualizer/) was a great help.

<br/>

Happy philosophising! 💭
