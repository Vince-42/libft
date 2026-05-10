/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:45:44 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/10 12:47:15 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	byte_value;
	t_size			search_size;

	search_size = ft_strlen(s);
	byte_value = (unsigned char) c;
	while (1)
	{
		if (s[search_size] == byte_value)
			return ((char *)&s[search_size]);
		if (search_size == 0)
			break ;
		search_size--;
	}
	return (0);
}
