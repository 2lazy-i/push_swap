/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:59:51 by mapatenk          #+#    #+#             */
/*   Updated: 2025/08/21 17:32:15 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix(int *a, int *b, int *size_a, int *size_b)
{
	int	bit;
	int	i;
	int	n;

	bit = 0b1;
	i = 0;
	while (i < 32)
	{
		n = 0;
		while (n < *size_a + *size_b)
		{
			if (a[0] & bit)
				ra(a, size_a);
			else
				pb(a, b, size_a, size_b);
			n++;
		}
		while (*size_b > 0)
			pa(a, b, size_a, size_b);
		bit <<= 1;
		i++;
		if (is_sorted(a, *size_a))
			break ;
	}
}

int	normalize(int *a, int size_a)
{
	bool	*is_normalized;
	int		smallest_index;
	int		i;

	is_normalized = ft_calloc(size_a, sizeof(bool));
	if (!is_normalized)
		return (0);
	i = 0;
	while (i < size_a)
	{
		smallest_index = get_smallest_number_index(a, size_a, is_normalized);
		a[smallest_index] = i;
		is_normalized[smallest_index] = true;
		i++;
	}
	free(is_normalized);
	return (1);
}

int	get_smallest_number_index(int *nums, int size, bool *is_normalized)
{
	int	smallest_value;
	int	smallest_index;
	int	i;

	smallest_value = INT_MAX;
	smallest_index = 0;
	i = 0;
	while (i < size)
	{
		if (!is_normalized[i] && nums[i] <= smallest_value)
		{
			smallest_value = nums[i];
			smallest_index = i;
		}
		i++;
	}
	return (smallest_index);
}

void	rrr(int *a, int *b, int *size_a, int *size_b)
{
	int	i;
	int	temp;

	if (*size_a < 2 || *size_b < 2)
		return ;
	temp = a[*size_a - 1];
	i = *size_a - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = temp;
	temp = b[*size_b - 1];
	i = *size_b - 1;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = temp;
	write(1, "rrr\n", 4);
}

long	ft_atol(const char *str)
{
	long int	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}
