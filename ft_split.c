/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 13:06:03 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/10 16:03:41 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_split(char const *s, char c);

static int	ft_countwords(char const *s, char c);

static void	*ft_free(char **tab, int count);

static char	*ft_fill(const char *s, int start, int end);

static char	*ft_fill(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start +1) * sizeof(char));
	if (!word)
		return (0);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **tab, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	ft_countwords(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	if (!s)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			words++;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (words);
}

static void	ft_gaintwoline(t_size *i, t_size *j, int *start)
{
	*i = 0;
	*j = 0;
	*start = -1;
}

char	**ft_split(char const *s, char c)
{
	t_size	i;
	t_size	j;
	int		start;
	char	**tab;

	tab = ft_calloc((ft_countwords(s, c) + 1), sizeof(char *));
	if (!tab)
		return (0);
	ft_gaintwoline(&i, &j, &start);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			tab[j] = ft_fill(s, start, i);
			if (!(tab [j]))
				return (ft_free(tab, j));
			start = -1;
			j++;
		}
		i++;
	}
	return (tab);
}
