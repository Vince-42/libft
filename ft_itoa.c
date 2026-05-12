/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:11:34 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/12 20:30:34 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/** Allocates memory (using malloc(3)) and returns
a string representing the integer received as an
argument. Negative numbers must be handled.
*/
char		*ft_itoa(int n);

static void	ft_reverse(char *str);

static int	ft_intlen(long n);

static int	ft_isneg(int n);

static int	ft_isneg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static void	ft_reverse(char *str)
{
	char	temp;
	int		start;
	int		last;

	start = 0;
	last = ft_strlen(str);
	while (start < last / 2)
	{
		temp = str[start];
		str[start] = str[last - start - 1];
		str[last - start - 1] = temp;
		start++;
	}
}

static int	ft_intlen(long n)
{
	int		count;
	long	calc;

	count = 0;
	calc = n;
	if (n == 0)
		return (1);
	while (calc > 0)
	{
		count = count + 1;
		calc = calc / 10;
	}
	return (count);
}

static void	ft_write(long number, char *str, int i, int n)
{
	char	res;

	while (number > 0)
	{
		res = number % 10 + '0';
		number = number / 10;
		str[i++] = res;
	}
	if (ft_isneg(n) == 1)
		str[i++] = '-';
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	int		i;
	long	number;
	char	*str;

	i = 0;
	number = n;
	if (number < 0)
		number *= -1;
	if (ft_isneg(n) == 1)
		str = malloc(sizeof(char) * ft_intlen(number) + 2);
	else
		str = malloc(sizeof(char) * ft_intlen(number) + 1);
	if (number == 0)
		str[i++] = '0';
	ft_write(number, str, i, n);
	ft_reverse(str);
	return (str);
}
