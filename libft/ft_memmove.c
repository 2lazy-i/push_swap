/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:44:47 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/16 15:06:58 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dptr;
	char	*sptr;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	sptr = (char *) src;
	dptr = (char *) dst;
	i = 0;
	if (dptr > sptr)
	{
		while (n > 0)
		{
			n--;
			dptr[n] = sptr[n];
		}
	}
	while (i < n)
	{
		dptr[i] = sptr[i];
		i++;
	}
	return (dst);
}

// int main()
// {
// 	char src[50] = "1234567";
// 	printf("%s\n", (char *)ft_memmove(src + 2, src, 3));
// 	return (0);
// }