/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:20:15 by obelkhad          #+#    #+#             */
/*   Updated: 2021/12/13 15:42:51 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	check_end_of_line(char	*buf)
{
	size_t	i;

	i = 0;
	while (*(buf + i) != '\n' && i < BUFFER_SIZE)
		i++;
	return i;
}

char	*get_next_line(int fd)
{
	t_list	*node;
	t_list	*temp;
	char	*buf;
	size_t	check;
	size_t	chars_in_line;

	buf = (char *)malloc(BUFFER_SIZE);
	read(fd, buf, BUFFER_SIZE);
	node = malloc(sizeof(t_list));
	check = check_end_of_line(buf);
	node->buffer = malloc(sizeof(char) * check);
	strncpy(node->buffer, buf, check);
	node->next = NULL;
	temp = node;
	chars_in_line = check;
	while (check == BUFFER_SIZE)
	{
		read(fd, buf, BUFFER_SIZE);
		check = check_end_of_line(buf);
		chars_in_line += check;
		ft_lstadd_bask(&node, ft_lstnew(buf));
		node = node->next;
	}
	node = temp;
	printf("%s",ft_lst_to_string(node, chars_in_line));
	return (ft_lst_to_string(node, chars_in_line));
}