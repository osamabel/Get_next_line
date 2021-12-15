/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:38:41 by obelkhad          #+#    #+#             */
/*   Updated: 2021/12/15 17:48:31 by obelkhad         ###   ########.fr       */
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

t_list	*ft_lstnew(char *buf, int check)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	if (buf[check] == '\n')
	{
		node->buffer = malloc(sizeof(char) * (check + 2));
		strncpy(node->buffer, buf, check + 1);
		(node->buffer)[check + 1] = '\0';
		node->next = NULL;
	}
	else
	{
		node->buffer = malloc(sizeof(char) * (check + 1));
		strncpy(node->buffer, buf, check + 1);
		node->next = NULL;
	}
	return (node);
}

void	creat_line(t_list **lst, char **line, size_t chars_in_line)
{
	size_t	i;
	size_t	check;
	t_list	*node;

	node = *lst;
	i = 0;
	check = 0;
	*line = malloc(sizeof(char) * (chars_in_line + 2));
	while (*lst)
	{
		i += check;
		check = check_end_of_line((*lst)->buffer);
		strncpy(*line + i, (*lst)->buffer, check);
		*lst = (*lst)->next;
	}
	i += check;
	*(*line + i) = '\n';
	*(*line + i + 1) = '\0';
	ft_lstclear(&node);
}

void	ft_strjoin(char **line, char *lost_chars)
{
	size_t		index;
	char		*result;

	index = 0;
	result = *line;
	*line = malloc(sizeof(char) * (strlen(result) + strlen(lost_chars) + 1));
	strncpy(*line + index, lost_chars, strlen(lost_chars));
	index += strlen(lost_chars);
	strncpy(*line + index, result, strlen(result));
	free(result);
	*(*line + strlen(*line)) = '\0';
}

char	*ft_lst_to_string(t_list **lst, size_t chars_in_line, char **buf, size_t index)
{
	static char	*lost_chars;
	char		*line;
	size_t 		i;
	size_t 		j;

	i = 0;
	j = index;
	line = NULL;
	while (j++ < BUFFER_SIZE - 1)
		i++;
	creat_line(lst, &line, chars_in_line);
	if (lost_chars)
	{
		ft_strjoin(&line, lost_chars);
		free(lost_chars);
	}
	if (i > 0)
	{
		lost_chars = malloc(sizeof(char) * (i + 1));
		strncpy(lost_chars, *buf + (index + 1), BUFFER_SIZE - index - 1);
		lost_chars[i] = '\0';
	}
	free(*buf);
	return (line);
}
