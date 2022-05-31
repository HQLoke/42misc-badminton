/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beautiful_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:06:09 by hloke             #+#    #+#             */
/*   Updated: 2022/05/31 16:50:00 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "badminton.h"

static void	print_header(void)
{
	int		fd;
	char	*tmp;

	fd = ft_open("src/output/header", O_RDONLY, 0);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		printf("%s", tmp);
		free (tmp);
		tmp = get_next_line(fd);
	}
	close (fd);
	printf("\n");
}

static void	print_column(void)
{
	printf("+======+==========+=========+=========+========+=======+=========+========+\n");
	printf("| Rank | Intra ID | Current |   Top   |   Win  | Total |  Total  |   Win  |\n");
	printf("|      |          |   MMR   |   MMR   | Streak |  Wins | Matches |  Rate  |\n");
	printf("+======+==========+=========+=========+========+=======+=========+========+\n");
}

void	beautiful_output(void)
{
	int	i;
	int	rank;

	print_header();
	print_column();
	i = 0;
	rank = 1;
	while (g_data->player[i] != NULL)
	{
		printf("| %4i | %8s |  %5s  |  %5s  |  %4s  | %4s  |  %5s  | %5s%% |\n", rank, g_data->player[i][0],  g_data->player[i][1],
		g_data->player[i][2],  g_data->player[i][3],  g_data->player[i][4],  g_data->player[i][5],  g_data->player[i][6]);
		rank += 1;
		i += 1;
	}
	printf("+======+==========+=========+=========+========+=======+=========+========+\n");
}
