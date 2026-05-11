/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:11:34 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/10 16:11:36 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** Allocates memory (using malloc(3)) and returns
a string representing the integer received as an
argument. Negative numbers must be handled.
*/
char    *ft_itoa(int n);

static void    ft_reverse(char *str);

static int ft_isneg(int n);

static int ft_isneg(int n)
{
    if (n < 0)
        return (1);
    else
        return (0);
}

static void    ft_reverse(char *str)
{
    char temp;
    int start;
    int last;

    start = 0;
    last = ft_strlen(str);

    while(start < last / 2)
    {
        temp = str[start];
        str[start] = str[last - start - 1];
        str[last - start - 1] = temp;
        start++;
    }
}

char    *ft_itoa(int n)
{
    int i;
    long number;
    char *str;
    char res;

    i = 0;
    number = n;
    str = ft_calloc(10, sizeof(char));
    if (number < 0)
        number *= -1;
    else if (number == 0)
        str[i] = '0';
    while (number > 0)
    {
        res = number % 10 + '0';
        number = number / 10;
        str[i++] = res;
    }
    if (ft_isneg(n) == 1)
        str[i] = '-';
    ft_reverse(str);
    return (str);
}