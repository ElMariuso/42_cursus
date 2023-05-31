/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:32:23 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/03 16:26:50 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	bool			is_simplified;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;
void	error(char	*message);
bool	is_correct(char	**splitted_stack);
bool	is_sorted(t_stack	*stack);
t_stack	*ft_stacklast(t_stack	*stack);
int		stack_size(t_stack	*stack);
void	ft_update_indexs(t_stack	*stack);

t_stack	*init_stack(int argc, char	**argv, t_stack	*stack_a);
void	ft_simplification(t_stack	*stack);

void	ft_sa_sb_ss(t_stack	*stack_a, t_stack	*stack_b, char command);
void	ft_ra_rb_rr(t_stack	*stack_a, t_stack	*stack_b, char command);
void	ft_rra_rrb_rrr(t_stack	*stack_a, t_stack	*stack_b, char command);
void	ft_pa_pb(t_stack	**stack_a, t_stack	**stack_b, char command);
void	short_sort(t_stack	**stack_a, t_stack	**stack_b);
void	sort(t_stack	**stack_a, t_stack	**stack_b);

void	free_all_array(char	**splitted_stack);
void	free_stack(t_stack	*stack);
void	free_all_stacks(t_stack	*stack_a, t_stack	*stack_b);
void	free_array_and_error(char	**splitted_stack);
void	free_stack_and_error(t_stack	*stack);
#endif
