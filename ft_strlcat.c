/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 14:19:32 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/10 12:22:12 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size	ft_strlcat(char *dst, const char *src, t_size dstsize);

t_size	ft_strlcat(char *dst, const char *src, t_size dstsize)
{
	t_size	i;
	t_size	dst_originalsize;
	t_size	src_originalsize;
	t_size	fill_size;

	dst_originalsize = ft_strlen(dst);
	src_originalsize = ft_strlen(src);
	fill_size = dstsize - dst_originalsize - 1;
	i = 0;
	if (src == 0)
		return (dst_originalsize);
	if (dst_originalsize >= dstsize)
		return (src_originalsize + dstsize);
	while (src[i] && i < fill_size)
	{
		dst[dst_originalsize + i] = src[i];
		i++;
	}
	if (dstsize > 0 || dst_originalsize <= dstsize)
		dst[dst_originalsize + i] = '\0';
	return (dst_originalsize + src_originalsize);
}
