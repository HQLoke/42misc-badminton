/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:27:47 by hloke             #+#    #+#             */
/*   Updated: 2022/05/27 10:27:55 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

//* If successful, return the file descriptor
int	ft_open(const char *path, int flag, int mode)
{
	int	file_des;

	file_des = open(path, flag, mode);
	if (file_des == -1)
	{
		ft_putstr_fd("ft_open: ", 2);
		perror(path);
		exit (EXIT_FAILURE);
	}
	return (file_des);
}
