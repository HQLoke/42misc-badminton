/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_player_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:25:22 by hloke             #+#    #+#             */
/*   Updated: 2022/05/31 13:59:32 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

t_data *g_data;

static void	test_player_stats(void)
{
	char	*tmp;
	int		retval;

	g_data = calloc(1, sizeof(t_data));
	g_data->player[0] = ft_split("a 1111 1050 1 2 3 11.1", ' ');
	g_data->player[1] = ft_split("b 2222 1060 2 4 6 22.2", ' ');
	retval = 1;
	
	tmp = player_get("a", mmrpoints);
	if (strcmp(tmp, "1111") != 0)
		retval = 0;
	tmp = player_get("a", highestmmr);
	if (strcmp(tmp, "1050") != 0)
		retval = 0;
	tmp = player_get("a", currentwinstreak);
	if (strcmp(tmp, "1") != 0)
		retval = 0;
	tmp = player_get("a", totalwins);
	if (strcmp(tmp, "2") != 0)
		retval = 0;
	tmp = player_get("a", matchesplayed);
	if (strcmp(tmp, "3") != 0)
		retval = 0;
	tmp = player_get("a", winrate);
	if (strcmp(tmp, "11.1") != 0)
		retval = 0;
	
	tmp = player_get("b", mmrpoints);
	if (strcmp(tmp, "2222") != 0)
		retval = 0;
	tmp = player_get("b", highestmmr);
	if (strcmp(tmp, "1060") != 0)
		retval = 0;
	tmp = player_get("b", currentwinstreak);
	if (strcmp(tmp, "2") != 0)
		retval = 0;
	tmp = player_get("b", totalwins);
	if (strcmp(tmp, "4") != 0)
		retval = 0;
	tmp = player_get("b", matchesplayed);
	if (strcmp(tmp, "6") != 0)
		retval = 0;
	tmp = player_get("b", winrate);
	if (strcmp(tmp, "22.2") != 0)
		retval = 0;

	if (retval == 1)
		printf("OK\n");
	else
		printf("Error: player_get needs fixing\n");
}

int main(void)
{
	test_player_stats();
	return (0);
}