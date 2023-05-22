/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:10:28 by fvaliyak          #+#    #+#             */
/*   Updated: 2022/11/04 19:56:19 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				c;
	unsigned int	n1;

	c = 0;
	if (n < 0)
	{
		if (write(fd, "-", 1) == -1)
      return;
		n = -n;
	}
	n1 = n;
	if (n1 > 9)
		ft_putnbr_fd((n1 / 10), fd);
	c = n1 % 10 + 48;
	if (write(fd, &c, 1) == -1)
    return ;
}
