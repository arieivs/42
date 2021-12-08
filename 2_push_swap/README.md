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
Here your max stack size for a and b is already known and won't change (so the big advantage of chained lists just disappear) and yes it will be faster to make rotations but it will be way slower to find a specific number in your stack and traverse the list (so it may ends up being just more restrictive AND slower)

### Using int or void \*
for me, using void ended up nastly. 

### Resources
For 3 or 5: https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

rizky: https://github.com/rizky/42-push_swap

dimitri: https://github.com/DimitriDaSilva/42_push_swap

visualizer: https://github.com/o-reo/push_swap_visualizer

<br/>

## ⏱ Testing
### Using ARG
When I try to compile my program the way they ask us to in the correction of this project (using the variable ARG), it assumes the three numbers as part of the same string, therefore the Error output in my program.
It's zsh thing. Basically zsh creates a string, bash doesn't. To change zsh default setting, you need to add setopt shwordsplit in your .zshrc file

### Generating random numbers
seq MIN MAX | sort -R

### Testers
Tester: https://github.com/lmalki-h/push_swap_tester

Juliao speed tester:https://gist.github.com/brhaka/af12a3b49812014c5cea47301659e750
Gueifao speed tester: https://gist.github.com/fletcher97/1e95b2d6ce317c01cf27414b6699f0cb
