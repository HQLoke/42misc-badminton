/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:48:04 by hloke             #+#    #+#             */
/*   Updated: 2022/05/31 16:09:53 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

int	match_add(char *pathname)
{
	int		fd;
	int		mmr;
	char	*tmp;
	char	**temp;

	fd = ft_open(pathname, O_RDONLY, 0);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		temp = ft_split(tmp, ' ');
		player_add(temp[0]);
		player_add(temp[1]);
		player_add(temp[2]);
		player_add(temp[3]);

		mmr = mmr_calc(temp);
		if (ft_atoi(temp[4]) > ft_atoi(temp[5]))
		{
			player_set(temp[0], win, mmr);
			player_set(temp[1], win, mmr);
			player_set(temp[2], lose, mmr);
			player_set(temp[3], lose, mmr);
		}
		else
		{
			player_set(temp[2], win, mmr);
			player_set(temp[3], win, mmr);
			player_set(temp[0], lose, mmr);
			player_set(temp[1], lose, mmr);
		}

		ft_memdel(temp, free);
		free(tmp);
		tmp = get_next_line(fd);
	}
	ft_close(fd);
	return (1);
}
