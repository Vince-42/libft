#include "libft.h"
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

int main(void)
{
    int i;
    int j;
    // test strlen
    printf("*********** *********** strlen *********** ***********\n");
    // test strlen
    const char *strlen_str[] = {"un", "deux", "trois", "quatres", "RaNd0M T3s*t", "", ".", "encore 3 ramdom elements", " ", "12345", "lA5t"};
    for (i = 0; i < (sizeof(strlen_str) / sizeof(strlen_str[0])); i++)
    {
        if (ft_strlen(strlen_str[i]) != strlen(strlen_str[i]))
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_strlen test | '%i'     >> ... %zu\n", i, ft_strlen(strlen_str[i]));
            printf("strlen test    | '%i'     >> ... %zu\n", i, strlen(strlen_str[i]));
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("test %i ******* OK ******* no-diff \n", i);
    }
    // test isalfa
    printf("****** *********** isalpha *********** ******\n");
    for (i = 89; i < 99; i++)
    {

        if(ft_isalpha(i) != isalpha(i))
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_isalpha test | '%i'     >> ... %i\n", i, ft_isalpha(i));
            printf("isalpha test    | '%i'     >> ... %i\n", i, isalpha(i));
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("test %i ******* OK ******* no-diff \n", i);
    }
    // test isalnum
    printf("****** *********** isalnum *********** ******\n");
    for (i = 40; i < 50; i++)
    {

        if(ft_isalnum(i) != isalnum(i))
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_isalnum test | '%i'     >> ... %i\n", i, ft_isalnum(i));
            printf("isalnum test    | '%i'     >> ... %i\n", i, isalnum(i));
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("test %i ******* OK ******* no-diff \n", i);
    }
    // test isAscii
    printf("****** *********** isAscii *********** ******\n");
    for (i = 89; i < 99 ; i++)
    {

        if(ft_isascii(i) != isascii(i))
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_isascii test | '%i'     >> ... %i\n",i, ft_isascii(i));
            printf("isascii test    | '%i'     >> ... %i\n",i ,isascii(i));
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("test %i ******* OK ******* no-diff \n", i);
    }
    // test isdigit
    printf("****** *********** isdigit *********** ******\n");
    for (i = 40; i < 50 ; i++)
    {

        if(ft_isdigit(i) != isdigit(i))
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_isdigit test | '%i'     >> ... %i\n",i, ft_isdigit(i));
            printf("isdigit test    | '%i'     >> ... %i\n",i ,isdigit(i));
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("test %i ******* OK ******* no-diff \n", i);
    }
    // test isprint
    printf("****** *********** isprint *********** ******\n");
    for (i = 25; i < 35 ; i++)
    {

        if(ft_isprint(i) != isprint(i))
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_isprint test | '%i'     >> ... %i\n",i, ft_isprint(i));
            printf("isprint test    | '%i'     >> ... %i\n",i ,isprint(i));
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("test %i ******* OK ******* no-diff \n", i);
    }
    // test memset
    printf("****** *********** memset *********** ******\n");
    char    str_mem[6] = "hello";
    char    str_test[6] = "hello";
    int     arr_mem[6] = {1,2,3,4,5,6};
    int     arr_test[6] = {1,2,3,4,5,6};

    memset(str_mem, '0', 4);
    memset(arr_mem, 0, 16);
    
    ft_memset(str_test, '0', 4);
    ft_memset(arr_test, 0, 16);

    for (i = 0; i < 6; i++)
    {
        if (str_mem[i] != str_test[i])
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_memset test | '%i'     >> ... %c\n",i, str_mem[i]);
            printf("memset test    | '%i'     >> ... %c\n",i ,str_test[i]);
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("#1 memtest %i ******* OK ******* no-diff \n", i);
    }

    for (i = 0; i < 6; i++)
    {
        if (arr_mem[i] != arr_test[i])
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_memset test | '%i'     >> ... %i\n", i, arr_mem[i]);
            printf("memset test    | '%i'     >> ... %i\n", i, arr_test[i]);
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("#2 memtest %i ******* OK ******* no-diff \n", i);
    }
    // test bzero
    printf("*********** *********** bzero *********** ***********\n");
    char    bze_str[10] = "hello amy";
    int     bze_arr[10] = {1,2,3,4,5,6,7,8,9,10};

    char    bze_str_official[10] = "hello amy";
    int     bze_arr_official[10] = {1,2,3,4,5,6,7,8,9,10};

    ft_bzero(bze_str, 1);
    ft_bzero(bze_arr, 4);

    bzero(bze_str_official, 1);
    bzero(bze_arr_official, 4);
    // until 10 because after it is undefined behavior
    for (i = 0; i < 10; i++)
    {
        if (bze_str[i] != bze_str_official[i])
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_bzero test  | '%i'     >> ... %c\n", i, bze_str[i]);
            printf("bzero  test    | '%i'     >> ... %c\n", i, bze_str_official[i]);
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("#1 bzero str %i ******* OK ******* no-diff \n", i);
    }
    // until 10 because after it is undefined behavior
    for (i = 0; i < 10; i++)
    {
        if (bze_arr[i] != bze_arr_official[i])
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_bzero test2  | '%i'     >> ... %i\n", i, bze_arr[i]);
            printf("bzero  test2    | '%i'     >> ... %i\n", i, bze_arr_official[i]);
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("#2 bzero int %i ******* OK ******* no-diff \n", i);
    }
    // test memcpy
    printf("*********** *********** memcpy *********** ***********\n");
    char    memcpy_src_str[10] = "hello amy";
    char    memcpy_dst_str[20] = "xxxxxxxxx";
    char    memcpy_src_str_official[10] = "hello amy";
    char    memcpy_dst_str_official[20] = "pppppppppppp";

    int     memcpy_src_arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int     memcpy_dst_arr[20] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int     memcpy_src_arr_official[10] = {1,2,3,4,5,6,7,8,9,10};
    int     memcpy_dst_arr_official[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    ft_memcpy(memcpy_dst_str, memcpy_src_str, 10);
    memcpy(memcpy_dst_str_official, memcpy_src_str_official, 10);
    for (i = 0; i < 10 ; i++)
    {
        if (memcpy_dst_str[i] != memcpy_dst_str_official[i])
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_memcpy test     | '%i'     >> ... %c\n", i, memcpy_dst_str[i]);
            printf("memcpy  test       | '%i'     >> ... %c\n", i, memcpy_dst_str_official[i]);
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("#1 memcpy str %i ******* OK ******* no-diff \n", i);
    }
    ft_memcpy(memcpy_dst_arr, memcpy_src_arr, sizeof(memcpy_src_arr));
//    printf("should be 4 bytes * 10 elements >>> %lu\n", sizeof(memcpy_src_arr));
    memcpy(memcpy_dst_arr_official, memcpy_src_arr_official, sizeof(memcpy_src_arr_official));

    for (i = 0; i < 10 ; i++)
    {
        if (memcpy_dst_arr[i] != memcpy_dst_arr_official[i])
        {
            printf("************ ERROR ERROR ERROR ************\n");
            printf("ft_memcpy test arr | '%i'     >> ... %i\n", i, memcpy_dst_arr[i]);
            printf("memcpy  test  arr  | '%i'     >> ... %i\n", i, memcpy_dst_arr_official[i]);
            printf("************ ERROR ERROR ERROR ************\n");
        }
        else
            printf("#2 memcpy int %i ******* OK ******* no-diff \n", i);
    }
    // test memmove
    printf("*********** *********** memmove *********** ***********\n");


    for (i = 0; i <= 5 ; i++)
    {
        char    dst_memmove[10] = "abcdefgh";
        char    src_memmove[10] = "abcdefgh";
        memmove(dst_memmove + 3, dst_memmove + i, i);
        ft_memmove(src_memmove + 3, src_memmove + i, i);
        for (j = 0; j < 10; j++)
        {
            if(dst_memmove[j] != src_memmove[j])
            {
                printf("************ ERROR ERROR ERROR ************\n");
                printf("ft_memmove test arr | i='%i'  j='%i'     >> ... %i\n",i, j, src_memmove[j]);
                printf("memmove  test  arr  | i='%i'  j='%i'     >> ... %i\n",i, j, dst_memmove[j]);
                printf("************ ERROR ERROR ERROR ************\n");
            }
            else
                printf("#1 memmove i:%i j:%i ******* OK ******* no-diff \n", i, j);
        }
    }
}