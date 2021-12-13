/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:38:41 by obelkhad          #+#    #+#             */
/*   Updated: 2021/12/13 15:42:13 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

void	ft_lstadd_bask(t_list **lst, t_list *new)
{
	t_list *head;

	if (lst && new)
	{
		if (!*lst)
			*lst = new;
		else
		{
			head = (*lst);
			while (head->next)
				head = head->next;
			head->next = new;
		}
	}
}

t_list	*ft_lstnew(char *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->buffer = malloc(sizeof(char) * BUFFER_SIZE);
	strncpy(node->buffer, content, check_end_of_line(content));
	node->next = NULL;
	return (node);
}

void	ft_lstprint(t_list *lst)
{
	while(lst)
	{
		printf("%s\n",lst->buffer);
		lst = lst->next;
	}
}

char	*ft_lst_to_string(t_list *lst, size_t chars_in_line)
{
	char	*line;
	size_t 	i;

	i = 0;
	line = (char *)malloc(sizeof(char) * (chars_in_line + 1));
	while (lst)
	{
		strncpy(line + i, lst->buffer, check_end_of_line(lst->buffer));
		lst = lst->next;
		i += BUFFER_SIZE;
	}
	line[i] = '\0';
	return (line);
}