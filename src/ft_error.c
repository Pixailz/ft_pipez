/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 00:58:36 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/05 16:21:28 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <errno.h>
#include "ft_printf.h"

int	ft_error(char *msg)
{
	if (errno)
	{
		perror(msg);
		exit(errno);
	}
	else
	{
		ft_printf("ERROR : %s\n", msg);
		exit(1);
	}
}
