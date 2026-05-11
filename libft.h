/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vleroy <vleroy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:22:40 by vleroy            #+#    #+#             */
/*   Updated: 2026/05/10 14:32:37 by vleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

typedef unsigned long	t_size;

typedef struct s_list
{
    void    *content;
    struct s_list *next;
} t_list;

t_list  *ft_lstnew(void *content);
void    ft_lstadd_front(t_list **lst, t_list *new);

t_size	ft_strlen(const char *str);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memset(void *b, int c, t_size len);
void	ft_bzero(void *s, t_size n);
void	*ft_memcpy(void *dst, const void *src, t_size n);
void	*ft_memmove(void *dst, const void *src, t_size len);
t_size	ft_strlcat(char *dst, const char *src, t_size dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, t_size n);
void	*ft_memchr(const void *s, int c, t_size n);
int		ft_memcmp(const void *s1, const void *s2, t_size n);
char	*ft_strnstr(const char *haystack, const char *needle, t_size len);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_calloc(t_size count, t_size size);
int		ft_atoi(const char *str);
t_size	ft_strlcpy(char *dst, const char *src, t_size size);
/**
* Allocates memory (using malloc(3)) and returns a
* substring from the string ’s’.
* The substring starts at index ’start’ and has a
* maximum length of ’len’.
*/
char    *ft_substr(char const *s, unsigned int start, t_size len);
/**
 * Allocates memory (using malloc(3)) and returns a
 * new string, which is the result of concatenating
 * 's1' and 's2'
 *  @param s1 char const
 *  @param s2 char const
 */
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * Allocates memory (using malloc(3)) and returns a
 * copy of ’s1’ with characters from ’set’ removed
 * from the beginning and the end.
 * @param s1 The string to be trimmed.
 * @param set The string containing the set of characters
 * to be removed.
 */
char	*ft_strtrim(char const *s1, char const *set);
/**
 * Allocates memory (using malloc(3)) and returns an
 * array of strings obtained by splitting ’s’ using
 * the character ’c’ as a delimiter.
 * Each string in the returned array is allocated
 * independently.
 * The array of pointers itself is also allocated
 * dynamically.
 * The returned array must be NULL terminated.
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split.
 * @return NULL if any allocation fails.
 */
char	**ft_split(char const *s, char c);
char    *ft_itoa(int n);
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void    ft_striteri(char *s, void (*f)(unsigned int, char*));
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putendl_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);


#endif
