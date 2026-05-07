/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:13:06 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/07 12:30:32 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, t_size len);

void	*ft_memset(void *b, int c, t_size len)
{
	unsigned char	bytes_value;
	unsigned char	*bytes_ptr;
	t_size			i;

	bytes_value = (unsigned char) c;
	bytes_ptr = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		bytes_ptr[i] = bytes_value;
		i++;
	}
	return (b);
}
