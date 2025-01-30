/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_on.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbartoch <pbartoch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:40:27 by pbartoch          #+#    #+#             */
/*   Updated: 2025/01/30 01:21:48 by pbartoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr, char c)
{
	int		count;
	char	hexadec;

	count = 0;
	if (nbr >= 16)
		count += ft_puthex(nbr / 16, c);
	if (c == 'X')
		hexadec = "0123456789ABCDEF"[nbr % 16];
	else
		hexadec = "0123456789abcdef"[nbr % 16];
	count += write(1, &hexadec, 1);
	return (count);
}


// int	ft_putchar(char c)
// {
// 	int	count;

// 	count = 0;
// 	write(1, &c, 1);
// 	count++;
// 	return (count);
// }

// int	main(void)
// {
// 	ft_putchar(53);
// 	return (0);
// }
