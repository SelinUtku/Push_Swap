/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sutku <sutku@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:22:24 by sutku             #+#    #+#             */
/*   Updated: 2022/11/21 15:29:30 by sutku            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2, int c);
char	*my_get_line(int control, char **s_arr, char **line, char *buff);
char	*check_valid(int control, char *s_arr, char *line, char *buff);
char	*remain_part(char *s_arr, char **line, int *flag);
int		check_newline(char *buff);
void	my_malloc(char **buff);

#endif