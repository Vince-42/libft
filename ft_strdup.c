/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:35:42 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/10 12:36:17 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *src);

char	*ft_strdup(char *src)
{
	int		str_size;
	int		i;
	char	*new_str;

	i = 0;
	str_size = ft_strlen(src);
	new_str = malloc(sizeof(char) * str_size + 1);
	while (src[i])
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
