/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:59:07 by pcheron           #+#    #+#             */
/*   Updated: 2023/04/25 20:10:21 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_combo_rarb(int ind_a, int ind_b, t_stack *lsta, t_stack *lstb)
{
	while (ind_a > 0 && ind_b > 0)
	{
		write(1, "rr\n", 3);
		ft_rotate(lsta);
		ft_rotate(lstb);
		ind_a--;
		ind_b--;
	}
	while (ind_a > 0)
	{
		write(1, "ra\n", 3);
		ft_rotate(lsta);
		ind_a--;
	}
	while (ind_b > 0)
	{
		write(1, "rb\n", 3);
		ft_rotate(lstb);
		ind_b--;
	}
	write(1, "pa\n", 3);
	ft_push(lstb, lsta);
}

void	ft_combo_rrarb(int ind_a, int ind_b, t_stack *lsta, t_stack *lstb)
{
	int	size_stack_a;

	size_stack_a = ft_stacklast(lsta)->index;
	while (ind_a <= size_stack_a)
	{
		write(1, "rra\n", 4);
		ft_r_rotate(lsta);
		ind_a++;
	}
	while (ind_b > 0)
	{
		write(1, "rb\n", 3);
		ft_rotate(lstb);
		ind_b--;
	}
	write(1, "pa\n", 3);
	ft_push(lstb, lsta);
}

void	ft_combo_rarrb(int ind_a, int ind_b, t_stack *lsta, t_stack *lstb)
{
	int	size_stack_b;

	size_stack_b = ft_stacklast(lstb)->index;
	while (ind_b <= size_stack_b)
	{
		write(1, "rrb\n", 4);
		ft_r_rotate(lstb);
		ind_b++;
	}
	while (ind_a > 0)
	{
		write(1, "ra\n", 3);
		ft_rotate(lsta);
		ind_a--;
	}
	write(1, "pa\n", 3);
	ft_push(lstb, lsta);
}

void	ft_combo_rrarrb(int ind_a, int ind_b, t_stack *lsta, t_stack *lstb)
{
	int	size_stack_a;
	int	size_stack_b;

	size_stack_a = ft_stacklast(lsta)->index;
	size_stack_b = ft_stacklast(lstb)->index;
	while (ind_a <= size_stack_a && ind_b <= size_stack_b)
	{
		write(1, "rrr\n", 4);
		ft_r_rotate(lsta);
		ft_r_rotate(lstb);
		ind_a++;
		ind_b++;
	}
	while (ind_a <= size_stack_a)
		(write(1, "rra\n", 4), ft_r_rotate(lsta), ind_a++);
	while (ind_b <= size_stack_b)
		(write(1, "rrb\n", 4), ft_r_rotate(lstb), ind_b++);
	write(1, "pa\n", 3);
	ft_push(lstb, lsta);
}
