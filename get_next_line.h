/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:11:00 by obelkhad          #+#    #+#             */
/*   Updated: 2021/12/16 11:29:01 by obelkhad         ###   ########.fr       */
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
void	ft_strjoin(char **line, char *lost_chars);

typedef struct s_list
{
	char	*buffer;
	struct s_list *next;
}	t_list;

void	ft_lstadd_bask(t_list **lst, t_list *new);
t_list	*ft_lstnew(char *buf, int check);
void	ft_lstprint(t_list *lst);
char	*ft_lst_to_string(t_list **lst, char **buf, size_t index);
void	creat_line(t_list **lst, char **line);
void	ft_lstclear(t_list **lst);
#endif