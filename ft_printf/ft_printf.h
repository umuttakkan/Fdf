/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:44:58 by uakkan            #+#    #+#             */
/*   Updated: 2022/11/29 17:45:01 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_format(va_list *args, char c);
int	ft_int(int a);
int	ft_hex(unsigned int a, char c);
int	ft_point(unsigned long a, int cont);
int	ft_string(char *str);
int	ft_unsigned(unsigned int a);
int	ft_putchar(char a);

#endif
