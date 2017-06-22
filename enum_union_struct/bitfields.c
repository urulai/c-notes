#include <stdio.h>

struct chessboard {
  int _board_colors: 2; /* white and black*/
  int _number_of_players: 2;
  int _pawns: 8;
  int _kings: 2;
  int _queens: 2;
  int _bishops: 2;
  int _knights: 2;
  int _rooks: 2;
};

int main(void)
{
  printf("%zu\n", sizeof(struct chessboard));
  return 0;
}
