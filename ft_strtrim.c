/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:48:17 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/12 20:00:29 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_checkin(char a, char const *str);
// return 0 if not found - nbr of occurences if found

static int	ft_checkin(char a, char const *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (a == str[i])
			res++;
		i++;
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		last;
	char	*new_strim;
	int		allocsize;


	if (!s1 || !set)
		return (NULL);
	i = 0;
	last = ft_strlen(s1) - 1;
	while (ft_checkin(s1[i], set))
		i++;
	if (s1[i] == '\0')
		return (ft_calloc(1,1));
	while (ft_checkin(s1[last], set))
		last--;
	allocsize = last - i + 1;
	new_strim = ft_substr(s1, i, allocsize);
	return (new_strim);
}
