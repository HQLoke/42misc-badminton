This program calculates the ranking of each player after each badminton match.
New player starts with 1000 points.

There are two data files: 
 i) player_data.txt
ii) match_history.txt

Player data format:
[intra ID] [MMR points] [Highest MMR] [Current win streak] [Total wins] [Matches played] [Win rate]

Match history format:
[Day date] [playerA playerB] [playerC playerD] [team1score : team2score]

Main functions:
1) --player-add (Add a new player. Print exist if error)
2) --player-del (Delete an existing player. Print doesn't exist if error)
3) --player-reset (Reset the score of an existing player. Print doesn't exist if error)

Example:
./badminton --player-add wting edlim hyun-zhe
./badminton --player-del wting edlim hyun-zhe
./badminton --player-reset wting edlim hyun-zhe

4) --match-add (Calculate the MMR score after every match)

Example:
./badminton --match-add hloke wting leu-lee tzi-qi 21 19

Formula for MMR calculation:
(lose team MMR / win team MMR) * (42) * ((score_diff/100) + 1) + 
(winstreak * 2)

Winstreak point is added only when winstreak >= 3

Error handling:
1) Invalid option
2)