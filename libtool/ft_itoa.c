/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faksouss <faksouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:25:40 by faksouss          #+#    #+#             */
/*   Updated: 2022/11/26 22:51:28 by faksouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*insert(long int n, char *r, int l)
{
	r[l] = 0;
	while (--l >= 0)
	{
		if (n == 0)
			break ;
		r[l] = (n % 10) + 48;
		n /= 10;
	}
	return (r);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*r;
	long int	nb;

	nb = n;
	if (nb < 0)
		nb *= -1;
	i = tol(nb, 10);
	r = (char *)ft_calloc(i + 2, sizeof(char));
	if (!r)
		return (NULL);
	nb = n;
	if (nb >= 0 && nb < 10)
		r[0] = nb + 48;
	if (nb > 9)
		r = insert(nb, r, i);
	else if (nb < 0)
	{
		r[0] = '-';
		r = insert(-nb, r, i + 1);
	}
	return (r);
}
