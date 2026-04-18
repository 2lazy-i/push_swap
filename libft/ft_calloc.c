/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:32:14 by mapatenk          #+#    #+#             */
/*   Updated: 2024/11/19 15:11:52 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / count)
		return (NULL);
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

// int main()
// {
// 	int	*arr;
// 	arr = ft_calloc(1, sizeof(int));
// 	printf("%d\n", arr[0]);
// 	free(arr);
// 	return 0;
// }