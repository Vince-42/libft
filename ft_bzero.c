#include "libft.h"

void    ft_bzero(void *s, size_t n);

void    ft_bzero(void *s, size_t n)
{
    size_t  i;
    unsigned char *bytes_ptr;
    unsigned char bytes_value;

    bytes_ptr = (unsigned char*) s;
    bytes_value = 0;

    i = 0;
    while (i < n)
    {
        bytes_ptr[i] = bytes_value;
        i++;
    }
}