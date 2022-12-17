/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:26:18 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/27 20:32:50 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	tol(long int nb, int base)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		nb *= -1;
		i = 1;
	}
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

int	prnt_frm(va_list arg, char frm)
{
	if (frm == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	else if (frm == 's')
		return (ft_putstr_fd(va_arg(arg, char *), 1));
	else if (frm == 'd' || frm == 'i')
		return (ft_putnbr_fd(va_arg(arg, int), 1));
	else if (frm == 'u')
		return (ft_putun(va_arg(arg, unsigned int)));
	else if (frm == 'x' || frm == 'X')
		return (ft_put_hex(va_arg(arg, unsigned int), frm));
	else if (frm == 'p')
		return (ft_put_add(va_arg(arg, void *)));
	else if (frm == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (ft_putchar_fd(frm, 1));
}

int	ft_printf(const char *s, ...)
{
	va_list			arg;
	unsigned int	i;
	unsigned int	j;

	va_start(arg, s);
	i = 0;
	j = 0;
	while (s[i] && i < ft_strlen((char *) s))
	{
		while (s[i] && s[i] != '%' && i < ft_strlen((char *) s))
		{	
			if (ft_putchar_fd(s[i], 1) < 0)
				return (-1);
			i++;
			j++;
		}
		if (s[i] == '%' && i < ft_strlen((char *) s))
		{
			j += prnt_frm(arg, s[i + 1]);
			i++;
		}
		i++;
	}
	va_end(arg);
	return (j);
}
