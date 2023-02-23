/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:36:18 by uakkan            #+#    #+#             */
/*   Updated: 2022/12/05 15:36:24 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, char a)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (!a)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == a)
			return (&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *readline, char *data)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!readline)
	{
		readline = (char *)malloc(sizeof(char) * 1);
		readline[0] = '\0';
	}
	if (!readline || !data)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(readline) + ft_strlen(data)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (readline)
		while (readline[++i] != '\0')
			str[i] = readline[i];
	while (data[j] != '\0')
		str[i++] = data[j++];
	str[i] = '\0';
	free(readline);
	return (str);
}
