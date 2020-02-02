## Basic C++ Syntax
1. hello world

```c++
// this is a hello world

/* multi
line comment! */

#include <iostream>

int main() {
	std::cout << "Hello World" <<endl; // 
	return 0;
} 
```

2. importing libraries

```c++
#include <NAME> or #include "NAME"
```
< >: Search for the library/file in the include path list first
" ": Search for the library/file in the current directory of your source code

3. how to run c++ program
In the linux terminal, run:

```shell
$ g++ -std=c++11 filename.cpp
$ ./a.out
```
4. variables type

5. casting (type conversion)

6. Arithmetic Operations

7. conditional

8. loop

8. arrays

9. pointer

10. exception handling

11. scope

12. function

13. Reading User-input & output
#include <iostream>

int main() {
	auto num = 0;
	std::cout << "Please enter a number:\n";
	std::cin >> num;
	std::cout << "You entered " << num << "\n";
}

14. Undefined Behavior