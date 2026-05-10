/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:37:18 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/10 12:38:25 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	t_size	i;
	t_size	j;

	i = 0;
	j = 0;
	new_str = malloc(ft_strlen(s1)+ft_strlen(s2) + 1);
	if (new_str == NULL)
		return (0);
	while (i < ft_strlen(s1))
	{
		new_str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}
