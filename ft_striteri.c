/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:12:45 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/12 16:09:56 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
s: The string to iterate over.
f: The function to apply to each character.
Return 
    Value None
Description 
    Applies the function ’f’ to each character of the
    string passed as argument, passing its index as
    the first argument. Each character is passed by
    address to ’f’ so it can be modified if necessary.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	str_totalsize;
	char			*new_str;
	unsigned int	i;

	i = 0;
	str_totalsize = ft_strlen(s);
	new_str = s;
	while (i < str_totalsize)
	{
		f(i, &s[i]);
		new_str[i] = s[i];
		i++;
	}
}
