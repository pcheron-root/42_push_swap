
#include "../include/push_swap.h"

void    ft_set_index(t_lst *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        lst->index = i;
        lst = lst->next;
        i++;
    }
}

void    ft_push(t_lst **lst_src, t_lst **lst_dest)
{
    t_lst   *tmp;

    tmp = *lst_src;
    *lst_src = (*lst_src)->next;
    tmp->next = *lst_dest;
    *lst_dest = tmp;
    ft_set_index(lst_dest);
    ft_set_index(lst_src);
}
