/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbartoch <pbartoch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:24:28 by pbartoch          #+#    #+#             */
/*   Updated: 2024/12/14 11:28:29 by pbartoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_base(int num, char *base)
{

}

int	putptr(void *ptr)
{

}

void	replace_percent(char *format, va_list ap)
{
if (*format == '%')
	write(1, "%", 1);
else if (*format == 'i')
	print_integer(va_arg(ap, int));
else
	write(1, "something else", 15);
format++;
}

int	handle_modifier()
{

}

int	ft_printf(const char *format, ...)
{
int		i;
va_list	ap;

va_start(ap, format);
i = 0;
while (format[i] != '\0')
{
	if (format[i] == '%')
		replace_percent(++format, ap);
	else
		write(1, &format, 1);
	format++;
}
}
