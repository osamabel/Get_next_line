/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:20:15 by obelkhad          #+#    #+#             */
/*   Updated: 2021/12/16 15:35:37 by obelkhad         ###   ########.fr       */
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
		*lst = NULL;
	}
}


char	*get_next_line(int fd)
{
	t_list	*list;
	t_list	*temp;
	char	*buf;
	int		read_value;

	if (fd == -1)
		return NULL;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	read_value = read(fd, buf, BUFFER_SIZE);
	if (read_value <= 0)
	{
		free(buf);
		return NULL;
	}
	buf[read_value] = '\0';
	list = ft_lstnew(buf, check_end_of_line(buf));
	temp = list;
	while (check_end_of_line(buf) == BUFFER_SIZE)
	{
		if (read(fd, buf, BUFFER_SIZE) == -1)
		{
			return NULL;
		}
		buf[read_value] = '\0';
		ft_lstadd_bask(&list, ft_lstnew(buf, check_end_of_line(buf)));
		list = list->next;
	}
	return (list = temp, ft_lst_to_string(&list, &buf, check_end_of_line(buf)));
}
