/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:08:11 by mapatenk          #+#    #+#             */
/*   Updated: 2025/08/20 21:01:59 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

int		*allocate_arrays(int argc, int **b);
void	parse_arguments(int *a, int size_a, char **argv);
long	ft_atol(const char *str);
bool	is_valid_number(char *str);
bool	validate_args(int argc, char **argv);
int		get_smallest_number_index(int *nums, int size, bool *is_normalized);
int		normalize(int *a, int size_a);
bool	is_sorted(int *a, int size_a);
void	radix(int *a, int *b, int *size_a, int *size_b);
void	sa(int *a, int *size_a);
void	sb(int *b, int *size_b);
void	ss(int *a, int *b, int *size_a, int *size_b);
void	pa(int *a, int *b, int *size_a, int *size_b);
void	pb(int *a, int *b, int *size_a, int *size_b);
void	ra(int *a, int *size_a);
void	rb(int *b, int *size_b);
void	rr(int *a, int *b, int *size_a, int *size_b);
void	rra(int *a, int *size_a);
void	rrb(int *b, int *size_b);
void	rrr(int *a, int *b, int *size_a, int *size_b);
void	sort(int *a, int *b, int *size_a, int *size_b);
void	sort3(int *a, int *size_a);
void	sort4(int *a, int *b, int *size_a, int *size_b);
void	sort5(int *a, int *b, int *size_a, int *size_b);

#endif