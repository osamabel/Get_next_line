/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:20:15 by obelkhad          #+#    #+#             */
/*   Updated: 2021/12/14 16:28:28 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	check_end_of_line(char	*buf)
{
	size_t	i;

	i = 0;
	while (buf[i] != '\n' && i < BUFFER_SIZE)
		i++;
	return i;
}

char	*get_next_line(int fd)
{
	t_list	*list;
	t_list	*temp;
	char	*buf;
	size_t	check;
	size_t	chars_in_line;

	buf = (char *)malloc(BUFFER_SIZE);
	read(fd, buf, BUFFER_SIZE);
	list = malloc(sizeof(t_list));
	temp = list;
	check = check_end_of_line(buf);
	list->buffer = malloc(sizeof(char) * check);
	strncpy(list->buffer, buf, check);
	list->next = NULL;
	chars_in_line = check;

	while (check == BUFFER_SIZE)
	{
		read(fd, buf, BUFFER_SIZE);     		// D \n ? ?
		check = check_end_of_line(buf); 		// 1
		chars_in_line += check;         		// 17
		ft_lstadd_bask(&list, ft_lstnew(buf));  // ["blabla"]-->["D"]
		list = list->next;
	}
	list = temp;
	// saving the lost chars from buf
	// buf(D, \n, ? ,?)  +  check(1) + BUF_SIZE = 4





	return (ft_lst_to_string(list, chars_in_line, buf, check));
	//return ("ffff");
}