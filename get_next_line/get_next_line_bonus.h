/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:18:44 by moraouf           #+#    #+#             */
/*   Updated: 2024/11/27 15:37:00 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef FD_MAX
#  define FD_MAX 1337
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
static char	*ft_strjoin_free(char **reste, char *buffer);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(char *s);
char		*ft_strchr(char *s, int c);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strdup(char *s);
char		*read_file(char **reste, char *buffer, int fd);

#endif