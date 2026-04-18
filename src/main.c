/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 2lazy <2lazy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:08:25 by mapatenk          #+#    #+#             */
/*   Updated: 2025/08/24 13:52:17 by 2lazy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*allocate_arrays(int argc, int **b)
{
	int	*a;

	a = (int *)malloc((argc - 1) * sizeof(int));
	if (!a)
		return (NULL);
	*b = (int *)malloc((argc - 1) * sizeof(int));
	if (!*b)
	{
		free(a);
		return (NULL);
	}
	return (a);
}

void	parse_arguments(int *a, int size_a, char **argv)
{
	int	i;

	i = 0;
	while (i < size_a)
	{
		a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

bool	is_valid_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (false);
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	validate_args(int argc, char **argv)
{
	int		i;
	int		j;
	long	num;

	if (argc < 2)
		return (false);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (false);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (false);
		j = i + 1;
		while (j < argc)
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;

	if (argc == 1)
		return (0);
	if (!validate_args(argc, argv))
		return (write(2, "Error\n", 6), 1);
	a = allocate_arrays(argc, &b);
	if (!a)
		return (1);
	size_a = argc - 1;
	size_b = 0;
	parse_arguments(a, size_a, argv);
	if (!normalize(a, size_a))
	{
		free(a);
		free(b);
		return (1);
	}
	sort(a, b, &size_a, &size_b);
	free(a);
	free(b);
	return (0);
}
