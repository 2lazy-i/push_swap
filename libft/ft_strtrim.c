/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:10:48 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/24 16:14:13 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*res;

	i = 0;
	start = 0;
	end = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
		start++;
	}
	i = ft_strlen(s1);
	if (start == i)
		return (ft_strdup(""));
	while (i > 0 && ft_strrchr(set, s1[i - 1]))
	{
		i--;
		end++;
	}
	res = ft_substr(s1, start, ft_strlen(s1) - (start + end));
	return (res);
}

// int main()
// {
// 	char str[] = "xddxdCodam42xdxddx";
// 	char *res;
// 	res = ft_strtrim(str, "xd");
// 	printf("%s\n", res);
// 	free(res);
// 	return (0);
// }