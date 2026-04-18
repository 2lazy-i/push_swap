/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:59:45 by mapatenk          #+#    #+#             */
/*   Updated: 2025/08/20 21:05:02 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(int *a, int *size_a)
{
	int	i;
	int	temp;

	if (*size_a < 2)
		return ;
	temp = a[0];
	i = 0;
	while (i < *size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[*size_a - 1] = temp;
	write(1, "ra\n", 3);
}

void	rb(int *b, int *size_b)
{
	int	i;
	int	temp;

	if (*size_b < 2)
		return ;
	temp = b[0];
	i = 0;
	while (i < *size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[*size_b - 1] = temp;
	write(1, "rb\n", 3);
}

void	rr(int *a, int *b, int *size_a, int *size_b)
{
	int	i;
	int	temp;

	if (*size_a < 2 || *size_b < 2)
		return ;
	temp = a[0];
	i = 0;
	while (i < *size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[*size_a - 1] = temp;
	temp = b[0];
	i = 0;
	while (i < *size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[*size_b - 1] = temp;
	write(1, "rr\n", 3);
}

void	rra(int *a, int *size_a)
{
	int	i;
	int	temp;

	if (*size_a < 2)
		return ;
	temp = a[*size_a - 1];
	i = *size_a - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	write(1, "rra\n", 4);
}

void	rrb(int *b, int *size_b)
{
	int	i;
	int	temp;

	if (*size_b < 2)
		return ;
	temp = b[*size_b - 1];
	i = *size_b - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	write(1, "rrb\n", 4);
}
