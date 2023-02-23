/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:14:11 by uakkan            #+#    #+#             */
/*   Updated: 2023/02/15 15:23:06 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_strsplit_addr(char **data)
{
	size_t	i;

	i = 0;
	while (data[i++])
		free(data[i]);
	free(data);
}

int	ft_isdigit_base(char c)
{
	char	*digits;
	int		i;

	digits = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (digits[i] == ft_tolower(c))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str)
{
	long	result;
	size_t	i;

	result = 0;
	i = 2;
	while (ft_isdigit_base(str[i]) >= 0)
		result = result * 16 + ft_isdigit_base(str[i++]);
	return (result);
}
