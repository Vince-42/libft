 #include "libft.h"

 void   *ft_memmove(void *dst, const void *src, size_t len);

 void   *ft_memmove(void *dst, const void *src, size_t len)
 {
    const unsigned char *bytes_src_ptr;
    unsigned char       *bytes_dst_ptr;
    size_t              i;

    bytes_src_ptr = (const unsigned char*) src;
    bytes_dst_ptr = (unsigned char*) dst;
    i = 0;

    if (bytes_dst_ptr > bytes_src_ptr)
    {
        while (len)
        {
            bytes_dst_ptr[len - 1] = bytes_src_ptr[len - 1];
            len--;
        }
    }
    else if (bytes_dst_ptr < bytes_src_ptr)
    {
        while (i < len)
        {
            bytes_dst_ptr[i] = bytes_src_ptr[i];
            i++;
        }
    }
    return (dst);
 }