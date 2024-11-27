/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:19:53 by moraouf           #+#    #+#             */
/*   Updated: 2024/11/27 15:42:46 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

static char	*ft_strjoin_free(char **reste, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(*reste, buffer);
	free(*reste);
	reste = NULL;
	return (tmp);
}

static char	*get_line(char **reste)
{
	size_t	len;
	char	*line;
	char	*tmp;

	len = 0;
	if (!*reste || **reste == '\0')
	{
		return (NULL);
	}
	while ((*reste)[len] != '\n' && (*reste)[len] != '\0')
		len++;
	if ((*reste)[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, *reste, len);
	line[len] = '\0';
	tmp = ft_strdup((*reste) + len);
	free(*reste);
	*reste = tmp;
	return (line);
}


char	*read_file(char **reste, char *buffer, int fd)
{
	ssize_t	bytes;

	while (!ft_strchr(reste[fd], '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		reste[fd] = ft_strjoin_free(&reste[fd], buffer);
	}
	free(buffer);
	if (!reste[fd] || reste[fd][0] == '\0')
	{
		free(reste[fd]);
		return (NULL);
	}
	return (reste[fd]);
}

char	*get_next_line(int fd)
{
	static char	*reste[FD_MAX];
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	reste[fd] = read_file(reste, buffer, fd);
	return (get_line(&reste[fd]));
}

// #include <stdio.h>
// int	main(void)
// {
// 	int		fd1;
//     int     fd2;
//     int     fd3;
// 	char	*line;

//     if(fd1< 0 || fd2< 0 || fd3 < 0)
//         {
//             perror ("hadchi makhdamch");
//         }

//     printf("Reading from test1.txt:\n");
// 	fd1 = open("Taha.txt", O_RDONLY);
// 	while ((line = get_next_line(fd1)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
//     printf("Reading from test2.txt:\n");
//     fd2 = open("fd2.txt", O_RDONLY);
// 	while ((line = get_next_line(fd2)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
//     printf("Reading from test3.txt:\n");
//     fd3 = open("fd3.txt", O_RDONLY);
// 	while ((line = get_next_line(fd3)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}

//     close(fd1);
// 	close(fd2);
// 	close(fd3);

//}
