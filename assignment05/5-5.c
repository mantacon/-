#include <stdio.h>

const int rook_dx[] = {0, 1, 0, -1};
const int rook_dy[] = {1, 0, -1, 0};

const int bishop_dx[] = {1, 1, -1, -1};
const int bishop_dy[] = {1, -1, -1, 1};

void printBoard(int x, int y, int piece_type) {
  char board[9][9];

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      board[i][j] = '-';
    }
  }

  if(piece_type == 0){
    for(int i=0;i<9;i++) board[x][i] = '*';
    for(int i=0;i<9;i++) board[i][y] = '*';
    board[x][y] = 'R';
  }else if(piece_type == 1){
    for(int i=1;x-i>=0 && y+i<9;i++) board[x-i][y+i] = '*';
    for(int i=1;x-1>=0 && y-i>=0;i++) board[x-i][y-i] = '*';
    for(int i=1;x+i<9 && y+i<9;i++) board[x+i][y+i] = '*';
    for(int i=1;x+i<9 && y-i>=0;i++) board[x+i][y-i] = '*';
    board[x][y] = 'B';
  }
  
  
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int x, y, piece_type;
  
  printf("‹î‚ð’u‚­c‚Æ‰¡‚ÌˆÊ’u‚Í?: ");
  scanf("%d %d", &x, &y);
  printf("”z’u‚·‚é‹î‚ª”òŽÔ‚È‚ç0, Šp‚È‚ç1‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢: ");
  scanf("%d", &piece_type);

  if (x  < 0 || x > 8 || y < 0 || y > 8) {
    printf("Input error. x‚Æy‚Í0, ..., 8‚Ì‚Ç‚ê‚©‚É‚µ‚Ä‚­‚¾‚³‚¢\n");
    return 1;
  }
  else if (piece_type != 0 && piece_type != 1) {
    printf("Input error. ‹î‚ÌŽí—Þ‚Í0‚©1‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
    return 1;
  }
  
  printBoard(x, y, piece_type);
  
  return 0;
}
