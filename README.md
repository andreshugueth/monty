# Stacks, Queues - LIFO, FIFO

## Resources:

* [Google](https://www.google.com/webhp?q=stack%20and%20queue)
* [How do I use extern to share variables between source files in C?](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files)
* [Queue using Stacks](https://www.geeksforgeeks.org/queue-using-stacks/)

## Learning Objectives

At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

### General

- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables

# More Info

## Data structures

Please use the following data structures for this project. Don’t forget to include them in your header file.

```c
/**
  * struct stack_s - doubly linked list representation of a stack (or queue)
  * @n: integer
  * @prev: points to the previous element of the stack (or queue)
  * @next: points to the next element of the stack (or queue)
  *
  * Description: doubly linked list node structure
  * for stack, queues, LIFO, FIFO Holberton project
  */
typedef struct stack_s
{
	        int n;
			        struct stack_s *prev;
					        struct stack_s *next;
} stack_t;
```

```c
/**
  * struct instruction_s - opcode and its function
  * @opcode: the opcode
  * @f: function to handle the opcode
  *
  * Description: opcode and its function
  * for stack, queues, LIFO, FIFO Holberton project
  */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

## Compilation & Output

- Your code will be compiled this way:

```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
- Any output must be printed on stdout
- Any error message must be printed on stderr
- [Here is a link to a GitHub repository](https://github.com/sickill/stderred) that could help you making sure your errors are printed on stderr



