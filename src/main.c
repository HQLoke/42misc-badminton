/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:48:01 by hloke             #+#    #+#             */
/*   Updated: 2022/05/31 15:58:38 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

//* Parsing a match file is the most important command. Must be correct before
//* creating other commands.
//* 
static int	teach_them(void)
{
	// printf("Usage: ./badminton [option] ...\n");
	// printf("\nList of options:\n");
	// printf("--player-add  : Add a new player(s)\n");
	// printf("Usage: ./badminton --player-add [player1] ...\n\n");
	// printf("--player-del  : Delete an existing player(s)\n");
	// printf("Usage: ./badminton --player-del [player1] ...\n\n");
	// printf("--player-reset: Reset the score of an existing player(s)\n");
	// printf("Usage: ./badminton --player-reset [player1] ...\n\n");
	// printf("--match-add   : Add all matches in a file to match history\n");
	// printf("Usage: ./badminton --match-add [match file]\n\n");
	printf("Usage: ./badminton [path_to_match_file]\n");
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (teach_them());
	init();
	match_add(argv[1]);
	player_sort(mmrpoints);

	int fd_player;
	
	fd_player = ft_open("data/player_data.txt", O_WRONLY | O_TRUNC, 0);
	int	i = -1;
	while (g_data->player[++i] != NULL)
	{
		int j = 0;
		while (g_data->player[i][j] != NULL)
		{
			ft_putstr_fd(g_data->player[i][j++], fd_player);
			ft_putchar_fd(' ', fd_player);
		}
		ft_putchar_fd('\n', fd_player);
	}
	close (fd_player);

	return (0);
}
