/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:09:42 by taha_laylay       #+#    #+#             */
/*   Updated: 2024/11/25 20:42:36 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_line(char **reste)
{
	size_t len;
	char *line;
	char *tmp;

	len = 0;
	if (!*reste || **reste == '\0')
		return (NULL);
	while((*reste)[len] != '\n' && (*reste)[len] != '\0')
		len++;
	if((*reste)[len] == '\n')
		len++;
	line = malloc(len + 1);
	if(!line)
		return NULL;
	ft_memcpy(line,*reste,len);
	tmp = ft_strdup((*reste) + len );
	free(*reste);
	*reste = tmp;
	return (line);
}


char *get_next_line(int fd)
{
	static char *reste;
	size_t bytes;
	char *buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	buffer = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if(!buffer)
		return NULL;
	while(!ft_strchr(reste,'\n'))
	{
		bytes = read(fd,buffer,BUFFER_SIZE);
		if(bytes < 0){
			free(buffer);
			return (NULL);	
		}
		if(bytes == 0)
			break;
		reste = ft_strjoin(reste,buffer);
	}
	return(get_line(&reste));
}
#include  <stdio.h>
int main()
{
	int fd1 = open("Taha.txt",  O_RDONLY);
	char *line;

	if((line = get_next_line(fd1)) != NULL)
	{
		printf("%s",line);
		free(line);
	}
	close(fd1);
}
