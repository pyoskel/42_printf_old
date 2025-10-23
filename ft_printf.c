/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:24:28 by pbartoch          #+#    #+#             */
/*   Updated: 2025/10/23 04:57:51 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * handle_specifier - Handles a single format specifier and writes the
 * corresponding argument to the standard output.
 * @param specifier The format specifier character.
 * @param args The variadic arguments list.
 * Return: The number of characters written for the specifier.
 */
int	handle_specifier(char specifier, va_list args)
{
	int	count;

	if (specifier == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count = ft_putnbr_base(va_arg(args, int), specifier, 10);
	else if (specifier == 'u')
		count = ft_putnbr_u_base(va_arg(args, unsigned int), specifier, 10);
	else if (specifier == '%')
		count = write(1, "%", 1);
	else if (specifier == 'x' || specifier == 'X')
		count = ft_putnbr_u_base(va_arg(args, unsigned int), specifier, 16);
	else if (specifier == 'p')
		count = ft_putptr(va_arg(args, void *), 0);
	else
		return (-1);
	return (count);
}

/**
 * ft_printf - A simplified version of the printf function.
 * @param format The format string containing text and format specifiers.
 * Variadic arguments corresponding to the format specifiers.
 * Return: The total number of characters printed.
 */
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

// int	main(void) // ft_printf testen
// {
// 	int	printed;

// 	// String-Literale werden automatisch zusammengefügt
//  	printed	= ft_printf("Character: %c\nString: %s\nDecimal: %d\n"
//         "Unsigned: %u\nHex (lowercase): %x\nHex (uppercase): %X\n"
//         "Pointer: %p\nPercent sign: %%\n",
//         'A', "Hello, World!", -42, 42, 255, 255, &printed);

// 	ft_printf("Total characters printed: %d\n", printed);
// 	return (0);
// }

// int	main(void) // for ft_putnbr_base
// {
// 	int i = INT_MIN;

// 	printf("%d\n", i);
// 	ft_printf("%d\n", i);
// 	return (0);
// }

// int	main(void) //ft_putstr testen
// {
// 	// char var1 = NULL;
// 	printf("hallo %s\n", "world");
// 	ft_printf("hallo %s\n", "world");
// 	return (0);
// }

// int	main(void) //ft_putchar testen
// {
// 	printf("hallo %c\n", c);
// 	ft_printf("hallo %c\n", c);
// 	return (0);
// }

// int	main(void) //ft_putnbr_base
// {
// 	int				num;
// 	// int				hex;
// 	// unsigned int	max_unsigned;
// 	int				*ptr_to_num;

// 	num = 15;
// 	// hex = 12112;
// 	// max_unsigned = 4294967294;
// 	ptr_to_num = &num;
// 	// ft_printf("decimal: %d, %i\nhexadecimal:
// 	// %X\nunsigned_int: %u\npointer:
// 	// 	%p\n", num, num, hex, max_unsigned, ptr_to_num);
// 	printf("Integer %d\nPointer %p\n", num, ptr_to_num);
// 	ft_printf("Integer %d\nPointer %p\n", num, ptr_to_num);
// 	return (0);
// }

// int	main(void)	//ft_puthex testen
// {
// 	int				number1 = 255;
// 	int				number2 = 0;
// 	unsigned int	number3 = 4294967295;
// 	int				count = ft_printf("%x", number1);
// // return Wert von printf wird an count uebergeben

// 	printf("Lowercase hex (x): %x\n", number1);
// 	ft_printf("Lowercase hex (x): %x\n\n", number1); // Erwartet: "ff"

// 	printf("Uppercase hex (X): %X\n", number1);
// 	ft_printf("Uppercase hex (X): %X\n\n", number1); // Erwartet: "FF"

// 	printf("Hex von 0: %x\n", number2);
// 	ft_printf("Hex von 0: %x\n\n", number2); // Erwartet: "0"

// 	printf("Hex von 4294967295 (UINT_MAX): %x\n", number3);
// 	ft_printf("Hex von 4294967295 (UINT_MAX): %x\n", number3);
// // Erwartet: "ffffffff"

// 	printf("%d\n", count); //length for Lowercase hex (number1)
// 	return (0);
// }
