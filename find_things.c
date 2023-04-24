
#include "../include/push_swap.h"

t_lst *ft_find_min(*lst)
{
    t_lst *min;

    min = lst;
    while (lst)
    {
        if (lst->nbr < min->nbr)
            min = lst;
        lst = lst->next;
    }
    return (min);
}

t_lst   *ft_find_max(*lst)
{
    int max;

    max = lst;
    while (lst)
    {
        if (lst->nbr > max->nbr)
            max = lst;
        lst = lst->next;
    }
    return (max);
}

int ft_find_big_brother(*lst, int nbr)
{
    int big_bro;
    int index;
    
    if (nbr > ft_find_max(lst)->nbr)
        return (ft_find_min(lst)->index);
    big_bro = INT_MAX;
    index = 0;
    while (lst)
    {
        if (lst->nbr > nbr && lst->nbr <= INT_MAX)
        {
            index = lst->index;
            big_bro = lst->nbr; 
        }
        lst = lst->next;
    }
    return (index);
}

int ft_find_best_combo(t_lst *lsta, t_lst *lstb, int ind_big_bro, int ind_lil_bro)
{
    int rarb;
    int rrarrb;
    int rarrb;
    int rrarb;
    
    rarb = ft_max(ind_big_bro, ind_lil_bro);
    rrarrb = ft_max(ft_find_max(lsta)->index - ind_big_bro, ft_find_max(lstb)->index - ind_lil_bro) + 1;
    rarrb = ft_max(ind_big_bro , ft_find_max(lstb)->index - ind_lil_bro + 1);
    rrarb = ft_max(ind_lil_bro , ft_find_max(lsta)->index - ind_big_bro + 1);
    if (rarb <= rrarb && rarb <= rrarrb && rarb <= rarrb)
        return ();
    if (rrarrb <= rarb && rrarrb <= rrarb && rrarrb <= rarrb)
        return ();
    if (rarrb <= rarb && rarrb <= rrarrb && rarrb <= rrarb)
        return ();
    return ();
}
