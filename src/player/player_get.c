/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:48:14 by hloke             #+#    #+#             */
/*   Updated: 2022/05/31 13:58:12 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

char	*player_get(char *name, int stat)
{
	int	i;

	i = 0;
	while (g_data->player[i] != NULL)
	{
		if (strcmp(g_data->player[i][0], name) == 0)
			return (g_data->player[i][stat]);
		i += 1;
	}
	return (NULL);
}
