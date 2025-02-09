#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char board[5][5] = {{' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' '}};

char boardBack[5][5] = {{' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' '}};

int column, row;
int turn = 1;
int start = 1;
char player = '1';

int state = 0;

void displayBoard();
void displayBoardBack();
void moveAgent(int row,int column, char player);
int checkWin();

void feature1(int row, int column);


int main(void){

    board[0][1] = 'J';
    board[0][2] = 'Q';
    board[0][3] = 'K';

    board[4][1] = 'J';
    board[4][2] = 'Q';
    board[4][3] = 'K';

    boardBack[0][1] = '1';
    boardBack[0][3] = '1';
    boardBack[0][2] = '1';

    boardBack[4][1] = '2';
    boardBack[4][2] = '2';
    boardBack[4][3] = '2';

    //random position boom
    srand(time(NULL));   
    int r1 = rand();    
    int r2 = rand();     
    r1 = r1%5;
    r2 = r2%5;
    while (boardBack[r1][r2] != ' ')
    {
        r1 = rand();    
        r2 = rand();     
        r1 = r1%5;
        r2 = r2%5;
    }
    boardBack[r1][r2] = 'B';
    
    while (start == 1) {
        // checkWin();
        

        displayBoardBack();
        displayBoard();

        printf("Player %c, select agent\n",player);

        printf("Enter the row [1-5]: ");
        scanf("%d", &row);

        printf("Enter the column [1-5]: ");
        scanf("%d", &column);

        moveAgent(row-1,column-1,player);

        if(state > 0){
            state -= 1;
        }
        else if(player == '2')
            player = '1';
        else
            player ='2';

        // printf(checkWin());
        if(checkWin() == 1){

            if( player == '1')
                player = '2';
            else
                player ='1';

            printf("!!!! Plyer %c WIN !!!!",player);
            displayBoard();
            start = 0;
        }

    }

}


void displayBoard() {

    printf("\n  ____________________\n");
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            if(j == 0){
                int num = i+1;
                printf("%d| %c ",num, board[i][j]);
            }
            else{
                printf("| %c ", board[i][j]);

            }

        }

        printf("|");
        printf("\n  ____________________\n");

    }
    printf("  1   2   3   4   5\n");

}


void displayBoardBack() {

    printf("\n  ____________________\n");
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            if(j == 0){
                int num = i+1;
                printf("%d| %c ",num, boardBack[i][j]);
            }
            else{
                printf("| %c ", boardBack[i][j]);

            }

        }

        printf("|");
        printf("\n  ____________________\n");

    }
    printf("  1   2   3   4   5\n");

}


