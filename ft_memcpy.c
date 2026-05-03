#include "libft.h"

void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    unsigned char *dst_bytes_ptr;
    const unsigned char *src_bytes_ptr;
    size_t i;

    i = 0;
    dst_bytes_ptr = (unsigned char*) dst;
    src_bytes_ptr = (const unsigned char*) src;
    while (i < n)
    {
        dst_bytes_ptr[i] = src_bytes_ptr[i];
        i++;
    }
    return (dst);
}