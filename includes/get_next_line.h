/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:14:45 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 18:41:46 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// CONFIG
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 0x100
# endif
# ifndef MAX_FD
#  define MAX_FD 0x400
# endif

// LIBRARY
# include "utils.h"

// MAIN
char	*get_next_line(int fd);
char	*ft_stash(char *s);
char	*ft_read(int fd, char *buf);
char	*ft_line(char *buf);

#endif
