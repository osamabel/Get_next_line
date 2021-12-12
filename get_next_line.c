/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:20:15 by obelkhad          #+#    #+#             */
/*   Updated: 2021/12/12 11:55:45 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	check_end_of_line(char *buf)
{
	size_t i;

	i = 0;
	while (i < strlen(buf) && buf[i] != '\n' && buf[i] != '\0')
		i++;
	return i;
}

char	*get_next_line(int fd)
{
	char *buf;
	char **holder;
	int splited_number;

	splited_number = 0;
	buf = malloc(sizeof(char) * 5);
	read(fd, buf, 5);
	while(check_end_of_line(buf) == strlen(buf))
	{
		printf("buf = %s\n",buf);
		splited_number++;
		read(fd, buf, 5);
	}
	printf("buf = %s\n",buf);
	read(fd, buf, 5);
	printf("buf = %s\n",buf);
	holder = (char **)malloc(sizeof(char *) * (splited_number + 2));
	printf("splited_number = %i",splited_number);
	
	
	
	return ("good");
}