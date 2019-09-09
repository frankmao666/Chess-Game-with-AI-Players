# Chess-Game-with-AI-Players
Chess Game with AI Players, C++ 

The game supports graphical displays, so make sure you are able to use graphical applications(X11)
[XQuartz for MacOS and X server such as XMing for Windows.]

This project is a completed chess game implemented with C++ programming language, with 4 different levels of computer players. The game
has the features to print the move histroy (command -history) , ask for an undo (command -undo) and get hints (command -hint).
The game also includes all special moves including en passant, castling and pawn promotion. All rules are following the regular chess game.

There are four levels of AI players.

<game white-player black-player> starts a new game. The parameters <white-player> and <black-player> 
can be either human or computer[1-4].

<resign> concedes the game to your opponent. This is the only way, outside of winning or
drawing the game, to end a game.

A move consists of the command move, followed by the starting and ending coordinates of
the piece to be moved. For example: <move e2 e4>. Castling would specified by the two-
square move for the king: <move e1 g1> or <move e1 c1> for white. Pawn promotion would
additionally specify the piece type to which the pawn is promoted: <move e7 e8 Q>. In the
case of a computer player, the command <move> (without arguments) makes the computer
player make a move.

<setup> enters setup mode, within which you can set up your own initial board congurations.
This can only be done when a game is not currently running. Within setup mode, the
following language is used:
{ <+ K e1> places the piece K (i.e., white king in this case) on the square e1. If a piece is
already on that square, it is replaced. The board should be redisplayed.
{ <- e1> removes the piece from the square e1 and then redisplays the board. If there is no
piece at that square, take no action.
{ <= colour> makes it colour's turn to go next.
{ <done> leaves setup mode.
Upon completion of setup mode, you must verify that the board contains exactly one white
king and exactly one black king; that no pawns are on the rst or last row of the board; and
that neither king is in check. The user cannot leave setup mode until these conditions are
satisfied. We recommend doing setup mode early, as it may facilitate testing.

 King (K) Moves one square in any direction.
 Queen (Q) Moves in any of the eight possible directions, any distance, but cannot move
past any piece that blocks its path.
 Bishop (B) Moves in any of the four diagonal directions, any distance, but cannot move
past any piece that blocks its path.
 Rook (R) Moves in any of the four vertical/horizontal directions, any distance, but cannot
move past any piece that blocks its path.
 Knight (N) If it sits on square (x; y), it can move to square (x+-2; y+-1) or (x+-1; y+-2).
Can "jump over" any piece that blocks its path.
 Pawn (P) Moves one square forward.

A capital letter represents White's piece and a non-capital letter represents Black's piece.

Hope you enjoy and have a nice day!

---Frank Shi
