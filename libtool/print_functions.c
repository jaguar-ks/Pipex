/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deman_wolf <deman_wolf@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:14:46 by faksouss          #+#    #+#             */
/*   Updated: 2022/12/08 05:37:00 by deman_wolf       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_put_add(void *p)
{
	unsigned long	r;
	int				j;

	j = write(1, "0x", 2);
	if (!p)
	{
		j += write(1, "0", 1);
		return (j);
	}
	r = (unsigned long)p;
	j += ft_put_hex(r, 'x');
	return (j);
}

int	ft_putun(unsigned int n)
{
	unsigned int	nb;

	nb = n;
	if (nb <= 9)
		ft_putchar_fd(nb + 48, 1);
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, 1);
		ft_putnbr_fd(nb % 10, 1);
	}
	nb = n;
	return (tol(nb, 10));
}

int	ft_put_hex(unsigned long n, char frm)
{
	unsigned long	nb;
	char			*hex;

	nb = n;
	if (frm == 'x')
		hex = "0123456789abcdef";
	else if (frm == 'X')
		hex = "0123456789ABCDEF";
	if (nb <= 15)
		ft_putchar_fd(hex[nb], 1);
	if (nb > 15)
	{
		ft_put_hex(nb / 16, frm);
		ft_put_hex(nb % 16, frm);
	}
	nb = n;
	return (tol(nb, 16));
}
