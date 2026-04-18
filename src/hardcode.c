/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:55:59 by mapatenk          #+#    #+#             */
/*   Updated: 2025/08/20 19:58:32 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort3(int *a, int *size_a)
{
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		sa(a, size_a);
	else if (a[0] > a[1] && a[1] > a[2])
	{
		sa(a, size_a);
		rra(a, size_a);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		ra(a, size_a);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		sa(a, size_a);
		ra(a, size_a);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		rra(a, size_a);
}

void	sort4(int *a, int *b, int *size_a, int *size_b)
{
	while (a[0] != 0)
		ra(a, size_a);
	pb(a, b, size_a, size_b);
	sort3(a, size_a);
	pa(a, b, size_a, size_b);
}

void	sort5(int *a, int *b, int *size_a, int *size_b)
{
	while (a[0] != 0 && a[0] != 1)
		ra(a, size_a);
	pb(a, b, size_a, size_b);
	while (a[0] != 0 && a[0] != 1)
		ra(a, size_a);
	pb(a, b, size_a, size_b);
	sort3(a, size_a);
	if (b[0] < b[1])
		sb(b, size_b);
	pa(a, b, size_a, size_b);
	pa(a, b, size_a, size_b);
}

void	sort(int *a, int *b, int *size_a, int *size_b)
{
	if (is_sorted(a, *size_a))
		return ;
	if (*size_a == 2)
	{
		sa(a, size_a);
		return ;
	}
	else if (*size_a == 3)
		sort3(a, size_a);
	else if (*size_a == 4)
		sort4(a, b, size_a, size_b);
	else if (*size_a == 5)
		sort5(a, b, size_a, size_b);
	else
		radix(a, b, size_a, size_b);
}

bool	is_sorted(int *a, int size_a)
{
	int	i;

	i = 0;
	while (i < size_a - 1)
	{
		if (a[i] > a[i + 1])
			return (false);
		i++;
	}
	return (true);
}
