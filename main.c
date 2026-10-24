#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void clear_terminal(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hConsole, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hConsole, dwMode);
    printf("\033[H\033[J"); 
}
int main(){
    srand(time(NULL));
    //Tic tac toe board.
    char matrix[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};
    //Game states Variables.
    bool gamend=false,xturn=true,playertwo,nodraw;
    int botlevel,botplan=0,botstep=0,choice;

    
    
    while (1){
        clear_terminal();
        printf("Play against:\nComputer\t\t(0)\n2nd Player\t\t(1)\n");
        if (scanf("%d",&choice)!=1){
            continue;
        }
        if (choice!=0 && choice!=1){
            continue;
        }
        break;
    } 
    playertwo = choice;

    if (!playertwo){
        do{
            clear_terminal();
            printf("(0) Easy bot.\n(1) Normal bot.\n(2) Hard bot.\n");
            scanf("%d",&botlevel);
        } while (botlevel<0||botlevel>2);
    }

    clear_terminal();

    while (!gamend){
        int pos=0;
        int posH;
        int posV;
        if (xturn){ // 1st player turn.
            printf("it's your turn\n");
            while (1){
                printf("Choose a square(1-9): ");
                if (scanf("%d",&pos)!=1){
                    printf("error\n");
                    while (getchar() != '\n');
                    continue;
                } 
                if (pos<1 || pos>9){
                    continue;
                }
                posH = (pos-1)%3;
                posV = (9-pos)/3;
                if(matrix[posV][posH]!=' '){
                    continue;
                }
                clear_terminal();
                break;
            }
            //printf("You chose %d\n\n",pos);
            matrix[posV][posH]='X';
            xturn= false;
        } else{//2nd player turn
             if (playertwo==true) {//Real player.
                while (1){
                    printf("Choose a square(1-9): ");
                    if (scanf("%d",&pos)!=1){
                        printf("error\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (pos<1 || pos>9){
                        continue;
                    }
                    posH = (pos-1)%3;
                    posV = (9-pos)/3;
                    if(matrix[posV][posH]!=' '){
                        continue;
                    }
                    clear_terminal();
                    break;
                }
                //printf("You chose %d\n\n",pos);
                matrix[posV][posH]='O';
                xturn= true;
            } else {//bot player
                switch (botlevel){
                    case 0:{
                        clear_terminal();
                        int a,b;
                        do{
                            a = rand() % 3;  
                            b = rand() % 3;
                        } while (matrix[a][b]!=' ');
                        matrix[a][b]='O';
                        xturn=true;
                        break;

                    }
                    case 1:

                        break;
                    case 2:
                        if (botplan==0){
                            if (matrix[1][1]=='X'){
                                botplan=1;

                            } else if (matrix[0][0]=='X'||matrix[0][2]=='X'||matrix[2][0]=='X'||matrix[2][2]=='X'){
                                botplan=2;

                            } else {
                                botplan=3;
                            }
                          
                        }
                        if (botplan==1){
                            switch (botstep){
                            case 1:
                                
                                break;
                            
                            default:
                                break;
                            }

                        } else if (botplan==2){

                        } else if (botplan==3){

                        }

                        break;
                }

            }
        }
        
        for (int j = 0; j < 3; j++){
            for (int i = 0; i < 3; i++)
            {
                printf("%c",matrix[j][i]); 
                if (i < 2) printf("|");
            }
            printf("\n");
            if (j < 2) printf("-+-+-\n");
        }

        for (int j = 0; j < 3; j++){
            if (matrix[j][0]!=' ' && matrix[j][0]==matrix[j][1] && matrix[j][0]==matrix[j][2]){
                gamend=true;
            }   
        }
        for (int i = 0; i < 3; i++){
            if (matrix[0][i]!=' ' && matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i]){
                gamend=true;
            }   
        }  
        
        if (matrix[0][0]!=' ' && matrix[0][0]==matrix[1][1] && matrix[0][0] == matrix[2][2] ){
            gamend=true;
        } else if (matrix[0][2]!=' ' && matrix[0][2]==matrix[1][1] && matrix[0][2] == matrix[2][0] ){
            gamend=true;
        }
        nodraw=false;
        for (int j = 0; j < 3; j++){
            for (int i = 0; i < 3; i++){
                if (matrix[j][i]==' '){
                    nodraw=true;
                   
                } else if (i==2 && j==2 && nodraw==false){
                    nodraw=false;
                    gamend=true;
                }
            }
             
        }
        
    }

    if (nodraw){
        if (xturn){
            printf("Player 2 Won.\n\n\n");
        } else {
            printf("Player 1 Won.\n\n\n");
        }        
    } else {
        printf("It's a Draw!\n\n\n");
    }
    return 0;
}
