/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:12:02 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/12 18:53:58 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
Parameters
s: The string to iterate over.
f: The function to apply to each character.

Returns 
    The string created from the successive applications
    of ’f’.
Returns 
    NULL if the allocation fails.

Description
Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to store the
results from the successive applications of f.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	str_size;
	unsigned int	i;
	char			*new_str;

	i = 0;
	str_size = ft_strlen(s);
	new_str = malloc(sizeof(char) * str_size + 1);
	if (!new_str)
		return (NULL);
	while (i < str_size)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
