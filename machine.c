//Name: Dhwanil Chokshi
//Project 1
//Class: CS311 T/TR 
//Deterministic Finite Automata: Legal "Double" Recognizer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

int create_machine(char dfa[13][16]);
int print_machine(char dfa[13][16]);
int read_file(char argv[], FILE *test, char dfa[13][16]);
int check(char string[], char dfa[13][16]);
int check_decimals(char string[], int length);

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Need to run a file with the program\n");
        exit(0);
    }
        
    FILE *fileptr;
    char machine[13][16];

    create_machine(machine);
    //print_machine(machine);
    read_file(argv[1], fileptr, machine); 

return 0;
}

int create_machine(char dfa[13][16])
{
//u = dead state
//1 = starting state
//3, 5, 6, 8, 9 = accept states
    dfa[0][0] = 't';

    dfa[0][1] = '.'; dfa[0][2] = '0'; dfa[0][3] = '1'; dfa[0][4] = '2'; dfa[0][5] = '3'; dfa[0][6] = '4'; dfa[0][7] = '5'; dfa[0][8] = '6';
    dfa[0][9] = '7'; dfa[0][10] = '8'; dfa[0][11] = '9'; dfa[0][12] = '+'; dfa[0][13] = '-'; dfa[0][14] = 'E'; dfa[0][15] = 'e'; 

    dfa[1][0] = '1'; dfa[1][1] = '2'; dfa[1][2] = '3', dfa[1][3] = '3'; dfa[1][4] = '3'; dfa[1][5] = '3'; dfa[1][6] = '3'; dfa[1][7] = '3';
    dfa[1][8] = '3'; dfa[1][9] = '3'; dfa[1][10] = '3'; dfa[1][11] = '3'; dfa[1][12] = '4'; dfa[1][13] = '4'; dfa[1][14] = 'u'; dfa[1][15] = 'u';

    dfa[2][0] = '2'; dfa[2][1] = 'u'; dfa[2][2] = '5', dfa[2][3] = '5'; dfa[2][4] = '5'; dfa[2][5] = '5'; dfa[2][6] = '5'; dfa[2][7] = '5';
    dfa[2][8] = '5'; dfa[2][9] = '5'; dfa[2][10] = '5'; dfa[2][11] = '5'; dfa[2][12] = 'u'; dfa[2][13] = 'u'; dfa[2][14] = 'u'; dfa[2][15] = 'u';
    
    dfa[3][0] = '3'; dfa[3][1] = '6'; dfa[3][2] = '3', dfa[3][3] = '3'; dfa[3][4] = '3'; dfa[3][5] = '3'; dfa[3][6] = '3'; dfa[3][7] = '3';
    dfa[3][8] = '3'; dfa[3][9] = '3'; dfa[3][10] = '3'; dfa[3][11] = '3'; dfa[3][12] = 'u'; dfa[3][13] = 'u'; dfa[3][14] = '7'; dfa[3][15] = '7';
    
    dfa[4][0] = '4'; dfa[4][1] = '2'; dfa[4][2] = '8', dfa[4][3] = '8'; dfa[4][4] = '8'; dfa[4][5] = '8'; dfa[4][6] = '8'; dfa[4][7] = '8';
    dfa[4][8] = '8'; dfa[4][9] = '8'; dfa[4][10] = '8'; dfa[4][11] = '8'; dfa[4][12] = 'u'; dfa[4][13] = 'u'; dfa[4][14] = 'u'; dfa[4][15] = 'u';
    
    dfa[5][0] = '5'; dfa[5][1] = 'u'; dfa[5][2] = '5', dfa[5][3] = '5'; dfa[5][4] = '5'; dfa[5][5] = '5'; dfa[5][6] = '5'; dfa[5][7] = '5';
    dfa[5][8] = '5'; dfa[5][9] = '5'; dfa[5][10] = '5'; dfa[5][11] = '5'; dfa[5][12] = 'u'; dfa[5][13] = 'u'; dfa[5][14] = '7'; dfa[5][15] = '7';

    dfa[6][0] = '6'; dfa[6][1] = 'u'; dfa[6][2] = '6', dfa[6][3] = '6'; dfa[6][4] = '6'; dfa[6][5] = '6'; dfa[6][6] = '6'; dfa[6][7] = '6';
    dfa[6][8] = '6'; dfa[6][9] = '6'; dfa[6][10] = '6'; dfa[6][11] = '6'; dfa[6][12] = 'u'; dfa[6][13] = 'u'; dfa[6][14] = '7'; dfa[6][15] = '7';

    dfa[7][0] = '7'; dfa[7][1] = 'u'; dfa[7][2] = '9', dfa[7][3] = '9'; dfa[7][4] = '9'; dfa[7][5] = '9'; dfa[7][6] = '9'; dfa[7][7] = '9';
    dfa[7][8] = '9'; dfa[7][9] = '9'; dfa[7][10] = '9'; dfa[7][11] = '9'; dfa[7][12] = 'a'; dfa[7][13] = 'a'; dfa[7][14] = 'u'; dfa[7][15] = 'u';

    dfa[8][0] = '8'; dfa[8][1] = '6'; dfa[8][2] = '8', dfa[8][3] = '8'; dfa[8][4] = '8'; dfa[8][5] = '8'; dfa[8][6] = '8'; dfa[8][7] = '8';
    dfa[8][8] = '8'; dfa[8][9] = '8'; dfa[8][10] = '8'; dfa[8][11] = '8'; dfa[8][12] = 'u'; dfa[8][13] = 'u'; dfa[8][14] = '7'; dfa[8][15] = '7';
    
    dfa[9][0] = '9'; dfa[9][1] = 'u'; dfa[9][2] = '9', dfa[9][3] = '9'; dfa[9][4] = '9'; dfa[9][5] = '9'; dfa[9][6] = '9'; dfa[9][7] = '9';
    dfa[9][8] = '9'; dfa[9][9] = '9'; dfa[9][10] = '9'; dfa[9][11] = '9'; dfa[9][12] = 'u'; dfa[9][13] = 'u'; dfa[9][14] = 'u'; dfa[9][15] = 'u';

    dfa[10][0] = 'a'; dfa[10][1] = 'b'; dfa[10][2] = '8', dfa[10][3] = '8'; dfa[10][4] = '8'; dfa[10][5] = '8'; dfa[10][6] = '8'; dfa[10][7] = '8';
    dfa[10][8] = '8'; dfa[10][9] = '8'; dfa[10][10] = '8'; dfa[10][11] = '8'; dfa[10][12] = 'u'; dfa[10][13] = 'u'; dfa[10][14] = 'u'; dfa[10][15] = 'u';

    dfa[11][0] = 'b'; dfa[11][1] = 'u'; dfa[11][2] = '9', dfa[11][3] = '9'; dfa[11][4] = '9'; dfa[11][5] = '9'; dfa[11][6] = '9'; dfa[11][7] = '9';
    dfa[11][8] = '9'; dfa[11][9] = '9'; dfa[11][10] = '9'; dfa[11][11] = '9'; dfa[11][12] = 'u'; dfa[11][13] = 'u'; dfa[11][14] = 'u'; dfa[11][15] = 'u';

    dfa[12][0] = 'u'; dfa[12][1] = 'u'; dfa[12][2] = 'u', dfa[12][3] = 'u'; dfa[12][4] = 'u'; dfa[12][5] = 'u'; dfa[12][6] = 'u'; dfa[12][7] = 'u';
    dfa[12][8] = 'u'; dfa[12][9] = 'u'; dfa[12][10] = 'u'; dfa[12][11] = 'u'; dfa[12][12] = 'u'; dfa[12][13] = 'u'; dfa[12][14] = 'u'; dfa[12][15] = 'u';

}

