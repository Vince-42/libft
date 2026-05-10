/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:29:26 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/10 12:30:39 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, t_size n);

void	*ft_memchr(const void *s, int c, t_size n)
{
	unsigned char	byte_value;
	unsigned char	*bytes_ptr;
	t_size			i;

	i = 0;
	byte_value = (unsigned char) c;
	bytes_ptr = (unsigned char *) s;
	while (i < n)
	{
		if (bytes_ptr[i] == byte_value)
		{
			return (&bytes_ptr[i]);
		}
		i++;
	}
	return (0);
}
