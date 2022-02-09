# Philosophers
To eat or not to eat, that is the question

## Resources
Code Vault videos: https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2

Advice from dcavalei: 1 advice, a good way to stop printing after someone died is to create a print function that prints according to a mutex that protects  the var "someone_died" , something like mutex lock; if someone died do nothing; else print message; mutex unlock;
This way when 1 philosopher talks, the others shut the hell up :D

Advice from msessa: Be careful of odd philosopher number (ex: ./philo 5 800 200 200), this introduce odd forks and add priorities issues that can land in philosophers dying when they are not supposed to. This issue has been fixed here by adding a small mandatory time of thinking after sleep (this naturally gives philosophers thinking since more time priority over the just-released forks without breaking encapsulation).

Mutex: https://stackoverflow.com/questions/34524/what-is-a-mutex/34558#34558

Compiling: https://stackoverflow.com/questions/23250863/difference-between-pthread-and-lpthread-while-compiling

Testers:

https://github.com/newlinuxbot/Philosphers-42Project-Tester/blob/master/start.sh

https://github.com/mikysett/philosophers_tester

Visualiser: https://nafuka11.github.io/philosophers-visualizer/

Semaphors:
https://www.youtube.com/watch?v=ukM_zzrIeXs

Atomic types:

https://stackoverflow.com/questions/36955884/what-are-atomic-types-in-the-c-language

http://www.gnu.org/software/libc/manual/html_node/Atomic-Types.html
