/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:36:01 by mleibeng          #+#    #+#             */
/*   Updated: 2023/12/08 15:01:05 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stash_data
{
	char	*content;
	int		eof;
}	t_stash_data;

char	*get_next_line(int fd);

#endif