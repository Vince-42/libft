/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:22:40 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/07 12:26:07 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

typedef unsigned long	t_size;

t_size	ft_strlen(const char *str);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memset(void *b, int c, t_size len);
void	ft_bzero(void *s, t_size n);
void	*ft_memcpy(void *restrict dst, const void *restrict src, t_size n);
void	*ft_memmove(void *dst, const void *src, t_size len);

#endif
