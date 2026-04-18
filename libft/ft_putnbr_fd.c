/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapatenk <mapatenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:10:24 by mapatenk          #+#    #+#             */
/*   Updated: 2024/10/23 13:29:12 by mapatenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			digit = n + 48;
			write(fd, &digit, 1);
		}
	}
}

// int main()
// {
//	ft_putnbr_fd(-42, 1);
//	ft_putnbr_fd(31, 2);
//	int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
//	if (fd != -1)
// {
//		ft_putnbr_fd(-4231, fd);
// 		close(fd);
// }
// 	return (0);
// }