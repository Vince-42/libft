/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:19:37 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/07 12:30:46 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, t_size n);

void	ft_bzero(void *s, t_size n)
{
	t_size			i;
	unsigned char	*bytes_ptr;
	unsigned char	bytes_value;

	bytes_ptr = (unsigned char *) s;
	bytes_value = 0;
	i = 0;
	while (i < n)
	{
		bytes_ptr[i] = bytes_value;
		i++;
	}
}
