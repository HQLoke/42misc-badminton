/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:54:42 by hloke             #+#    #+#             */
/*   Updated: 2022/05/31 15:58:21 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

void	init(void)
{
	int		i;
	int		fd_player;
	char	*tmp;

	g_data = calloc(1, sizeof(t_data));
	fd_player = ft_open("data/player_data.txt", O_RDONLY, 0);
	i = 0;
	tmp = get_next_line(fd_player);
	while (tmp != NULL)
	{
		ft_memmove(tmp + (ft_strlen(tmp) - 2), tmp, 1);
		g_data->player[i++] = ft_split(tmp, ' ');
		free (tmp);
		tmp = get_next_line(fd_player);
	}
	g_data->num_player = i;
	ft_close(fd_player);
}
