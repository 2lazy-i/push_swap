/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:55:59 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/21 16:05:56 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write (fd, &str[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}

// int main()
// {
// 	ft_putendl_fd("Codam", 1);
// 	ft_putendl_fd("42", 2);
// 	int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd != -1)
// 	{
// 		ft_putendl_fd("Codam42", fd);
// 		close(fd);
// 	}
// 	return (0);
// }