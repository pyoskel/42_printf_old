/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_on.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:40:27 by pbartoch          #+#    #+#             */
/*   Updated: 2025/10/23 02:35:26 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/**
 * ft_putchar - Writes a single character to the standard output.
 * @param c The character to write.
 * Return: The number of characters written (1).
 */
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * ft_putstr - Writes a string to the standard output.
 * @param str The string to write.
 * Return: The number of characters written.
 */
int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i] != '\0')
		count += write(1, &str[i], 1);
	return (count);
}

/**
 * ft_putnbr_base - Writes an integer in a specified base to the standard output.
 * @param nbr The integer to write.
 * @param c The format specifier ('d', 'i', etc.).
 * @param base The base for conversion (e.g., 10 for decimal).
 * Return: The number of characters written.
 */
int	ft_putnbr_base(int nbr, char c, unsigned int base)
{
	int		count;
	char	dec;

	count = 0;
	if (nbr == INT_MIN)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= (int)base)
		count += ft_putnbr_base(nbr / base, c, base);
	dec = "0123456789"[nbr % base];
	count += write(1, &dec, 1);
	return (count);
}

/**
 * - Writes an unsigned integer in a specified base to the standard output.
 * @param nbr The unsigned integer to write.
 * @param c The format specifier ('x', 'X', etc.).
 * @param base for conversion (10 for decimal, 16 for hexadecimal).
 * Return: The number of characters written.
 */
int	ft_putnbr_u_base(unsigned int nbr, char c, unsigned int base)
{
	int		count;
	char	hexadec;

	count = 0;
	if (nbr >= base)
		count += ft_putnbr_u_base(nbr / base, c, base);
	if (c == 'X')
		hexadec = "0123456789ABCDEF"[nbr % base];
	else
		hexadec = "0123456789abcdef"[nbr % base];
	count += write(1, &hexadec, 1);
	return (count);
}

/**
 * - Writes a pointer address in hexadecimal format to the standard output.
 * @param ptr The pointer to write.
 * @param flag A flag to indicate if the "0x" prefix should be printed 
 * 				(0 for no, 1 for yes).
 * Return: The number of characters written.
 */
int	ft_putptr(void *ptr, int flag)
{
	unsigned long	address;
	int				count;
	char			hexadec;

	address = (unsigned long)ptr;
	count = 0;
	if (flag == 0)
	{
		if (!ptr)
			return (write(1, "(nil)", 5));
		count += write(1, "0x", 2);
	}
	if (address >= 16)
		count += ft_putptr((void *)(address / 16), 1);
	hexadec = "0123456789abcdef"[address % 16];
	count += write(1, &hexadec, 1);
	return (count);
}

// int	main(void) //ft_putchar
// {
// 	ft_putchar('A');
// 	return (0);
// }

// int	main(void) //ft_putptr_00
// {
// 	int	value = 2;

// 	printf("%p\n", &value);
// 	ft_putptr(&value, 0);
// 	printf("\n");
// 	return (0);
// }

// int main(void) //ft_putptr_01
// {
//     int count;
//     void *ptr = (void *)0xDEADBEEF; // Ein Beispiel-Pointer

//     // Teste deinen %p-Formatter
//     count = ft_printf("Test %p: %p\n", ptr, NULL);
//     printf("Original: %p %p (count: %d)\n", ptr, NULL, count);

//     return 0;
// }