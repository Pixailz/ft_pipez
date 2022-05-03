/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:39:26 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/03 23:42:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* ########################################################################## */
/* LIBRARY */
/* ####### */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <stdint.h>

/* ########################################################################## */

/* ########################################################################## */
/* UTILS */
/* ##### */

char	**ft_split(char const *s, char c);
char	*ft_memjoin(char *s1, char *s2);
char	*ft_memchr(char *buf, unsigned char c);
char	*ft_strtok(char *str, char *token);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, const char *src);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(char *s);
size_t	ft_strcspn(char *s, const char *accepts);
size_t	ft_strspn(char *s, const char *accepts);
int		ft_get_words(char const *str, char c);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_puthex(unsigned long n, char format);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_error(char *msg);

/* ########################################################################## */

#endif
