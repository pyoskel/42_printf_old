/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbartoch <pbartoch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:55:25 by pbartoch          #+#    #+#             */
/*   Updated: 2025/02/02 23:23:52 by pbartoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //for variadic functions
# include <unistd.h> //for write function
# include <stdio.h>  //for printf function

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_base(int nbr, char c, unsigned int base);
int	ft_putnbr_u_base(unsigned int nbr, char c, unsigned int base);
int	ft_putptr(void *ptr);

#endif