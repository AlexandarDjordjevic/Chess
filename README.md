# Playing chess
Create a simple game for playing chess. It should be a simple console application with no GUI.
## Playing
Application should be a console application where each player could enter its move. Application will display the name of the player in the console and expect a valid move to be entered. For example:
[White]: f2:f4
[Black]: f7:f5
[White]:

In the above example white player entered f2:f4 move (meaning move figure from f2 to f4), black player entered f7:f5 (move figure from f7 to f5). Application is waiting on for white player to enter his move.

Application needs to validate each move: is starting position valid (is there a figure on table for current player) and is target position valid (can figure be moved on that position). For example f2:f5 is not a valid move since pion cannot move 3 places forward. If the move is not valid, the application should not accept the move, it should write an error to the console and request a valid move from the current player. For example:
[White]: f2:f5
Not a valid move
[White]:

Note: when validating a move application should take into account can the figure be moved on target place at all (pion cannot move backward, bishop can only move diagonal etc). If there is a figure on target place, move is only possible if that figure is from the opponent player in which case the current player takes the opponent's figure.
## Check and checkmate
Application should detect situations like: check or checkmate. In both cases the application should write a message in the console. For example:
[White]: f2:f4
Check
[Black]: 

In case the check application should validate that the player's next move has not produced a check again - that is not a valid move.

In the case of the checkmate game is over and the application should write the name of the winner and exit.

## Game end
Game ends in case of the checkmate or if current player types “resign” - it means that the player thinks the opponent has a strong position and there is no much sense to continue.

**WRITE CODE AS IT IS A PRODUCTION READY CODE - COVER EDGE CASES, WRITE UNIT TESTS**
