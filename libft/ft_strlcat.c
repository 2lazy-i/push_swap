/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:07:10 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/21 14:40:04 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen >= dstsize)
		dstlen = dstsize;
	if (dstlen == dstsize)
		return (dstsize + srclen);
	if (dstsize - dstlen > srclen)
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, dstsize - dstlen - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dstlen + srclen);
}

// int main()
// {
// 	char arr1[] = " Krab";
// 	char arr2[18] = "Krusty";
// 	ft_strlcat(arr2, arr1, sizeof(arr2));
// 	printf("%s\n", arr2);
// 	return (0);
// }