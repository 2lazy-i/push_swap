/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:47:32 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/22 14:17:43 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// static	void ft_upperteri(unsigned int i, char *c)
// {
// 	(void)i;
// 	if (*c >= 'a' && *c <= 'z')
// 	{
// 		*c = *c - 32;
// 	}
// }
//
// int main()
// {
// 	char test[] = "teStmyFuNctioN42";
// 	ft_striteri(test, ft_upperteri);
// 	printf("%s\n", test);
// 	return (0);
// }