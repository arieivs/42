# Push Swap
A project about sorting algorithms and complexity which uses the worst possible data structure to sort

<br/>

## ⏳ Sorting Algorithms and Complexity
To watch: https://www.youtube.com/watch?v=D6xkbGLQesk

Just for the fun:
Sleep sort: https://kevlinhenney.medium.com/need-something-sorted-sleep-on-it-11fdf8453914

<br/>

## 🥞 Implementation
### Array vs Linked Lists
There's a little war on discord on whether to use arrays or linked lists for this project.
Given that the size of A is known from the start and it won't change, the main advantage of linked lists disappears.
Additionally, it's easier/faster to iterate through a whole array and find a specific value using indexes.
On the other hand, it will be faster to make rotations and the other main operations allowed for push swap using linked lists, and stacks are, typically, implemented with linked lists.
The conclusion?
Both are ok, just go with whatever works best for you.
This project might be THE moment you finally get around and comfortable with linked lists, which is a criteria as good as any other.
Personally I decided to use linked lists.
What you definitelly don't need though, is a double linked list (where each node has both a pointer to the next one and the previous one).

### Content of type int vs void \*
Initially, I was using the linked lists implemented in libft, with content of type void \*.
The obvious advantage being that I was using something versitile.
However, this required for a lot of typecasting, as everytime I wanted to read the value x stored as void \* I needed to do \*(int \*)x.
Additionally, at some point I started having serious issues when storing the values in the stack, and changing the content type to int solved it.
Structs automatically allocate the required memory for its content, and the amount of memory used by an int or a void \* is different.
I believe that's why the change fixed it, although there is obviously alternative solutions to this.

### The algorithm
Check [this article](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) on how to sort stack

rizky: https://github.com/rizky/42-push_swap

dimitri: https://github.com/DimitriDaSilva/42_push_swap

visualizer: https://github.com/o-reo/push_swap_visualizer

<br/>

## ⏱ Testing
### Using ARG
When I try to compile my program the way they ask us to in the correction of this project (using the variable ARG), it assumes the three numbers as part of the same string, therefore the Error output in my program.
It's zsh thing. Basically zsh creates a string, bash doesn't. To change zsh default setting, you need to add setopt shwordsplit in your .zshrc file

### Generating random numbers
```ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`;```

```seq MIN MAX | sort -R```

### Testers
Tester: https://github.com/lmalki-h/push_swap_tester

Michele speed tester: https://github.com/mikysett/push_swap_speed_tester

Juliao speed tester:https://gist.github.com/brhaka/af12a3b49812014c5cea47301659e750

Gueifao speed tester: https://gist.github.com/fletcher97/1e95b2d6ce317c01cf27414b6699f0cb
