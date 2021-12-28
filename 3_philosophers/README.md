# Philosophers
To eat or not to eat, that is the question

## Resources
Code Vault videos: https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2

https://miro.com/app/board/o9J_l0AjIkc=/

Advice from dcavalei: 1 advice, a good way to stop printing after someone died is to create a print function that prints according to a mutex that protects  the var "someone_died" , something like mutex lock; if someone died do nothing; else print message; mutex unlock;
This way when 1 philosopher talks, the others shut the hell up :D

Mutex: https://stackoverflow.com/questions/34524/what-is-a-mutex/34558#34558

Compiling: https://stackoverflow.com/questions/23250863/difference-between-pthread-and-lpthread-while-compiling

Testers:

https://github.com/newlinuxbot/Philosphers-42Project-Tester/blob/master/start.sh

https://github.com/mikysett/philosophers_tester
