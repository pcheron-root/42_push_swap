/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 01:02:45 by pcheron           #+#    #+#             */
/*   Updated: 2023/05/10 16:17:53 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_min(int x, int y)
{
	return (x * (x < y) + y * (x >= y));
}

int	ft_max(int x, int y)
{
	return (x * (x > y) + y * (x <= y));
}

void	ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

bool	ft_atoi(int *result, char *str)
{
	int	sign;

	sign = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		*str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		*str++;
		if (!*str)
			return (false);
	}
	*result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (*result > *result * 10 - 48 + *str && !(*result == INT_MAX / 10
				&& *str == '8' && !str[1] && sign < 0))
			return (false);
		*result = *result * 10 - 48 + *str;
		*str++;
	}
	if (*str)
		return (false);
	return (*result *= sign, true);
}
