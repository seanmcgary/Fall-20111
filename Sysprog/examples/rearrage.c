#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// preprocessor macros
#define MAX_CALLS 20 // max # of cols to process
#define MAX_INPUT 1000 // max len of input & output lines

// prototypes
int read_column_numbers(int columns[], int max);

// pass input and output by reference
void rearrange(char *output, char const *input, int n_columns, int const columns[]);


int read_column_numbers(int columns[], int max){
    // this is an initial assignment, NOT initialization
    int num = 0;
    int ch;
    
    // do we have room in the array
    // did we read a number
    // was it a termination number
    while(num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0){
        num += 1;
    }
    
    // we want an even number of inputs
    if(num % 2 != 0){
        puts("Last column number is not paired");
        exit(EXIT_FAILURE);
    }
    
    // discard the rest of the line having the final number
    while((ch = getchar()) != EOF && ch != '\n');

    return(num);
    
}

void rearrange(char *output, char const *input, int n_columns, int const columns[]){
    int col;
    int output_col;
    int len;

    len = strlen(input);
    output_col = 0;

    for(col = 0; col < n_columns; col += 2){
        int nchars = columns[col + 1] - columns[col] + 1;

        if(columns[col] > len || output_col == MAX_INPUT - 1){
            break;
        }

        if(output_col + nchars > MAX_INPUT - 1){
            nchars = MAX_INPUT - output_col - 1;
        }

        strncpy(output + output_col, input + columns[col], nchars);
        output_col += nchars;
    }
}

int main(void){

    int n_columns; 
    int columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    // read list of column numbers

    n_columns = read_column_numbers(columns, MAX_COLS);

    // read, process, and print the remaining lines of input
    // This loop is VERY common
    //      fgets: buffer, sizeof the buffer, stream pointer
    //      fgets returns a pointer to the buffer, otherwise, it returns a NULL pointer
    while(fgets(input, MAX_INPUT, stdin) != NULL){
        printf("Original input : %s", input);
        rearrange(output, input, n_columns, columns);
        printf("Rearranged line : %s\n", output);
    }

    return(EXIT_SUCCESS);
}
