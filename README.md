# About
This is an unbeatable Tic  Tac Toe Single player VS Computer Game, developed in C++ by Naman Kumar.

The game always end up in a tie or computer winning the game. The algorithm is developed such that it leaves no chances with the player to win any game out of the 9! games that can be played on a 3 by 3 grid, whosoever goes first. Moreover the algorithm takes an attacking move when the computer's turn comes, increasing the winning chances of the computer.

The algorithm of this game uses all the tricks which one use while playing with pen & paper. One can do mistake but this algorithm never does one. 

#How It Works?
Well this game uses the same method to decide the computer's moves same as the 3 step process we go through for taking a move at any stage of the game:

    1) We analyze if we are winning by taking a move, in any of the 3 rows or the 3 columns or the 2 diagonals. If winning, then we thake the required the move and wins the game.
  
    2) If we are not winning, that means if the first step fails in taking any move, we then analyze if the opponent is going to win in his next turn. If found, then we take the required move to block the opponent from winning the game. 
  
    3) Now, if neither the opponent nor ourselves our winning, then we take such a move that will lead us to a win in future.

The same above method is used by the game to analyze the stage the decide the computer's move. Using simple functions in c++.

The AI(int b) controlls the computer's move and is called when the computer's turn comes. The 3 different functions for each step in the process of deciding the move are called in the AI(int b), in the required order:

    1) defend(y,t,b): (Winning move) Checks if the computer is having a possible winning move. Take the step and wins.
    
    2) defend(t,y,b): (Defending move) Checks if the player (opponent) have a possible winning move, takes a step as to block the player.
    
    3) attack(): (Atacking move) Take a step such that it have winning possibilities in future moves.
    
Some other functions are being used in the game as to build up the interface and make the game work are:

    1) print(): Print the grid (array a[3][3]).
    
    2) check(): Checks if anyone won. First checkes all three rows and columns then both the diagonals.
    
    3) pin(): Takes input from the player.
    
    4) again(): At the end asks the player if want to play the game again.

#How To Play?
Playing this game is not a big deal. The first step is to choose your turn. Input '1' to take the first turn or '2' to take the second and let the computer take the first turn. 

After selecting the turn, the player's and the computer's symbol will appear on the screen according to their turn, that can be '1' or '2'. 

Next the grid will appear. The zero represent the empty space. To take a move, enter "row<space>column" number. Example for taking the move at top left block input "1 1".

At the end of total of 9 moves, including both of the player and the computer, any one of the 3 things may be displayed on your console screen:

    1) Computer WON, You LOOSE!
    
    2) TIE!
    
    3) Congratulations, You WON!

Sorry but the last one will never be displayed because you are never gonna win. 

Next, the computer will ask if you want to play the game again, input 'y' or'Y' to play again, or it will exit. 
