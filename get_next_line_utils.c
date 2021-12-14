/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:38:41 by obelkhad          #+#    #+#             */
/*   Updated: 2021/12/14 16:28:31 by obelkhad         ###   ########.fr       */
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

t_list	*ft_lstnew(char *buffred)
{
	t_list	*node;
	size_t	check;

	check = check_end_of_line(buffred);
	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	if (buffred[check] == '\n')
	{
		node->buffer = malloc(sizeof(char) * (check + 1));
		strncpy(node->buffer, buffred, check + 1);
	}
	else
	{
		node->buffer = malloc(sizeof(char) * check);
		strncpy(node->buffer, buffred, check);
	}
	node->next = NULL;
	return (node);
}

char	*ft_strjoin(char *line, char * lost_chars)
{
	size_t		total_chars;
	size_t		index;
	char		*result;

	index = 0;
	total_chars = strlen(line) + strlen(lost_chars);
	result = malloc(sizeof(char) * total_chars);
	strncpy(result + index, lost_chars, strlen(lost_chars));
	index += strlen(lost_chars);
	strncpy(result + index, line, strlen(line));


	/////////////////////////// free los_chars and line ;


	return (result);
}

char	*creat_line(t_list *lst, size_t chars_in_line)
{
	char	*result;
	size_t	i;
	size_t	check;

	i = 0;
	check = 0;
	result = malloc(sizeof(char) * (chars_in_line + 1));
	while (lst)
	{
		i += check;
		check = check_end_of_line(lst->buffer);
		strncpy(result + i, lst->buffer, check);
		lst = lst->next;
	}
	//result[i] = '\n';



	////////////////////////////// free list ;


	return (result);
}


char	*ft_lst_to_string(t_list *lst, size_t chars_in_line, char *buffer, size_t index)
{
	static char	*lost_chars;
	char		*line;
	char		*result;
	size_t 		i;
	size_t 		j;

	i = 0;
	j = index;
	while (j++ < BUFFER_SIZE - 1)  // index = 1    | D  \n  ?  ?
		i++;                       // 2		     	 0   1  2  3
	if (i == 0)
	{
		line = creat_line(lst, chars_in_line);
		if (lost_chars)
		{
			result = malloc(sizeof(char) * (strlen(line) + strlen(lost_chars)));
			result = ft_strjoin(line,lost_chars); // result = lost_chars + line;
			//free lost_chars
			//free line
			return (result);
		}
	}
	else
	{
		line = creat_line(lst, chars_in_line);
		if (lost_chars)
		{
			result = malloc(sizeof(char) * (strlen(line) + strlen(lost_chars)));
			result = ft_strjoin(line,lost_chars); // result = lost_chars + line;
			//free lost_chars
			//free line
			return (result);
		}
		lost_chars = malloc(sizeof(char) * i);
		strncpy(lost_chars, buffer + (index + 1), BUFFER_SIZE - index - 1);
	}
	return (line);
}

// char	*ft_lst_to_string(t_list *lst, size_t chars_in_line, char *buffer, size_t index)
// {
// 	char	*line;
// 	char	*lost_chars;
// 	size_t 	i;
// 	size_t 	j;

// 	i = 0;
// 	j = index;
// 	while (j < BUFFER_SIZE)  // index = 1    | D  \n  ?  ?
// 	{
// 		i++;                 // 2			    0   1  2  3
// 		j++;
// 	}
// 	if (i == 0)
// 	{
// 		line = creat_line(lst, chars_in_line);
// 	}
// 	else
// 	{
// 		lost_chars = malloc(sizeof(char) * i);
// 		strncpy(lost_chars, buffer + (index + 1), BUFFER_SIZE - index - 1);
// 		line = creat_line(lst, chars_in_line);
// 		return (ft_strjoin(line,lost_chars));
// 	}
// 	return (line);
// }


// void	creat_line(t_list *lst, size_t chars_in_line, char **line, int i)
// {
// 	*line = (char *)malloc(sizeof(char) * (chars_in_line + 1));
// 	while (lst)
// 	{
// 		strncpy((*line + i), lst->buffer, check_end_of_line(lst->buffer));
// 		i += check_end_of_line(lst->buffer);
// 		lst = lst->next;
// 	}
// 	(*line)[i] = '\n';
// }
// char	*ft_lst_to_string(t_list *lst, size_t chars_in_line)
// {
// 	char	*line;
// 	size_t i;

// 	i = 0;
	
// 	creat_line(lst, chars_in_line, &line, i);
	
// 	line = (char *)malloc(sizeof(char) * (chars_in_line + 1));
// 	while (lst)
// 	{
// 		strncpy(line + i, lst->buffer, check_end_of_line(lst->buffer));
// 		lst = lst->next;
// 		i += BUFFER_SIZE;
// 	}
// 	line[i] = '\n';
// 	return (line);
// }