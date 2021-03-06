/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:48:01 by hloke             #+#    #+#             */
/*   Updated: 2022/05/31 16:50:32 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

//* Parsing a match file is the most important command. Must be correct before
//* creating other commands.
//* 
static int	teach_them(void)
{
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
	update_player_data();
	beautiful_output();
	return (0);
}
