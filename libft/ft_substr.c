/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:23:26 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/24 11:05:51 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	max;

	if (!s)
		return (NULL);
	max = ft_strlen(s);
	i = 0;
	if (start > max)
		return (ft_strdup(""));
	if (start + len > max)
		len = max - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len && s[start] != '\0')
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

// int main()
// {
// 	char str[] = "I will try to do it in time";
// 	char *sub = ft_substr(str, 2, 4);
// 	printf("%s\n", sub);
// 	free(sub);
// 	return (0);
// }