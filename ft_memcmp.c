/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:31:21 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/10 12:32:42 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, t_size n);

int	ft_memcmp(const void *s1, const void *s2, t_size n)
{
	unsigned char	*byte_s1_ptr;
	unsigned char	*byte_s2_ptr;
	t_size			i;

	byte_s1_ptr = (unsigned char *)s1;
	byte_s2_ptr = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (byte_s1_ptr[i] != byte_s2_ptr[i])
			return (byte_s1_ptr[i] - byte_s2_ptr[i]);
		i++;
	}
	return (0);
}
