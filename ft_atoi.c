/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 12:00:29 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/10 13:04:52 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str);

static int	check_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else 
			break ;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	is_neg;
	int	i;

	res = 0;
	is_neg = 1;
	i = check_space(str);
	if (str[i] == '-')
	{
		is_neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = 10 * res + (str[i] - '0');
		}
		else
			break ;
		i++;
	}
	return (res * is_neg);
}
