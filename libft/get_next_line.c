/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:45:09 by mapatenk          #+#    #+#             */
/*   Updated: 2025/01/16 12:09:29 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*extract_line(char **remainder)
{
	char	*line;
	char	*newline;
	char	*temp;

	newline = ft_strchr(*remainder, '\n');
	if (!newline)
	{
		line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		return (line);
	}
	line = ft_substr(*remainder, 0, newline - *remainder + 1);
	temp = ft_strdup(newline + 1);
	free(*remainder);
	*remainder = temp;
	return (line);
}

static char	*read_to_remainder(int fd, char *remainder)
{
	char	*buffer;
	int		bytes_read;
	char	*temp;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(remainder), NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(remainder), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(remainder, buffer);
		free(remainder);
		if (temp == NULL)
			return (free(buffer), NULL);
		remainder = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remainder)
		remainder = ft_strdup("");
	if (!remainder)
		return (NULL);
	remainder = read_to_remainder(fd, remainder);
	if (!remainder || *remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	line = extract_line(&remainder);
	if (!line)
	{
		free(remainder);
		remainder = NULL;
	}
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int fd;
// 	char *line = NULL;
//
// 	fd = open("test_full.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }