/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:20:15 by obelkhad          #+#    #+#             */
/*   Updated: 2021/12/15 17:48:18 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

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
	}
}


char	*get_next_line(int fd)
{
	t_list	*list;
	t_list	*temp;
	char	*buf;
	size_t	chars_in_line;

	if (fd == -1)
		return NULL;
	chars_in_line = 0;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	buf[BUFFER_SIZE] = '\0';
	if (read(fd, buf, BUFFER_SIZE) <= 0)
		return NULL;
	list = ft_lstnew(buf, check_end_of_line(buf));
	temp = list;
	while (check_end_of_line(buf) == BUFFER_SIZE)
	{
		chars_in_line += check_end_of_line(buf);
		if (read(fd, buf, BUFFER_SIZE) == -1)
			return NULL;
		buf[BUFFER_SIZE] = '\0';
		ft_lstadd_bask(&list, ft_lstnew(buf, check_end_of_line(buf)));
		list = list->next;
	}
	chars_in_line += check_end_of_line(buf);
	return (list = temp, ft_lst_to_string(&list, chars_in_line, &buf, check_end_of_line(buf)));
}
