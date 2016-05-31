# 315-individual-project
##Achievement Tracker

This Project simulates an achievement tracker similar to ones used by Steam, Xbox, or Playstation. This project Parsers command line messages which are piped through a text for ease of testing. The following lists the commands that work for this program:

###AddPlayer <Player ID> <Player Name>
Add player to the database. <Player ID> is a positive integer identifier for the player. <Player Name> is a string enclosed by double quotes ("Andruid Kerne"). <Player Name> may contain special characters (excluding double quote).
 
###AddGame <Game ID> <Game Name>
Add game to the database. <Game ID> is a positive integer identifier for the game. <Game Name> is a string enclosed by double quotes (i.e. "Mirror's Edge"). <Game Name> may contain special characters (excluding double quote).

###AddAchievement <Game ID> <Achievement ID> <Achievement Name> <Achievement Points>
Add achievement to the game denoted by <Game ID>. <Achievement ID> is an integer identifier for the achievement. <Achievement Name> is a string enclosed by double quotes (i.e. "Head over heels"). <Achievement Name> may contain special characters (excluding double quote). 
<Achievement Points> is an integer indicating how many gamer points the achievement is worth.

###Plays <Player ID> <Game ID> <Player IGN>
Add entry for player playing a specific game. <Player IGN> is a string identifier for that that player's particular in game name for the specified game, enclosed by double quotes. <Player IGN> may contain special characters (excluding double quote).

###AddFriends <Player ID1> <Player ID2>
Makes players 1 & 2 friends. Friends are mutual.

###Achieve <Player ID> <Game ID> <Achievement ID>
Adds achievement indicated to <Player ID>'s record. Each achievement can only be achieved by a given player for once.

###FriendsWhoPlay <Player ID> <Game ID>
Report which of player's friends play the specified game.

###ComparePlayers <Player ID1> <Player ID2> <Game ID>
Print report comparing player 1 and player 2's achievement records and total achievement scores for the given game. The given game is guaranteed to have been played by both players.

###SummarizePlayer <Player ID>
Print record of all of player's friends, games the player plays, and gamer point totals.

###SummarizeGame <Game ID>
Print a record of all players who play the specified game and the number of times each of its achievements have been accomplished.

###SummarizeAchievement <Game ID> <Achievement ID>
Print a list of all players who have achieved an achievement, and the percentage of players who play that game who have the achievement.

###AchievementRanking
Print a summary ranking all players by their total number of gamer points.

