/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:22:32 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/07 17:10:52 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, t_size n);

void	*ft_memcpy(void *dst, const void *src, t_size n)
{
	unsigned char		*dst_bytes_ptr;
	const unsigned char	*src_bytes_ptr;
	t_size				i;

	i = 0;
	dst_bytes_ptr = (unsigned char *) dst;
	src_bytes_ptr = (const unsigned char *) src;
	while (i < n)
	{
		dst_bytes_ptr[i] = src_bytes_ptr[i];
		i++;
	}
	return (dst);
}
