/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbartoch <pbartoch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:24:28 by pbartoch          #+#    #+#             */
/*   Updated: 2025/01/30 02:00:12 by pbartoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	putnbr_base(int num, char *base)
// {

// }

// int	putptr(void *ptr)
// {

// }

// void	print_integer(int i)
// {
// 	write(1, ft_itoa(i), ft_strlen(ft_itoa(i)));
// }

int	handle_specifier(char specifier, va_list args)
{
	int	count;

	if (specifier == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		count = ft_putnbr(va_arg(args, unsigned int));
	else if (specifier == '%')
		count = ft_putchar(va_arg(args, int));
	else if (specifier == 'x' || specifier == 'X')
		count = ft_puthex(va_arg(args, unsigned int), specifier);
	else if (specifier == 'p')
		count = ft_putptr(va_arg(args, void *));
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	i = -1;
	count = 0;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
			count += handle_specifier(format[++i], args);
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	return (va_end(args), count);
}

// int	main(void)	//ft_puthex testen
// {
// 	int				number1 = 255;
// 	int				number2 = 0;
// 	unsigned int	number3 = 4294967295;
// 	int				count = ft_printf("%x", number1); //return Wert von printf wird an count uebergeben

// 	printf("Lowercase hex (x): %x\n", number1);
// 	ft_printf("Lowercase hex (x): %x\n\n", number1); // Erwartet: "ff"

// 	printf("Uppercase hex (X): %X\n", number1);
// 	ft_printf("Uppercase hex (X): %X\n\n", number1); // Erwartet: "FF"

// 	printf("Hex von 0: %x\n", number2);
// 	ft_printf("Hex von 0: %x\n\n", number2); // Erwartet: "0"

// 	printf("Hex von 4294967295 (UINT_MAX): %x\n", number3);
// 	ft_printf("Hex von 4294967295 (UINT_MAX): %x\n", number3); // Erwartet: "ffffffff"

// 	printf("%d\n", count); //length for Lowercase hex (number1)
// 	return (0);
// }
