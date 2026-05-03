#include "libft.h"

void    *ft_memset(void *b, int c, size_t len);

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char   bytes_value;
    unsigned char   *bytes_ptr;
    size_t i;

    bytes_value = (unsigned char) c;
    bytes_ptr = (unsigned char*) b;

    i = 0;
    while (i < len)
    {
        bytes_ptr[i] = bytes_value;
        i++;
    }
    return (b);
}