/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uakkan <uakkan@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:20:04 by uakkan            #+#    #+#             */
/*   Updated: 2022/12/05 15:42:55 by uakkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif 

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_get_after_newline(char *readline);
char	*ft_get_before_newline(char *readline);
char	*ft_get_read_line(int fd, char *readline);
char	*ft_strchr(char *str, char a);
char	*ft_strjoin(char *readline, char *data);

#endif