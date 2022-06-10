/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:48:38 by hloke             #+#    #+#             */
/*   Updated: 2022/06/05 14:53:02 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

//* Set the updated stats back to the player
static void	stat_set(char **player, int stats[5], float wr)
{
	char	*buffer;

	buffer = calloc(10, sizeof(char));
	if (wr == 100.0)
		gcvt(wr, 4, buffer);
	else if (wr >= 10.0 && wr < 100.0)
		gcvt(wr, 3, buffer);
	else
		gcvt(wr, 2, buffer);
	player[mmrpoints] = ft_itoa(stats[mmrpoints]);
	player[highestmmr] = ft_itoa(stats[highestmmr]);
	player[currentwinstreak] = ft_itoa(stats[currentwinstreak]);
	player[totalwins] = ft_itoa(stats[totalwins]);
	player[matchesplayed] = ft_itoa(stats[matchesplayed]);
	player[winrate] = buffer;
}

//* stats[5] contains int variables:
//* mmrpoints, highestmmr, currentwinstreak, totalwins, matchesplayed
//* wr = winrate
static void	stat_init(char **player, int stats[5], float *wr)
{
	stats[mmrpoints] = atoi(player[mmrpoints]);
	stats[highestmmr] = atoi(player[highestmmr]);
	stats[currentwinstreak] = atoi(player[currentwinstreak]);
	stats[totalwins] = atoi(player[totalwins]);
	stats[matchesplayed] = atoi(player[matchesplayed]);
	*wr = atof(player[winrate]);
}

//* Set player stats
//* Outcome = win or lose
//* MMR = if win, increment mmr, else decrement mmr
//* Returns 0 if player's stats are successfully changes, else returns -1
int	player_set(char *name, int outcome, int mmr)
{
	int		i;
	int		stats[6];
	float	winrate;

	i = 0;
	while (g_data->player[i] != NULL)
	{
		if (strcmp(g_data->player[i][0], name) == 0)
		{
			stat_init(g_data->player[i], stats, &winrate);
			if (outcome == win)
			{
				stats[currentwinstreak] += 1;
				stats[totalwins] += 1;
				stats[mmrpoints] += mmr;
				if (stats[currentwinstreak] >= 3)
					stats[mmrpoints] += stats[currentwinstreak] * 2;
				if (stats[mmrpoints] > stats[highestmmr])
					stats[highestmmr] = stats[mmrpoints];
			}
			else
			{
				stats[mmrpoints] -= mmr;
				if (stats[mmrpoints] < 300)
					stats[mmrpoints] = 300;
				stats[currentwinstreak] = 0;
			}
			stats[matchesplayed] += 1;
			winrate = (float)stats[totalwins] * 100.0 / (float)stats[matchesplayed];
			stat_set(g_data->player[i], stats, winrate);
			return (0);
		}
		i += 1;
	}
	return (-1);
}
