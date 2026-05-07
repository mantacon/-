#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 6
#define N_DIRECTIONS 8

const int othello_dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int othello_dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void initBoard(char board[][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] = '-';
    }
  }

  board[2][2] = 'W';
  board[2][3] = 'B';
  board[3][2] = 'B';
  board[3][3] = 'W';
  
  // 8 * 8マスの場合
  /* board[3][3] = 'W'; */
  /* board[3][4] = 'B'; */
  /* board[4][3] = 'B'; */
  /* board[4][4] = 'W'; */
}

void printBoard(char board[][N]) {
    for(int i = 0;i < N;i++){
        for(int j = 0; j < N; j++){
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
}

int isFeasible(char board[][N], int x, int y, char player) {
  int n_flips;
  int nx;
  int ny;
  char opponent;
  
  if (player == 'B') opponent = 'W';
  else opponent = 'B';

  if (board[x][y] == 'B' || board[x][y] == 'W') {
    return 0;
  }
  
  for (int i = 0; i < N_DIRECTIONS; i++) {
    n_flips = 0;
    nx = x + othello_dx[i];
    ny = y + othello_dy[i];

    while (nx >= 0 && nx < N && ny >= 0 && ny < N && board[nx][ny] == opponent) {
      nx += othello_dx[i];
      ny += othello_dy[i];
      n_flips++;
    }

    if (nx >= 0 && nx < N && ny >= 0 && ny < N && board[nx][ny] == player && n_flips > 0) {
      return 1;
    }   
  }

  return 0;
}

int canSetStone(char board[][N], char player) { 
  int ok = 0;
  for (int x = 0; x < N; x++) {
    for (int y = 0; y < N; y++) {
      ok = isFeasible(board, x, y, player);
      if (ok) return 1;
    }
  }

  return 0;
}

void updateBoard(char board[][N], int x, int y, char player) {
    char opponent;
    if (player == 'B') opponent = 'W';
    else opponent = 'B';
    for(int i=0;i<N_DIRECTIONS;i++){
        int nx = x;
        int ny = y;
        while(1){
            nx += othello_dx[i];
            ny += othello_dy[i];
            if(!(nx >= 0 && nx < N && ny >= 0 && ny < N)) break;
            if(board[nx][ny] == '-') break;
            if(board[nx][ny] == player){
                for(;;){
                    nx -= othello_dx[i];
                    ny -= othello_dy[i];
                    if(!(nx != x || ny != y)) break;
                    if(board[nx][ny] == opponent) board[nx][ny] = player;
                    
                }
                break;
            }
        }   
    }
    board[x][y] = player;
}

int countStones(char board[][N], char player) {
  int n_stones = 0;
  for (int x = 0; x < N; x++) {
    for (int y = 0; y < N; y++) {
      if (board[x][y] == player) {
	n_stones++;
      }
    }
  }

  return n_stones;
}

int main() {
  srand((unsigned int)time(NULL));
  int x, y, piece_type;
  char board[N][N];
  char player = 'B';
  int pass_count = 0;
  initBoard(board);

  printf("BがあなたでWがコンピュータです\n");
  while (pass_count < 2) {
    int can_set_stone = canSetStone(board, player);
    printBoard(board);
  
    if (!can_set_stone) {
      printf("%cのプレイヤー: どこにも石を置けないのでスキップします\n", player);
      pass_count++;
    }
    else {
      int is_feasible = 0;
      pass_count = 0;
      if(player == 'W'){
        int x2;
        int y2;
        printf("コンピュータのターン\n");
        while(is_feasible == 0){
            x2 = rand() % 6;
            y2 = rand() % 6;
            is_feasible = isFeasible(board,x2,y2,player);
        }
        updateBoard(board, x2, y2, player);
        }
      else{
            do {
	        printf("あなたのターン: どこに石を置きますか?\n");
	        scanf("%d %d", &x, &y);

	        is_feasible = isFeasible(board, x, y, player);
	        if (!is_feasible) printf("%d, %d には置けません\n", x, y);
            } while (!is_feasible);

            updateBoard(board, x, y, player);
        }
    }

    if (player == 'B') player = 'W';
    else player = 'B';
  }

  int n_b_stones = countStones(board, 'B');  
  int n_w_stones = countStones(board, 'W');

  if (n_b_stones > n_w_stones)  {
    printf("ゲーム終了. Bは%d個, Wは%d個. よってBの勝ち!\n", n_b_stones, n_w_stones);  
  }
  else if (n_b_stones < n_w_stones)  {
    printf("ゲーム終了. Bは%d個, Wは%d個. よってWの勝ち!\n", n_b_stones, n_w_stones);  
  }
  else {
    printf("ゲーム終了. Bは%d個, Wは%d個. よって引き分け!\n", n_b_stones, n_w_stones);  
  }
    
  return 0;
}
