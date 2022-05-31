/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_player_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:54:19 by hloke             #+#    #+#             */
/*   Updated: 2022/05/31 14:03:12 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

static void test_invalid_player(void)
{
	t_data	data;
	int		i;

	i = -1;
	while (data.player[++i] != NULL)
	{
		int j = 0;
		while (data.player[i][j] != NULL)
			printf("%s ", data.player[i][j++]);
		printf("\n");
	}
}

int	main(void)
{
	test_invalid_player();
	return (0);
}
