/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:41:54 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/10 12:44:52 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, t_size len);

char	*ft_strnstr(const char *haystack, const char *needle, t_size len)
{
	t_size	i;
	t_size	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			while (needle[j] && i + j < len)
			{
				if (haystack[i + j] == needle[j])
					j++;
				else
					break ;
			}
			if (needle[j] == '\0')
				return ((char *) &haystack[i]);
		}
		i++;
	}
	return (0);
}
