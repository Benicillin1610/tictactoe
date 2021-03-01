#include <stdio.h>

void print_board (char board[9]);
void game_intro (void);
void play_game (char board[9]);
int check_game_victory (char board[9]);
void check_game_drawn (char board[9]);


int main (void) {

    char board[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

    //Calls out function to introduce the game_intro
    game_intro();

    //Calls out function to print out the initially empty board that will be filled
    print_board(board);

    //For players taking turns to play until a winning combo found and ends it early
    play_game(board);
        
    //Check if the game is a draw or not after all spots are filled:
    check_game_drawn(board);   

    
    return 0;

}

//Function to print out the board
void print_board (char board[9]) {

    printf("\n     |   |   ");
    printf("\n   %c | %c | %c\n", board[0], board[1], board[2]);
    printf("-----|---|-----\n");
    printf("   %c | %c | %c\n", board[3], board[4], board[5]);
    printf("-----|---|-----\n");
    printf("   %c | %c | %c", board[6], board[7], board[8]);
    printf("\n     |   |   \n\n");
}

void game_intro (void) {

printf("\nWELCOME TO TIC TAC TOE!\n");
printf("Player 1: X  Player 2: O\n");

}

void play_game (char board[9]) {

    int player_turn = 2;
    //in while loop, calls out function to check the board and say if anyone wins.
    //Also allows player 1 then player 2 then vice versa
    while (player_turn <= 10 && (check_game_victory(board) == -1)) {

        //For player one:
        if (player_turn % 2 == 0) {
        
            printf("PLAYER ONE'S TURN, CHOOSE A LETTER TO PLACE X: ");
            char player_one_placement;
            scanf(" %c", &player_one_placement);  
                      
            
            //Scenario: wrong leter entered or spot already taken           
            //While loop allows user to try again until correct letter          
            while (!((player_one_placement >= 'a' && player_one_placement <= 'i')
            && (player_one_placement == board[player_one_placement - 97]))) {
                
                if (!(player_one_placement >= 'a' && player_one_placement <= 'i')) {
                    printf("WRONG LETTER! PLEASE TRY AGAIN: ");
                }
                
                else if (player_one_placement != board[player_one_placement - 97]) {
                    printf("THIS SPOT HAS ALREADY BEEN TAKEN! PLEASE TRY AGAIN: ");
                }
                
                scanf(" %c", &player_one_placement);               
            }

                     
            //Scenario: correct letter enetered:
            if (player_one_placement >= 'a' 
            && player_one_placement <= 'i') {
                              
                board[player_one_placement - 97] = 'X';                               
                print_board(board);              
            }
        }
        
        //For player two: 
        else if (player_turn % 2 != 0) {
        
            printf("PLAYER TWO'S TURN, CHOOSE A LETTER TO PLACE O: ");
            char player_two_placement;
            scanf(" %c", &player_two_placement);  
                                  
            
            //Scenario: wrong leter entered or spot already taken
            //Can try again until correct letter                       
            while ( !((player_two_placement >= 'a' && player_two_placement <= 'i')
            && (player_two_placement == board[player_two_placement - 97])) ) {
                        
                if (!(player_two_placement >= 'a' && player_two_placement <= 'i')) {
                    printf("WRONG LETTER! PLEASE TRY AGAIN: ");
                }
                
                else if (player_two_placement != board[player_two_placement - 97]) {
                    printf("THIS SPOT HAS ALREADY BEEN TAKEN! PLEASE TRY AGAIN: ");
                }
                scanf(" %c", &player_two_placement);               
            }
            
            //Scenario: correct letter enetered:
            if (player_two_placement >= 'a' 
            && player_two_placement <= 'i') {
                              
                board[player_two_placement - 97] = 'O';                        
                print_board(board);     
                         
            }

        }
   
 
        player_turn++;
    }

}



int check_game_victory (char board[9]) {
            

    //Function to update the board and check if a line is made or not

    //RETURNS "1" FOR ALL WINNING COMBINATIONS:
    //winning by vertical lines: 
    
    if ( (board[0] == board[3] && board[3] == board[6]) && (board[0] == 'X')) {
        printf("GAME OVER! PLAYER ONE WINS!!\n");
        return 1;
    }
    
    else if ( (board[0] == board[3] && board[3] == board[6]) && (board[0] == 'O')) {
        printf("GAME OVER! PLAYER TWO WINS!!\n");
        return 1;
    }
    
    else if ( (board[1] == board[4] && board[4] == board[7]) && (board[1] == 'X')) {
        printf("GAME OVER! PLAYER ONE WINS!!\n");
        return 1;
    }
    
    else if ( (board[1] == board[4] && board[4] == board[7]) && (board[1] == 'O')) {
        printf("GAME OVER! PLAYER TWO WINS!!\n");
        return 1;
    }
    

    
    //winning by horizontal lines: 

    if ( (board[0] == board[1] && board[1] == board[2]) && (board[0] == 'X')) {
        printf("GAME OVER! PLAYER ONE WINS!!\n");
        return 1;
    }
    
    else if ( (board[0] == board[1] && board[1] == board[2]) && (board[0] == 'O')) {
        printf("GAME OVER! PLAYER TWO WINS!!\n");
        return 1;
    }

    else if ( (board[3] == board[4] && board[4] == board[5]) && (board[3] == 'X')) {
        printf("GAME OVER! PLAYER ONE WINS!!\n");
        return 1;
    }
    
    else if ( (board[3] == board[4] && board[4] == board[5]) && (board[3] == 'O')) {
        printf("GAME OVER! PLAYER TWO WINS!!\n");
        return 1;
    }
    

    //winning by diagonal lines
    
    if ( (board[0] == board[4] && board[4] == board[8]) && (board[0] == 'X')) {
        printf("GAME OVER! PLAYER ONE WINS!!\n");
        return 1;
    }
    
    else if ( (board[0] == board[4] && board[4] == board[8]) && (board[0] == 'O')) {
        printf("GAME OVER! PLAYER TWO WINS!!\n");
        return 1;
    }

    
    else if ( (board[2] == board[4] && board[4] == board[6]) && (board[4] == 'X')) {
        printf("GAME OVER! PLAYER ONE WINS!!\n");
        return 1;
    }
    
    else if ( (board[2] == board[4] && board[4] == board[6]) && (board[0] == 'O')) {
        printf("GAME OVER! PLAYER TWO WINS!!\n");
        return 1;
    }
    
    //OTHERWISE, THE GAME WILL CONTINUE UNTIL A WINNING COMBO IS FOUND OR DRAW GAME
    else {
        return -1;
    }
    

}

void check_game_drawn (char board[9]) {

    //RESULT: GAME IS A DRAW AND NO ONE WINS IF ALL OF THE BOARD IS FILLED
    //AND THERE ARE NO "THREE STRAIGHT":
    
    if ((board[0] != 'a' && board[1] != 'b' && board[2] != 'c' 
    && board[3] != 'd' && board[4] != 'e' && board[5] != 'f' 
    && board[6] != 'g' && board[7] != 'h' && board[8] != 'i' ) 
    && (check_game_victory(board) != 1)) {
    
        printf("GAME IS DRAWN, NOBODY WINS!!!\n\n");
    
    }

}

                    
  
  
              



