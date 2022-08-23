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

## 💧 IO stream
if we want to get an int from std::cin and something that doesn't match that data type is given, it fails, and potentially goes crazy.
https://stackoverflow.com/questions/39282953/how-to-reset-stdcin-when-using-it
if (std::cin.fail())
{
	std::cin.clear();
	std::cin.ignore();
}

Right now if I press ctrl+D while waiting for user input, I close std::cin, thus it enters a sort of infinite crazy loop.
https://stackoverflow.com/questions/5146344/problem-with-consecutive-cins

## 💬 Strings
https://en.cppreference.com/w/cpp/string/basic_string

https://stackoverflow.com/questions/1524356/c-deprecated-conversion-from-string-constant-to-char

std::string automatically allocates memory dynamically to the string, and frees it in the destructor.

When there's utf-8 characters involved, things might get tricky... the size is refering to the amount of bytes needed, so if a character (like é) uses more bytes (in this case 2) it may make things more complicated... Luckily we have american keyboards at school

https://stackoverflow.com/questions/50403342/how-do-i-properly-use-stdstring-on-utf-8-in-c

https://stackoverflow.com/questions/4063146/getting-the-actual-length-of-a-utf-8-encoded-stdstring

## ⏩ Pointers to members functions
https://stackoverflow.com/questions/43205893/array-of-pointers-on-member-functions-of-current-class
https://isocpp.org/wiki/faq/pointers-to-members

moral of the story: user typedef

## 👨‍👩‍👧‍👦 Inheritance
* calling parent's constructor: https://stackoverflow.com/questions/66051940/how-to-call-parent-constructor-in-child-classes-constructor
* destruction sequence: https://en.cppreference.com/w/cpp/language/destructor

### Level of encapsulation
https://www.go4expert.com/articles/encapsulation-inheritance-polymorphism-t29981/
* Public: public and protected methods from parent class will be public and protected methods from child class, respectively.
* Protected: public and protected methods from parent class will be protected methods from child class.
* Private: public and protected methods from parent class will be private methods from child class.
In all three cases above, private members from parent class remain only accessible to the parent class.

### Diamond Inheritance
Diamond inheritance is a case of multiple inheritance, where classes B and C are both subclasses from A, and D inherits both from B and C.
solution: use virtual inheritance, https://www.cprogramming.com/tutorial/virtual_inheritance.html 

### -Wshadow compilation flag
-Wshadow: https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
In ex03, there is ClapTrap::name, both ScavTrap and FragTrap inherit this attribute, and DiamondTrap inherits from both.
So already exists a DiamondTrap::name, but it is required a private name for the class Diamond, so there is a risk of shadowing and the flag -Wshadow will warn it.
The flag -Wno-shadow will ignore it

