/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcheron <pcheron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 01:06:29 by pcheron           #+#    #+#             */
/*   Updated: 2023/04/25 01:06:33 by pcheron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RARB 1
# define RRARB 2
# define RARRB 3
# define RRARRB 4

typedef struct s_stack
{
    int nbr;
    int index;
    t_stack *next;
}   t_stack;

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

#endif