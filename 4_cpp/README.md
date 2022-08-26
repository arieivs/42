# CPP Modules
Piscine all over again? Not really.

## 🔗 Useful links
* [C++98 Documentation](https://www.cplusplus.com/doc/oldtutorial/)
* [CPP Modules Wiki](https://github.com/qingqingqingli/CPP/wiki)
* [C++ Tutorial](https://www.youtube.com/watch?v=yDkv5ypOfoU)
* [C++ Writing Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md)
* [Object creation on the stack vs heap](https://stackoverflow.com/questions/10157122/object-creation-on-the-stack-heap)
* [Orthodox Canonical Class form](https://www.francescmm.com/orthodox-canonical-class-form/)
* [Scope Resolution Operator ::](https://www.geeksforgeeks.org/scope-resolution-operator-in-c/)

<br/>

## 💧 IO stream
Imagine the following: we're getting user input from std::cin, and we are expecting an integer; if the user types anything other than digits (or well, something easy to convert to an integer such as +55), the programme goes crazy.
How to fix this? [Reset std::cin](https://stackoverflow.com/questions/39282953/how-to-reset-stdcin-when-using-it)
```
if (std::cin.fail()) {
	std::cin.clear();
	std::cin.ignore();
}
```
If at some point the user presses ctrl+D in the prompt, it closes std::cin, thus entering an infinite loop.
Potentially [more on this here](https://stackoverflow.com/questions/5146344/problem-with-consecutive-cins).

<br/>

## 💬 Strings
* [CPP Reference Strings](https://en.cppreference.com/w/cpp/string/basic_string)
* [Strings are not arrays of chars anymore... they're const](https://stackoverflow.com/questions/1524356/c-deprecated-conversion-from-string-constant-to-char)
* std::string allocates memory dynamically to the string, and frees it in the destructor (it feels weird...)

The size of a string is measured by the number of bytes needed to contain it, so if an utf-8 strange character (like é) requires more than one byte (2 bytes in this case), it will affect any size-dependent string manipulation.
More on [std::string with utf-8 here](https://stackoverflow.com/questions/50403342/how-do-i-properly-use-stdstring-on-utf-8-in-c) and [getting its size here](https://stackoverflow.com/questions/4063146/getting-the-actual-length-of-a-utf-8-encoded-stdstring).
(Luckily we have american keyboards at school.)

<br/>

## ⏩ Pointers to members functions
Read how to create [points to members functions here](https://isocpp.org/wiki/faq/pointers-to-members), and an [array of them here](https://stackoverflow.com/questions/43205893/array-of-pointers-on-member-functions-of-current-class).
TL;DR use ```typedef```.

<br/>

## 👨‍👩‍👧‍👦 Inheritance
* [Calling parent's constructor](https://stackoverflow.com/questions/66051940/how-to-call-parent-constructor-in-child-classes-constructor)
* [Destruction sequence](https://en.cppreference.com/w/cpp/language/destructor)

### 💊 Level of encapsulation
* **Public**: public and protected methods from parent class will be public and protected methods from child class, respectively.
* **Protected**: public and protected methods from parent class will be protected methods from child class.
* **Private**: public and protected methods from parent class will be private methods from child class.
In all three cases above, private members from parent class remain only accessible to the parent class.
[Read more here](https://www.go4expert.com/articles/encapsulation-inheritance-polymorphism-t29981/).

### 🔷 Diamond Inheritance
Diamond inheritance is a case of multiple inheritance, where classes B and C are both subclasses from A, and D inherits both from B and C.
Solution? B and C should inherit from A virtually, [more here](https://www.cprogramming.com/tutorial/virtual_inheritance.html).
In this way, instantiating D will create one single instance of A, B and C, while without the virtual keyword it would create 2 instances of A.
Thus calling a member function which D inherited from A could be ambiguous.

### 🏴 -Wshadow compilation flag
The [-Wshadow compilation flag](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html) warns you about situations where there is a risk of shadowing.
For example if a child class and its parent class both have an attribute with the same name, there is a risk of shadowing.

### 👻 ```virtual```
Imagine that we have a class Animal, and a class Dog which publicly inherits from it. We can do something like this:
```
Animnal*	a_dog = new Dog();
```
In order to do this, the Animal's destructor needs to be virtual, else it will be undefined behaviour.
[More here](https://www.geeksforgeeks.org/base-class-pointer-pointing-to-derived-class-object/).
Why? Before explaining, let's give another example.

Imagine both classes have a makeSound() method, which prints different outputs to the std::cout.
If we call ```a_dog.makeSound()```, we will call the function defined on the Animal class.
Why? Because the resolution of function calls is static, meaning it's decided at compilation time, and our compiler thinks a_dog is an Animal.
Solution? Add the prefix ```virtual``` to the makeSound() member function, both in the Animal and Dog classes. 
In this way the resolution of this function call will be dynamic, thus it will be decided during execution.
At that point our programme knows that a_dog is a Dog and will call the makeSound() function defined in the Dog class.

The situation is exactly the same for the destructors example.
By having a virtual destructor, we make sure we destroy the Dog object properly.

<br/>

## 🚨 Exceptions
The guy who shoots the videos on intra was clearly having a bad day when he shot these ones...
So here's some extra guidance on exceptions, [here](https://www.geeksforgeeks.org/exception-handling-c/) and [here](https://cplusplus.com/doc/tutorial/exceptions/).
