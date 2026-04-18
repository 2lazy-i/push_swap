/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:59:13 by mapatenk          #+#    #+#             */
/*   Updated: 2025/08/20 21:03:34 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(int *a, int *size_a)
{
	int	temp;

	if (*size_a < 2)
		return ;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(int *b, int *size_b)
{
	int	temp;

	if (*size_b < 2)
		return ;
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(int *a, int *b, int *size_a, int *size_b)
{
	int	temp;

	if (*size_a < 2 || *size_b < 2)
		return ;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
	write(1, "ss\n", 3);
}

void	pa(int *a, int *b, int *size_a, int *size_b)
{
	int	i;

	if (*size_b == 0)
		return ;
	i = *size_a;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (i < *size_b - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	(*size_a)++;
	(*size_b)--;
	write(1, "pa\n", 3);
}

void	pb(int *a, int *b, int *size_a, int *size_b)
{
	int	i;

	if (*size_a == 0)
		return ;
	i = *size_b;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = a[0];
	i = 0;
	while (i < *size_a - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	(*size_b)++;
	(*size_a)--;
	write(1, "pb\n", 3);
}
