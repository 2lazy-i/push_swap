/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:17:53 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/28 13:58:55 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c);
static void	init_vars(size_t *i, size_t *index, char ***res, size_t c);
static void	*mem_free(char **arr);
static char	*fill_word(const char *s, size_t start, char c);

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	size_t	index;
	size_t	start;

	init_vars(&i, &index, &res, word_count(s, c) + 1);
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			res[index] = fill_word(s, start, c);
			if (!res[index++])
				return (mem_free(res));
		}
	}
	res[index] = NULL;
	return (res);
}

static void	init_vars(size_t *i, size_t *index, char ***res, size_t c)
{
	*i = 0;
	*index = 0;
	*res = malloc(c * sizeof(char *));
}

static int	word_count(const char *str, char c)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] && (i == 0 || str[i - 1] == c))
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static void	*mem_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	*fill_word(const char *s, size_t start, char c)
{
	size_t	len;
	char	*word;
	size_t	i;

	i = 0;
	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

// int main(void)
// {
//     char    str[] = " my final   function  is ready";
//     char    ch = ' ';
//     char    **res;
//     int     i;

//     res = ft_split(str, ch);
//     if (res == NULL)
//     {
//         printf("Memory allocation failed.\n");
//         return (1);
//     }
//     i = 0;
//     while (res[i] != NULL)
//     {
//         printf("%s\n", res[i]);
//         free(res[i]);
//         i++;
//     }
//     free(res);
//     return (0);
// }