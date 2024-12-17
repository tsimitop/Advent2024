/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:26:13 by tsimitop          #+#    #+#             */
/*   Updated: 2024/04/15 23:17:04 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoinn(char *s1, char *s2);
size_t	ft_strlenn(char *str);
void	ft_bzeron(void *s, size_t n);
void	*ft_callocn(size_t count, size_t size);
char	*ft_strchrn(char *s, int c);
char	*ft_strdupn(char *s1);

#endif