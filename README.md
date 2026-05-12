*This project has been created as part of the 42 curriculum by vleroy.*

# Description

This project is written in C, in accordance with the Norm.

The functions do not quit unexpectedly (segmentation fault, bus error, dou-
ble free, etc.) except for undefined behavior.

All heap-allocated memory are properly freed when necessary.

The Makefile compiles the source files to the required output with the flags -Wall, -Wextra, and -Werror, using cc.
The Makefile does not perform unnecessary relinking.
The Makefile contain the rules $(NAME), all, clean, fclean and re.


# Instructions

use the command *make* in repository to create `libft.a` file.
use the command *make clean* to remove `.o` file in the repository.
use the command *make fclean* to remove `.o` & `libft.a` file.

# Resources

stackoverflow & google was used for syntax and variable access questions. 
AI was used to help understand syntax for maker file, to help creating some test cases & to assist in the detailed library description part of this README.
man was used to reproduce function logic.
Book - C++ : Programming in C.

# Detailed library description

`libft.a` is a custom C static library that reimplements a selection of standard C library functions, along with additional utility functions for memory management, string manipulation, character checks, linked lists, and file descriptor output.

---

## Functions

### Character Check Functions

| Function | Description |
|---|---|
| `ft_isalpha` | Checks whether a character is alphabetic. |
| `ft_isdigit` | Checks whether a character is a digit. |
| `ft_isalnum` | Checks whether a character is alphanumeric. |
| `ft_isascii` | Checks whether a character belongs to the ASCII table. |
| `ft_isprint` | Checks whether a character is printable. |

---

### Character Conversion Functions

| Function | Description |
|---|---|
| `ft_toupper` | Converts a lowercase character to uppercase. |
| `ft_tolower` | Converts an uppercase character to lowercase. |

---

### String Functions

| Function | Description |
|---|---|
| `ft_strlen` | Calculates the length of a string. |
| `ft_strchr` | Finds the first occurrence of a character in a string. |
| `ft_strrchr` | Finds the last occurrence of a character in a string. |
| `ft_strncmp` | Compares two strings up to a given number of characters. |
| `ft_strnstr` | Locates a substring inside a string, limited by length. |
| `ft_strdup` | Duplicates a string using allocated memory. |
| `ft_substr` | Creates a substring from a given string. |
| `ft_strjoin` | Joins two strings into a new allocated string. |
| `ft_strtrim` | Removes specified characters from the beginning and end of a string. |
| `ft_split` | Splits a string into an array of strings using a delimiter. |
| `ft_strmapi` | Creates a new string by applying a function to each character. |
| `ft_striteri` | Applies a function to each character of a string in place. |

---

### Memory Functions

| Function | Description |
|---|---|
| `ft_memset` | Fills a block of memory with a specific byte. |
| `ft_bzero` | Sets a block of memory to zero. |
| `ft_memcpy` | Copies memory from one area to another. |
| `ft_memmove` | Copies memory safely, even when areas overlap. |
| `ft_memchr` | Searches memory for a specific byte. |
| `ft_memcmp` | Compares two memory areas. |
| `ft_calloc` | Allocates memory and initializes it to zero. |

---

### Conversion Functions

| Function | Description |
|---|---|
| `ft_atoi` | Converts a string to an integer. |
| `ft_itoa` | Converts an integer to a string. |

---

### File Descriptor Output Functions

| Function | Description |
|---|---|
| `ft_putchar_fd` | Outputs a character to a given file descriptor. |
| `ft_putstr_fd` | Outputs a string to a given file descriptor. |
| `ft_putendl_fd` | Outputs a string followed by a newline to a given file descriptor. |
| `ft_putnbr_fd` | Outputs an integer to a given file descriptor. |

---

## List Functions

The linked list utilities are using the `t_list` structure.

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new linked list node. |
| `ft_lstadd_front` | Adds a node to the beginning of a linked list. |
| `ft_lstsize` | Counts the number of nodes in a linked list. |
| `ft_lstlast` | Returns the last node of a linked list. |
| `ft_lstadd_back` | Adds a node to the end of a linked list. |
| `ft_lstdelone` | Deletes one node using a given delete function. |
| `ft_lstclear` | Deletes and frees an entire linked list. |
| `ft_lstiter` | Applies a function to each node of a linked list. |
| `ft_lstmap` | Creates a new linked list by applying a function to each node. |

---

## Function Categories Overview

| Category | Functions |
|---|---|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| String manipulation | `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri` |
| Memory manipulation | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Type conversion | `ft_atoi`, `ft_itoa` |
| File descriptor output | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` |
| Linked list bonus | `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap` |

---

## Compilation

The library is compiled into a static archive named:

`libft.a`

It can then be linked with other C programs.
