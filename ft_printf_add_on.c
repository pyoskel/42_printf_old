/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_on.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbartoch <pbartoch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:40:27 by pbartoch          #+#    #+#             */
/*   Updated: 2025/01/29 22:14:13 by pbartoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	int		count;
	char	digit;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, c);
	if (c == 'X')
		digit = "0123456789ABCDEF"[n % 16];
	else
		digit = "0123456789abcdef"[n % 16];
	count += write(1, &digit, 1);
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
