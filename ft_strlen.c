/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:21:07 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/07 12:30:11 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size	ft_strlen(const char *str);

t_size	ft_strlen(const char *str)
{
	t_size	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
