/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha_laylay <taha_laylay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:10:23 by taha_laylay       #+#    #+#             */
/*   Updated: 2024/11/24 21:59:25 by taha_laylay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif



# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


char *get_next_line(int fd);
char *ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(const char *s1, const char *s2);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);


#endif