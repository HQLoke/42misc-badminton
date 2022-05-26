#include "badminton.h"

static int	teach_them(void)
{
	printf("Usage: ./badminton [option] ...\n");
	printf("\nList of options:\n");
	printf("--player-add  : Add a new player(s)\n");
	printf("Usage: ./badminton --player-add [player1] ...\n\n");
	printf("--player-del  : Delete an existing player(s)\n");
	printf("Usage: ./badminton --player-del [player1] ...\n\n");
	printf("--player-reset: Reset the score of an existing player(s)\n");
	printf("Usage: ./badminton --player-reset [player1] ...\n\n");
	printf("--match-add   : Add a played match to match history\n");
	printf("Usage: ./badminton --match-add [team1 P1] [team1 P2] [team2 P1] "
	"[team2 P2] [team1 score] [team2 score]\n\n");
	printf("--match-del   : Add a played match to history\n");
	printf("Usage: ./badminton --match-del [line number]\n");
	return (1);
}

int	main(int argc, char **argv)
{
	char	**player[PLAYER_SIZE];
	char	*match[MATCH_SIZE];

	(void)argv;
	if (argc < 3)
		return (teach_them());
	int fd = open("data/player_data.txt", O_RDONLY);
	int i = 0;
	char	*tmp;
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		player[i] = ft_split(tmp, ' ');
		i += 1;
		free (tmp);
		tmp = get_next_line(fd);
	}
	return (0);
}
