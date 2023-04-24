
#include "../include/push_swap.h"

t_lst   *ft_lstnew(int nbr)
{
    t_lst   *new;

    new = malloc(sizeof(t_lst));
    if (!new)
        return (NULL);
    new->nbr = nbr;
    new->index = 0;
    new->next = NULL;
}

t_lst   *ft_lstlast(t_lst *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

void    ft_lstadd_back(t_lst **lst, t_lst *new)
{
    if (!lst)
        *lst = new;
    else
    {
        ft_lstlast(*lst)->next = new;
    }
}

void    ft_lstadd_front(t_lst **lst, t_lst *new)
{
    if (!new)
        return ;
    new->next = *lst;
    if (!*lst)
        return ;
    *lst = new;
}

void    ft_lstfree(t_list **lst)
{
    t_lst *tmp;

    while (*lst)
    {
        tmp = (*lst)->next;
        ft_free(lst);
        *lst = tmp;
    }
    *lst = NULL;
}
