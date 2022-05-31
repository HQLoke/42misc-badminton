/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   badminton.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:37:30 by hloke             #+#    #+#             */
/*   Updated: 2022/05/31 14:48:49 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BADMINTON_H
# define BADMINTON_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>
# include "libft.h"

struct s_data	*g_data;

enum	e_player_stats
{
	mmrpoints = 1,
	highestmmr,
	currentwinstreak,
	totalwins,
	matchesplayed,
	winrate
};

enum	e_outcome
{
	lose = 0,
	win = 1
};

typedef struct s_data
{
	int		num_player;
	char	**player[10000];
}	t_data;

//* init/init.c
void	init(void);

//* match/
int		match_add(char *pathname);
int		mmr_calc(char **temp);

//* player/
int		player_add(char *name);
int		player_del(char *name);
char	*player_get(char *name, int stat);
int		player_set(char *name, int outcome, int mmr);
void	player_sort(int stat);

void	player_reset(void);

//* utils/
void	ft_close(int fd);
void	ft_memdel(void *ptr, void (*del)(void *));
int		ft_open(const char *path, int flag, int mode);

#endif