/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 13:08:43 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/10 13:12:19 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	unsigned char	byte_value;
	int				search_size;
	int				i;

	search_size = ft_strlen(s) + 1;
	byte_value = (unsigned char) c;
	i = 0;
	while (i < search_size)
	{
		if (s[i] == byte_value)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
