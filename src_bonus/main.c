/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:47:07 by pcheron           #+#    #+#             */
/*   Updated: 2023/05/10 15:30:53 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.c"

bool	ft_(t_stack *stack_a, t_stack *stack_b)
{
	char	*str;

	str = "jusqu'ici tout va bien";
	while (str)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (ft_(str, stack_a, stack_b))
		{
			free(str);
			ft_stackclear(stack_a);
			ft_stackclear(stack_b);
			write(2, "Error\n", 6);
			return (false);
		}
		free(str);
	}
	if (ft_is_solved(stack_a, stack_b))
		return (write(1, "OK\n", 3), false);
	ft_stackclear(stack_a);
	ft_stackclear(stack_b);
	return (write(1, "KO\n", 3), true);
}

bool	ft_is_solved(t_stack *stack_a, t_stack *stack_b)
{
	int	ind_min;

	if (stack_b)
		return (ft_stackclear(&stack_b), false);
	if (!ft_is_sorted(t_stack *stack_a))
		return (false);
	ind_min = ft_find_min(stack_a)->ind;
	if (inf_min)
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*new;
	int		nbr;
	int		i;

	i = 0;
	nbr = 0;
	stack_a = NULL;
	stack_b = NULL;
	while (argv[++i])
	{
		if (!ft_atoi(&nbr, argv[i]))
			return (ft_stackclear(&stack_a), EXIT_FAILURE);
		new = ft_stacknew(nbr);
		if (!new || ft_is_duplicate(stack_a, nbr))
			return (ft_stackclear(&stack_a), EXIT_FAILURE);
		ft_stackadd_back(&stack_a, new);
	}
	return (0);
}