void moveAgent(int row,int column, char player) {

    int movement = 0;

        if (boardBack[row][column] == player) {

            printf("\n1)Up\n2)Left\n3)Right\n4)Down\nSelect your movement :");
            scanf("%d", &movement);

            switch (movement) {
                case 1:
                    if(boardBack[row-1][column] == 'B'){
                        feature1(row, column);
                        board[row][column] = ' ';
                        boardBack[row][column] = ' ';
                        boardBack[row-1][column] = ' ';
                    }

                    else if(board[row-1][column] == ' ' || 
                    (board[row-1][column] == 'K' && board[row][column] == 'J') || 
                    (board[row-1][column] == 'J' && board[row][column] == 'Q') || 
                    (board[row-1][column] == 'Q' && board[row][column] == 'K')){
                            
                        board[row-1][column] = board[row][column];
                        board[row][column] = ' ';
                        boardBack[row-1][column] = boardBack[row][column];
                        boardBack[row][column] = ' ';
                        turn++;  
                    }
                    else if(board[row-1][column] == board[row][column] ){
                        board[row-1][column] = ' ';
                        board[row][column] = ' ';
                        boardBack[row-1][column] = ' ';
                        boardBack[row][column] = ' ';
                    }
                    else{
                        printf("!!! Please select again !!!\n\n");
                    }

                    break;

                case 2:
                    if(boardBack[row][column-1] == 'B'){
                        feature1(row, column);
                        board[row][column] = ' ';
                        boardBack[row][column] = ' ';
                        boardBack[row][column-1] = ' ';
                    }

                    else if(board[row][column-1] == ' ' || 
                    (board[row][column-1] == 'K' && board[row][column] == 'J') || 
                    (board[row][column-1] == 'J' && board[row][column] == 'Q') || 
                    (board[row][column-1] == 'Q' && board[row][column] == 'K')){
                        
                        board[row][column-1] = board[row][column];
                        board[row][column] = ' ';
                        boardBack[row][column-1] = boardBack[row][column];
                        boardBack[row][column] = ' ';
                        turn++;    
                        
                    }

                    else if(board[row][column-1] == board[row][column] ){
                        board[row][column-1] = ' ';
                        board[row][column] = ' ';
                        boardBack[row][column-1] = ' ';
                        boardBack[row][column] = ' ';
                    }

                    else{
                        printf("\n!!! Please select again !!!\n");
                    }
                    break;

                case 3:

                    if(boardBack[row][column+1] == 'B'){
                        feature1(row, column);
                        board[row][column] = ' ';
                        boardBack[row][column] = ' ';
                        boardBack[row][column+1] = ' ';
                    }

                    else if(board[row][column+1] == ' ' || 
                    (board[row][column+1] == 'K' && board[row][column] == 'J') || 
                    (board[row][column+1] == 'J' && board[row][column] == 'Q') || 
                    (board[row][column+1] == 'Q' && board[row][column] == 'K')){

                            board[row][column+1] = board[row][column];
                            board[row][column] = ' ';
                            boardBack[row][column+1] = boardBack[row][column];
                            boardBack[row][column] = ' ';
                            turn++;      
                    }
                    else if(board[row][column+1] == board[row][column] ){
                        board[row][column+1] = ' ';
                        board[row][column] = ' ';
                        boardBack[row][column+1] = ' ';
                        boardBack[row][column] = ' ';
                    }

                    else{
                        printf("!!! Please select again !!!\n\n");
                    }
                    break;

                case 4:

                    if(boardBack[row+1][column] == 'B'){
                        feature1(row, column);
                        board[row][column] = ' ';
                        boardBack[row][column] = ' ';
                        boardBack[row+1][column] = ' ';
                    }

                    else if(board[row+1][column] == ' ' || 
                    (board[row+1][column] == 'K' && board[row][column] == 'J') || 
                    (board[row+1][column] == 'J' && board[row][column] == 'Q') || 
                    (board[row+1][column] == 'Q' && board[row][column] == 'K')){

                            board[row+1][column] = board[row][column];
                            board[row][column] = ' ';
                            boardBack[row+1][column] = boardBack[row][column];
                            boardBack[row][column] = ' ';
                            turn++;   
                    }

                    else if(board[row+1][column] == board[row][column] ){
                        board[row+1][column] = ' ';
                        board[row][column] = ' ';
                        boardBack[row+1][column] = ' ';
                        boardBack[row][column] = ' ';
                    }

                    else{
                        printf("!!! Please select again !!!\n\n");
                    }
                    break;
                
                }
        }

        else{
            printf("Not your agent please select again !!!\n");
        }
}

int  checkWin(){
    int count = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 'J' ||
                board[i][j] == 'Q' ||
                board[i][j] == 'K') {
                count++;
            }
        }
    }
    return count;
}


void feature1(int row, int column){
    //check fall boom
    printf("\n\nFalling into a bomb crater\n");

    //set positoion
    if (board[row][column] == 'J' &&  boardBack[row][column] == '1')
    {
        board[0][1] = 'J';
        boardBack[0][1] = '1';
    }
    else if (board[row][column] == 'Q' &&  boardBack[row][column] == '1')
    {
        board[0][2] = 'Q';
        boardBack[0][2] = '1';
    }
    else if (board[row][column] == 'K' &&  boardBack[row][column] == '1')
    {
        board[0][3] = 'K';
        boardBack[0][3] = '1';
    }

    else if (board[row][column] == 'J' &&  boardBack[row][column] == '2')
    {
        board[4][1] = 'J';
        boardBack[4][1] = '2';
    }
    else if (board[row][column] == 'Q' &&  boardBack[row][column] == '2')
    {
        board[4][2] = 'Q';
        boardBack[4][2] = '2';
    }
    else if (board[row][column] == 'K' &&  boardBack[row][column] == '2')
    {
        board[4][3] = 'K';
        boardBack[4][3] = '2';
    }
    
    //fall go to start point and stop 1 turn
    //enemy play 2 turn
    state = 2;
    if(player == '2')
        player = '1';
    else
        player ='2';
}