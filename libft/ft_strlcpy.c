/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:01:06 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/17 12:49:23 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
		ft_memcpy(dst, src, srclen + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (srclen);
}

// int main()
// {
// 	char arr1[] = "Codam 42";
// 	char arr2[5] = "full";
// 	ft_strlcpy(arr2, arr1, sizeof(str2));
// 	printf("%s\n", arr1);
// 	printf("%s\n", arr2);
// 	return (0);
// }