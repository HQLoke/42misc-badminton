/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmr_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:15:51 by hloke             #+#    #+#             */
/*   Updated: 2022/05/31 14:38:26 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

//* Formula:
//* (lose team MMR / win team MMR) * (42) * ((score_diff/100) + 1) + 
//* (streak * 2)
//* Streak point is added only when winstreak >= 3
//* Temp[4] is team A score, temp[5] is team B score
int	mmr_calc(char **temp)
{
	float	losemmr;
	float	winmmr;
	float	ascore;
	float	bscore;
	float	retval;

	ascore = (float)atoi(temp[4]);
	bscore = (float)atoi(temp[5]);
	if (ascore > bscore)
	{
		losemmr = (float)ft_atoi(player_get(temp[2], mmrpoints)) + \
		(float)ft_atoi(player_get(temp[3], mmrpoints));
		winmmr = (float)ft_atoi(player_get(temp[0], mmrpoints)) + \
		(float)ft_atoi(player_get(temp[1], mmrpoints));
	}
	else
	{
		losemmr = (float)ft_atoi(player_get(temp[0], mmrpoints)) + \
		(float)ft_atoi(player_get(temp[1], mmrpoints));
		winmmr = (float)ft_atoi(player_get(temp[2], mmrpoints)) + \
		(float)ft_atoi(player_get(temp[3], mmrpoints));
	}
	retval = (losemmr / winmmr) * 42 * (fabsl(ascore - bscore) / 100 + 1);
	return ((int)retval);
}
