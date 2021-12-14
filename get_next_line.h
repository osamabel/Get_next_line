/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:11:00 by obelkhad          #+#    #+#             */
/*   Updated: 2021/12/14 16:28:38 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

char	*get_next_line(int fd);
size_t	check_end_of_line(char	*buf);

typedef struct s_list
{
	char	*buffer;
	struct s_list *next;
}	t_list;

void	ft_lstadd_bask(t_list **lst, t_list *new);
t_list	*ft_lstnew(char *buffred);
void	ft_lstprint(t_list *lst);
char	*ft_lst_to_string(t_list *lst, size_t chars_in_line, char *buffer, size_t index);
char	*creat_line(t_list *lst, size_t chars_in_line);
char	*ft_strjoin(char *line, char * lost_chars);
#endif