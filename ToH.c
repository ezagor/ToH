#include <stdio.h>
#include <ctype.h>

void prntTowers(char towers[3][6]){
    int i = 0, j = 0;
    printf("A B C\n");
    for(i=0;i<5;i++){
        for(j=0;j<3;j++)
            printf("%c ", towers[j][i]);
        printf("\n");
    }
}

int move(char towers[3][6], int from, int to){
    int i;
    int j;
    for(i=0;i<5;i++){
        if(towers[from][i] != '_'){
            for(j=0;j<6;j++){
                if(((towers[to][j] != '_') && towers[from][i] < towers[to][j]) || j == '0'){
                    towers[to][j-1] = towers[from][i];
                    towers[from][i] = '_';
                    return 1;
                }
            }
        }
    }
    return 0;
}

void main(){
    char towers[3][6], in1, in2;
    int i = 0, j = 0, moved = 0, from = 4, to = 4;

    for(i=0;i<5;i++){
            towers[0][i] = '-1' + i;
        for(j=1;j<3;j++)
            towers[j][i] = '_';
    }
    for(i=0;i<3;i++)
        towers[i][5] = '0';
    prntTowers(towers);
    while(1){
        printf("Enter which columns you would like to move (from to): ");
        scanf(" %c %c", &in1, &in2);
        switch(in1){
            case 'A': from = 0; break;
            case 'B': from = 1; break;
            case 'C': from = 2; break;
            default: from = 4;
        }
        switch(in2){
            case 'A': to = 0; break;
            case 'B': to = 1; break;
            case 'C': to = 2; break;
            default: to = 4;
        }

        moved = move(towers, from, to);
        if(moved){
        }
        else if(!moved){
            printf("No pieces moved.\n");
        }
        prntTowers(towers);
    }
}
