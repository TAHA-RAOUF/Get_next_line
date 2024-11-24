/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha_laylay <taha_laylay@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:09:42 by taha_laylay       #+#    #+#             */
/*   Updated: 2024/11/24 21:56:46 by taha_laylay      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

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
	bytes = read(fd,buffer,BUFFER_SIZE);
	if(bytes < 0){
		free(buffer);
		return (NULL);	
	}
	buffer[bytes] = '\0';
	return(buffer);
}


int main()
{
	int fd1 = open("Taha.txt", O_CREAT | O_RDWR , 0777);
	if(fd1 == -1 )
	{
		perror("ceci est une rror ");
	}
	write(fd1,"Salam ana labas o nta ki dayr llabas 3lik ",43);
	lseek(fd1,0,SEEK_SET);
	
	printf("%s",get_next_line(fd1));
	
}