int print_machine(char dfa[13][16])
{
    int i,j;

    for(i = 0; i < 13; ++i){
        putchar('\n');
        for(j = 0; j < 16; ++j)
            printf("%c ", dfa[i][j]);
    }
    printf("%c", '\n');
}

int read_file(char argv[], FILE *test, char dfa[13][16])
{
    char line[SIZE];
    int success = 0;
    test = fopen(argv, "r");

    if(!test)
    {
        printf("Sorry could not open the file!\n");
        return 0;
    }
    else
    {
        while(fgets(line, sizeof(line), test) && !feof(test))
        {
            success = check(line, dfa);
            if(success == 1)
                fprintf(stdout, "%s %s", "ACCEPT", line); 
            else
                fprintf(stdout, "%s %s", "NOT ACCEPT", line);
        }
    }
}

int check(char string[], char dfa[13][16])
{
    char mimic_columns[16] = {'t', '.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', 'E', 'e'};
    char mimic_rows[13] = {'t', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'u'};
    int row_index, column_index;
    int len, i, j, counter = 0, success = 0, success2 = 0;
    char new_start_state; 
    
    len = strlen(string);



    if(len == 1)
        return 0;

    if(!check_decimals(string, len))
        return 0;

    while(counter < len-1)
    {
        success = 0;
        for(i = 1; i < 16; ++i)
        {
            if(string[counter] == mimic_columns[i])
            {
                column_index = i;
                success = 1;
            }
        }

        if(success == 0)
            return 0;
        
        if(counter == 0)
        {
            row_index = 1;
            new_start_state = dfa[row_index][column_index];
        }
        else
            new_start_state = dfa[row_index][column_index];

        if(new_start_state == 'u')
            return 0;

        else
        {
            for(i = 1; i < 13; ++i)
            {
                if(new_start_state == mimic_rows[i])
                {
                    row_index = i;
                }
            }
            new_start_state = dfa[row_index][0];
            if(new_start_state == 'u')
                return 0;
        }
        ++counter;
    }

    if(new_start_state == '3' || new_start_state == '5' || new_start_state == '6' || new_start_state == '8' || new_start_state == '9')
        return 1;
    else
        return 0;
}

int check_decimals(char string[], int length)
{
    int count = 0;
    int i;

    for(i = 0; i < length; ++i)
    {
        if(string[i] == '.')
            ++count;

    }
    if(count > 1)
        return 0;
    else
        return 1;
}
