#include "libft.h"
#include <stdlib.h>

t_list *ft_lstnew(void *content);

t_list *ft_lstnew(void *content)
{
    t_list *new_list;

    new_list = malloc(sizeof(content));
    new_list->next = NULL;
    new_list->content = content;
    return (new_list);
}