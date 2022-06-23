# CPP Modules

## Useful links
* https://github.com/qingqingqingli/CPP/wiki
* https://www.youtube.com/watch?v=yDkv5ypOfoU (tutorial dimitri suggested)
* https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md (Writting Guidelines)
* https://stackoverflow.com/questions/10157122/object-creation-on-the-stack-heap (memory allocation)
* https://www.cplusplus.com/doc/oldtutorial/ (C++98)
* [Orthodox Canonical Class form](https://www.francescmm.com/orthodox-canonical-class-form/)
* [Scope Resolution Operator ::](https://www.geeksforgeeks.org/scope-resolution-operator-in-c/)

## IO stream
if we want to get an int from std::cin and something that doesn't match that data type is given, it fails, and potentially goes crazy.
https://stackoverflow.com/questions/39282953/how-to-reset-stdcin-when-using-it
if (std::cin.fail())
{
	std::cin.clear();
	std::cin.ignore();
}

Right now if I press ctrl+D while waiting for user input, I close std::cin, thus it enters a sort of infinite crazy loop.
https://stackoverflow.com/questions/5146344/problem-with-consecutive-cins

## Strings
https://en.cppreference.com/w/cpp/string/basic_string

https://stackoverflow.com/questions/1524356/c-deprecated-conversion-from-string-constant-to-char

std::string automatically allocates memory dynamically to the string, and frees it in the destructor.

When there's utf-8 characters involved, things might get tricky... the size is refering to the amount of bytes needed, so if a character (like é) uses more bytes (in this case 2) it may make things more complicated... Luckily we have american keyboards at school

https://stackoverflow.com/questions/50403342/how-do-i-properly-use-stdstring-on-utf-8-in-c

https://stackoverflow.com/questions/4063146/getting-the-actual-length-of-a-utf-8-encoded-stdstring

## CPP00
Wondering whether to have the instance variables as parameters from the constructor... which kinda makes more sence to me. In the end I didn't do it cos since we will be creating all the contacts before we have that information, all those values would just be null. So... might as well just go the "naive" way.

## Pointers to members functions
https://stackoverflow.com/questions/43205893/array-of-pointers-on-member-functions-of-current-class
https://isocpp.org/wiki/faq/pointers-to-members

moral of the story: user typedef
