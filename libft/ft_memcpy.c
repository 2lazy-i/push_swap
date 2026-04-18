/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:53:59 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/16 14:14:44 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;

	if (dst == NULL && src == NULL)
		return (dst);
	dptr = (unsigned char *) dst;
	sptr = (unsigned char *) src;
	while (n > 0)
	{
		*dptr = *sptr;
		dptr++;
		sptr++;
		n--;
	}
	return (dst);
}

// int main()
// {
// 	char src[50] = "1234567";
// 	printf("%s\n", (char *)ft_memcpy(src + 2, src, 3));
// 	return (0);
// }