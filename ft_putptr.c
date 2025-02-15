/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:22:37 by yufli             #+#    #+#             */
/*   Updated: 2025/02/14 22:27:30 by yufli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex_ptr(t_list *data, unsigned long long n)
{
	char	c;
	int		rem;

	if (n >= 16)
		ft_puthex_ptr(data, n / 16);
	rem = n % 16;
	if (rem < 10)
		c = rem + '0';
	else
		c = rem - 10 + 'a';
	ft_putchar(data, c);
}

void	ft_putptr(t_list *data, unsigned long long ptr)
{
	if (ptr == 0)
	{
		ft_putstr(data, "0x0");
		return ;
	}
	ft_putstr(data, "0x");
	ft_puthex_ptr(data, ptr);
}
