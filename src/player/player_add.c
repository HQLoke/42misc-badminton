/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:59:55 by hloke             #+#    #+#             */
/*   Updated: 2022/05/31 11:43:51 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

static int	new_player(char *name)
{
	char	*tmp;

	tmp = ft_strjoin(name, " 1000 1000 0 0 0 0");
	g_data->player[g_data->num_player] = ft_split(tmp, ' ');
	g_data->num_player += 1;
	free (tmp);
	return (0);
}

//* Add new player
//* Returns 1 if player already exists, else returns 0
int	player_add(char *name)
{
	int	i;

	i = 0;
	while (g_data->player[i] != NULL)
	{
		if (strcmp(g_data->player[i++][0], name) == 0)
			return (1);
	}
	return (new_player(name));
}
