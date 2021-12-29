# Push Swap
A project about sorting algorithms and complexity which uses the worst possible data structure to sort

<br/>

## ⏳ Sorting Algorithms and Complexity
Read this [introduction on time complexity](https://remimercier.com/wtf-time-complexity/) and watch this [introductin on Big O notation and sorting algorithms](https://www.youtube.com/watch?v=RGuJga2Gl_k).

This might be a good moment to dig into some popular sorting algorithms, such as quick sort and merge sort: find [further explanations, code in C and resources for some sorting algorithms here](https://github.com/arieivs/algorithms/tree/master/sort).
Although the best one is, of course, the [sleep sort](https://kevlinhenney.medium.com/need-something-sorted-sleep-on-it-11fdf8453914) 😴.

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
Check [this article](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) on how to sort stack with up to 3 elements.
For a stack with up to 5 elements, look for the two smallest numbers in stack A and move them to B (in order).
After ordering the remaining elements in A, simply push the 2 smallest elements back to A and it's done!

The best way to come up with a generic sorting algorithm (so something to be used with a stack with 6 elements or with a stack with 1000 elements) is to watch someone else's code in action.
Use this [push swap visualizer](https://github.com/o-reo/push_swap_visualizer).
For me, the algorithm which proved to be the easiest for me to understand, thus becoming my source of inspiration, was [Knulpinette's](https://github.com/Knulpinette/Cursus42/tree/main/02-push_swap).
For better performances check [Rizky's](https://github.com/rizky/42-push_swap) or [Dimitri's](https://github.com/DimitriDaSilva/42_push_swap) (I believe they follow a similar logic), or [Flávio's](https://github.com/flaviomota/push_swap) who has a very different approach.
[APinto](https://github.com/protsaq/push_swap) also offers a different perspective.

I start by scanning through the whole stack A and pushing all elements lower than its mean to stack B.
Then I go through stack B and push all elements wich are higher than its mean back to the top of A.
I repeat this until the size of B is below a certain number.
This threshold was determined empirically and it does not depend on stack A's original size: I simply run the programme multiple times with different thresholds and picked the one giving better results (which was 20 by the way).
At this point, stack A is pre-sorted, and stack B has a manageable amount of elements which can be moved to the bottom of A in the right order.
Once that is done, we move the next pre-sorted chunck of numbers from A to B and repeat the process until they are all sorted at the bottom of A.

### Mean vs Median
In order to achieve better results, one should use the median.
After all, that's what we trully want: to have half of the elements in one side and the other half in the other.
However, what's the first step to calculate the median of a set of numbers?
Sort it.
Which meant that I would need to create a copy of my list and sort it in a faster way to help me sort it in a slower way.
Hmm...

Mean and Median can be very different.
That's true.
Yet, most random numbers generators will give you a set of numbers not too far away from a normal distribution.
So I felt that mean was good enough.
Yet, if you're looking for ways to optimize your code, by all means do calculate and use the median instead.

<br/>

## ⏱ Testing
[Push swap tester](https://github.com/lmalki-h/push_swap_tester).

### Using ARG
When giving the parameters to the programme via the ARG environment variable, it will probably take it as a single argument.
For this reason, my programme can both receive the arguments as a single string, so ```./push_swap "3 6 4 2 5"``` or one argument per element, so ```./push_swap 3 6 4 2 5```.
However, that wasn't necessary.
This behaviour (interpreting the value of ARG as a single string) is a default for zsh.
While zsh creates a string, bash doesn't.
To change zsh default settings, you need to add ```setopt shwordsplit``` in your .zshrc file.

### Generating random numbers
```ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`;```

```seq MIN MAX | sort -R```
