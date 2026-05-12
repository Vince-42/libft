/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:54:31 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/12 17:30:12 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char		*ft_substr(char const *s, unsigned int start, t_size len);

static int	ft_returnalloc(t_size size_str, unsigned int start, t_size len);

static int	ft_returnalloc(t_size size_str, unsigned int start, t_size len)
{
	t_size	alloc_size;

	if (start < size_str)
	{
		if (len >= size_str)
			alloc_size = size_str - start + 1;
		else
			alloc_size = len + 1;
	}
	else
		alloc_size = 1;
	return (alloc_size);
}

char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	t_size	size_str;
	t_size	i;
	char	*new_substr;
	t_size	alloc_size;

	size_str = ft_strlen(s);
	alloc_size = ft_returnalloc(size_str, start, len);
	i = 0;
	new_substr = malloc(alloc_size);
	if (new_substr == NULL)
		return (NULL);
	while (i < len && (start + i) < size_str)
	{
		new_substr[i] = s[start + i];
		i++;
	}
	new_substr[i] = '\0';
	return (new_substr);
}
