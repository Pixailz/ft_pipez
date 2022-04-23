/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:14:45 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 03:59:16 by brda-sil         ###   ########.fr       */
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
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

// MAIN
char		*get_next_line(int fd);

// UTILS
size_t		ft_strlen(char *s);
char		*ft_memchr(char *buf, unsigned char c);
char		*ft_memjoin(char *s1, char *s2);
char		*ft_stash(char *s);
char		*ft_read(int fd, char *buf);
char		*ft_line(char *buf);

#endif
