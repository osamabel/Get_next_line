/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:20:15 by obelkhad          #+#    #+#             */
/*   Updated: 2021/12/16 20:46:46 by obelkhad         ###   ########.fr       */
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
	int		readed_char;
	char	*buf;
	t_list	*list;
	t_list	*temp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	readed_char = read(fd, buf, BUFFER_SIZE); //6
	if (readed_char <= 0)
	{
		free(buf);
		return (NULL);
	}
	buf[readed_char] = '\0';
	list = ft_lstnew(buf, check_end_of_line(buf));
	temp = list;
	while (check_end_of_line(buf) == BUFFER_SIZE)
	{
		readed_char = read(fd, buf, BUFFER_SIZE);
		if (readed_char <= 0)
			return (list = temp, ft_lst_to_string(&list, &buf, BUFFER_SIZE));
		ft_lstadd_bask(&list, ft_lstnew(buf, check_end_of_line(buf)));
		list = list->next;
	}
	return (list = temp, ft_lst_to_string(&list, &buf, check_end_of_line(buf)));
}
