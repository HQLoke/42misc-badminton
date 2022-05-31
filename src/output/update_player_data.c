/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:02:10 by hloke             #+#    #+#             */
/*   Updated: 2022/05/31 16:09:10 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

void	update_player_data(void)
{
	int	fd_player;
	int	i;
	int	j;

	fd_player = ft_open("data/player_data.txt", O_WRONLY | O_TRUNC, 0);
	i = -1;
	while (g_data->player[++i] != NULL)
	{
		j = 0;
		while (g_data->player[i][j] != NULL)
		{
			ft_putstr_fd(g_data->player[i][j++], fd_player);
			ft_putchar_fd(' ', fd_player);
		}
		ft_putchar_fd('\n', fd_player);
	}
	close (fd_player);
}
