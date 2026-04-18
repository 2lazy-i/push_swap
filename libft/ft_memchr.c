/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:15:20 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/16 14:14:37 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return ((char *)&ptr[i]);
		}
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char arr[50] = "Hello, world!";
// 	char ch = 'r';
//
// 	char *result = ft_memchr(arr, ch, 20);
// 	printf("the first occurrence of %c is %ld\n", ch, result - arr);
// 	return (0);
// }