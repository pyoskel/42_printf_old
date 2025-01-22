/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbartoch <pbartoch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:27:14 by pbartoch          #+#    #+#             */
/*   Updated: 2025/01/22 20:38:57 by pbartoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>

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
	printf("hello my name is Laura and i'm 23 years old\n");
	printf("hello my name is %s and i'm %d years old\n", "Pascal", 25);
}
