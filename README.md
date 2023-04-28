# ft_printf
The ft_printf project challenges us to create a function that mimics the behaviour of the C standard library's `printf()` function,
which prints formatted output to the standard output stream or a user-defined output stream.

## Getting Started
To use the `ft_printf` function, simply clone the repository to your local machine.
The library comes with a Makefile that includes the following rules:

- `all`: compiles the library
- `re`: recompiles the library
- `fclean`: removes all object files and the library
- `clean`: removes all object files

To compile the library, run:

```bash
make all
```
This will generate a `.a` file that you can link to your C projects.

## Using the Function
To use the ft_printf function, include the `ft_printf.h` header file in your C source files.

```C
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    return (0);
}
```

### Supported Conversion Specifiers
It supports the following conversion specifiers:

|Specifier|Output|
|---|---|
|`%c`|Character|
|`%s`|String|
|`%p`|Pointer address|
|`%d`|Signed decimal integer|
|`%i`|Signed decimal integer|
|`%u`|Unsigned decimal integer|
|`%x`|Unsigned hexadecimal (lowercase)|
|`%X`|Unsigned hexadecimal (uppercase)|

## Relation with libft Project
The ft_printf function is included in the libft project, which is a library of useful functions that are used in later projects at 42.
You can find the libft project [here](https://github.com/Jkutkut/42Madrid-Libft).

## Conclusions
The ft_printf function is a powerful tool for printing formatted output to the standard output stream or a user-defined output stream.
This project has been added to the libft, which is a library of useful functions used in later projects at 42.
