/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbartoch <pbartoch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:24:28 by pbartoch          #+#    #+#             */
/*   Updated: 2025/01/23 18:46:12 by pbartoch         ###   ########.fr       */
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

static int	handle_specifier(char specifier, va_list args, int *count)
{
	if (specifier == 'c')
	else if (specifier == 's')
	else if (specifier == 'd')
	else if (specifier == 'i')
	else if (specifier == '%')
	else if (specifier == 'x')
	else if (specifier == 'X')
	else if (specifier == 'p')
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
