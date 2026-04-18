/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:53:13 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/23 13:48:41 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(long nbr);
static char	*memspace(int len);

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	long	nbr;
	char	*result;

	nbr = n;
	len = nbrlen(nbr);
	result = memspace(len);
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = '\0';
	return (result);
}

static char	*memspace(int len)
{
	char	*tbox;

	tbox = malloc((len + 1) * sizeof(char));
	if (!tbox)
		return (NULL);
	tbox[0] = '0';
	return (tbox);
}

static int	nbrlen(long nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		count++;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

// int main()
// {
// 	char *s = ft_itoa(100);
// 	printf("address %p = '%s'\n", s, s);
// 	return (0);
// }