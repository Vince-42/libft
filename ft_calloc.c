/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:25:37 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/12 16:59:25 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

void	*ft_calloc(t_size count, t_size size);

void	*ft_calloc(t_size count, t_size size)
{
	unsigned char	*new_byte_adr;
	t_size			allocation_total;
	t_size			i;

	i = 0;
	if (size != 0)
	{
		if ((count > (t_size) INT_MAX / size))
			return (NULL);
		if ((count > (t_size) - 1 / size))
			return (NULL);
	}
	allocation_total = count * size;
	new_byte_adr = malloc(allocation_total);
	if (new_byte_adr == NULL)
		return (NULL);
	while (i < allocation_total)
	{
		new_byte_adr[i] = 0;
		i++;
	}
	return (new_byte_adr);
}
