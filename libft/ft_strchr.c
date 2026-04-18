/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:23:51 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/16 14:15:03 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == (char)c)
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}

// int main()
// {
// 	const char *str = "Hello, world!";
// 	char ch = 'r';
//
// 	char *result = ft_strchr(str, ch);
// 	printf("the first occurrence of %c is %ld\n", ch, result - str);
// 	return (0);
// }