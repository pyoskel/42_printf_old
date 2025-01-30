/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbartoch <pbartoch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:55:25 by pbartoch          #+#    #+#             */
/*   Updated: 2025/01/30 01:17:17 by pbartoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //for variadic functions
# include <unistd.h> //for write function
# include <stdio.h> //for printf function

int	ft_printf(const char *format, ...);
int	ft_puthex(unsigned int n, char c);

#endif