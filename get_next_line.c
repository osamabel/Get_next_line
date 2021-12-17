/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:20:15 by obelkhad          #+#    #+#             */
/*   Updated: 2021/12/17 13:53:37 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include <limits.h>

size_t	check_end_of_line(char	*buf)
{
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	return i;

}

// todo strlen
// todo strncpy

void	ft_lstclear(t_list **lst)
{
	t_list	*current;

	if (lst)
	{
		while (*lst)
		{
			current = (*lst);
			(*lst) = (*lst)->next;
			free(current->buffer);
			free(current);
		}
		*lst = NULL;
	}
}


char	*get_next_line(int fd)
{
	static char	*lost_chars;
	char	*temp;
	char	*line;
	int		check;
	int		len;

	if (lost_chars)
	{
		len = strlen(lost_chars);
		check = check_end_of_line(lost_chars);
		if (check <= len)
		{
			temp = lost_chars + check;
			if (*temp == '\n')
				temp = lost_chars + check + 1;
			line = malloc(sizeof(char) * (check + 2));
			strncpy(line, lost_chars, check + 1);
			line[check + 1] = '\0';
			if (*temp)
			{
				lost_chars = malloc(sizeof(char) * (len - check));
				strncpy(lost_chars, temp, len - check);
				free(temp - check - 1);
			}else
			{
				free(lost_chars);
				lost_chars = NULL;
			}
			return (line);
		}
	}
	return (read_and_store(fd, &lost_chars));
}
