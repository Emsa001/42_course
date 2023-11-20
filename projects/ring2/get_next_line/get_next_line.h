/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:11:41 by escura            #+#    #+#             */
/*   Updated: 2023/11/20 14:51:21 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}					t_list;

int					found_newline(t_list *list);
t_list				*find_last_node(t_list *list);
void				copy_str(t_list *list, char *str);
int					len_to_newline(t_list *list);
char				*get_next_line(int fd);
void				dealloc(t_list **list, t_list *clean_node, char *buf);

#endif
