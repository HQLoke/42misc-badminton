/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:48:36 by hloke             #+#    #+#             */
/*   Updated: 2022/05/31 16:07:18 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

static void	swap(char **playerA, char **playerB)
{
	char	*tmp;
	int		i;

	i = 0;
	while (playerA[i] != NULL)
	{
		tmp = playerA[i];
		playerA[i] = playerB[i];
		playerB[i] = tmp;
		i += 1;
	}
}

void	player_sort(int stat)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_data->num_player - 1)
	{
		j = 0;
		while (j < g_data->num_player - i - 1)
		{
			if (stat == winrate)
			{
				if (atof(g_data->player[j][stat]) < \
				atof(g_data->player[j + 1][stat]))
					swap(g_data->player[j], g_data->player[j + 1]);
			}
			else
			{
				if (atoi(g_data->player[j][stat]) < \
				atoi(g_data->player[j + 1][stat]))
					swap(g_data->player[j], g_data->player[j + 1]);
			}
			j += 1;
		}
		i += 1;
	}
}
