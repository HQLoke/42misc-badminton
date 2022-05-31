/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:48:28 by hloke             #+#    #+#             */
/*   Updated: 2022/05/31 11:42:45 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

static int	remove_player(void)
{
	return (0);
}

//* Returns 0 if player is successfully deleted, else returns 1
int	player_del(char *name)
{
	int	i;
	int	exist;

	i = 0;
	exist = 0;
	while (g_data->player[i] != NULL)
	{
		if (strcmp(g_data->player[i++][0], name) == 0)
			return (remove_player());
	}
	return (1);
}
