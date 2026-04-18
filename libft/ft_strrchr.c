/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:57:19 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/16 14:15:25 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (str[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
		i--;
	}
	return (NULL);
}

// int main()
// {
// 	const char *str = "Hello, world!";
// 	char ch = 'l';
//
// 	char *result = ft_strrchr(str, ch);
// 	printf("the last occurrence of %c is %ld\n", ch, result - str);
// 	return (0);
// }