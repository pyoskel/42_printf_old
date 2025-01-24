/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbartoch <pbartoch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:24:28 by pbartoch          #+#    #+#             */
/*   Updated: 2025/01/24 20:32:54 by pbartoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include <stdarg.h> //for variadic functions
#include <string.h> //for variadic functions
#include <unistd.h> //for write function
#include "../libft/libft.h"

// int	putnbr_base(int num, char *base)
// {

// }

// int	putptr(void *ptr)
// {

// }

void	print_integer(int i)
{
	write(1, ft_itoa(i), ft_strlen(ft_itoa(i)));
}

void	replace_percent(char *format, va_list args)
{
	if (*format == '%')
		write(1, "%", 1);
	else if (*format == 'i')
		print_integer(va_arg(args, int));
	else
		write(1, "something else", 15);
	format++;
}

int	handle_specifier(char specifier, va_list args, int *count)
{
	if (specifier == 'c')
		count = ft_putchar_fd
	else if (specifier == 's')
		count = ft_putstr_fd
	else if (specifier == 'd')
		count = ft_putnbr_fd
	else if (specifier == 'i')
		count = ft_putnbr_fd
	else if (specifier == 'u')
		count = ft_putnbr_fd
	else if (specifier == '%')
		count = ft_putchar_fd
	else if (specifier == 'x')
		count = ft_puthex
	else if (specifier == 'X')
		count = ft_puthex_upper
	else if (specifier == 'p')
		count = ft_putchar_fd or putptr
	// return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			replace_percent(++format, args);
		else
			write(1, &format, 1);
		format++;
	}
}

int	main(void)
{
	ft_printf("Test %% int: %i\n", "12");
}
