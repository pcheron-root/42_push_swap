/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 01:02:45 by pcheron           #+#    #+#             */
/*   Updated: 2023/04/25 01:02:48 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int ft_min(int x, int y)
{
    return (x * (x < y) + y * (x >= y));
}

int ft_max(int x, int y)
{
    return (x * (x > y) + y * (x <= y));
}

void    ft_free(void **ptr)
{
    if (*ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
}

bool    ft_atoi(int *result, char *str)
{
    int i;
    int sign;

    sign = 1;
    i = 0;
    while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    *result = 0;
    while (str[i] >='0' && str[i] <= '9')
    {
        if (*result > *result * 10 + str[i] - 48)
            return (false);
        *result = *result * 10 + str[i] - 48;
        i++;
    }
    if (str[i] || (*result == INT_MAX && sign < 0))
        return (false);
    *result *= sign;
    return (true);
}
