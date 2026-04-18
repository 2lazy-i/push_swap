/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:36:24 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/23 13:46:47 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write (fd, &str[i], 1);
		i++;
	}
}

// int main()
// {
// 	ft_putstr_fd("Codam", 1);
// 	ft_putstr_fd("42", 2);
// 	int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd != -1)
// 	{
// 		ft_putstr_fd("Codam42", fd);
// 		close(fd);
// 	}
// 	return (0);
// }