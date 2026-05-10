/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:48:17 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/10 12:53:33 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_checkin(char a, char const *str);
// alloc string
static char	*ft_alloc(char const *s1, char const *set);
// helper function to return count of s1[i] in set
static int	ft_returncount(char const *str, char const *set);
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

static int	ft_returncount(char const *str, char const *set)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i] == set[j])
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static char	*ft_alloc(char const *s1, char const *set)
{
	int		count;
	int		total_allocation;
	char	*new_str;

	count = ft_returncount(s1, set);
	total_allocation = ft_strlen(s1) - count;
	new_str = malloc(total_allocation + 1);
	if (new_str == NULL)
		return (NULL);
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		last;
	char	*new_strim;
	int		buf;

	i = 0;
	last = ft_strlen(s1);
	buf = 0;
	if (!s1 || !set)
		return (0);
	new_strim = ft_alloc(s1, set);
	while (ft_checkin(s1[i], set))
		i++;
	while (ft_checkin(s1[last - 1], set))
		last--;
	while (i < last)
	{
		new_strim[buf] = s1[i];
		buf++;
		i++;
	}
	new_strim[buf] = '\0';
	return (new_strim);
}
