# 0x17-find_the_loop

# Linked List Loop Detection

This project contains an implementation of a function to detect loops in a linked list using Floyd's cycle-finding algorithm. The project provides a C file with the implementation, a header file with function prototypes, and a main file for testing.

## Contents

- [Introduction](#introduction)
- [Function](#function)
- [Usage](#usage)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

## Introduction

A linked list is a data structure composed of nodes that are connected together through pointers. In some cases, a linked list may have a loop where a node points back to a previous node in the list, creating an infinite cycle. The goal of this project is to detect such loops in a linked list.

The `find_listint_loop` function implemented in this project uses Floyd's cycle-finding algorithm, also known as the "tortoise and hare" algorithm, to detect loops in a linked list. It finds the loop by iterating through the list with two pointers: one moving one step at a time (`slow`), and the other moving two steps at a time (`fast`). If there is a loop, the two pointers will eventually meet at some node within the loop.

## Function

The project provides the following function:

```c
listint_t *find_listint_loop(listint_t *head);
find_listint_loop: Finds the loop in a linked list.
Parameters:
head: Pointer to the head of the linked list.
Returns:
The address of the node where the loop starts, or NULL if there is no loop.
```
## Usage

To use the find_listint_loop function in your own code, follow these steps:
1. Include the lists.h header file in your source file:
#include "lists.h"

2. Call the find_listint_loop function, passing the head of the linked list as the argument:
listint_t *loopStart = find_listint_loop(head);

3. The function will return the address of the node where the loop starts, or NULL if there is no loop.

## Testing 

The project includes a main file main.c that demonstrates the usage of the find_listint_loop function. It creates two linked lists and tests the function on each of them. You can compile and run the main file to see the output:
```
gcc -Wall -Werror -Wextra -pedantic main.c -o main
./main
```
The output will display the linked lists and indicate the start of the loop, if any.

## Contributing
Contributions to this project are welcome! If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

## License

```swift 
Make sure to include the appropriate `LICENSE` file in your repository as well, specifying the license under which the project is distributed.
```
