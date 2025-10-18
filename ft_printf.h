/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:55:25 by pbartoch          #+#    #+#             */
/*   Updated: 2025/10/18 03:09:48 by pabartoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //for variadic functions
# include <unistd.h> //for write function
# include <stdio.h>  //for printf function
# include <limits.h> //for INT_MIN 

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_base(int nbr, char c, unsigned int base);
int	ft_putnbr_u_base(unsigned int nbr, char c, unsigned int base);
int	ft_putptr(void *ptr, int flag);

#endif