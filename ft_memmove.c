/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:04:50 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/07 12:32:54 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, t_size len);

void	*ft_memmove(void *dst, const void *src, t_size len)
{
	unsigned char		*bytes_dst_ptr;
	const unsigned char	*bytes_src_ptr;
	t_size				i;

	bytes_src_ptr = (const unsigned char *) src;
	bytes_dst_ptr = (unsigned char *) dst;
	i = 0;
	if (bytes_dst_ptr > bytes_src_ptr)
	{
		while (len)
		{
			bytes_dst_ptr[len - 1] = bytes_src_ptr[len - 1];
			len--;
		}
	}
	else if (bytes_dst_ptr < bytes_src_ptr)
	{
		while (i < len)
		{
			bytes_dst_ptr[i] = bytes_src_ptr[i];
			i++;
		}
	}
	return (dst);
}
