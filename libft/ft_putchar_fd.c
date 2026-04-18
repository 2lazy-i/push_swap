/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:48:59 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/21 15:35:09 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// int main()
// {
// 	ft_putchar_fd('A', 1);
// 	ft_putchar_fd('B', 2);
// 	int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd != -1)
// 	{
// 		ft_putchar_fd('C', fd);
// 		close(fd);
// }
// 	return (0);
// }