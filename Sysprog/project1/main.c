#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "allocate.h"
#include "objects.h"
#include "input.h"


int main(int argc, char *argv[]){
    

	if(argc != 3){
        printf("Usage: main customer_file  parts_file\n");
		return 0;
	}


    struct Part *head_part = allocate(sizeof(struct Part));
    struct Part *tail_part = allocate(sizeof(struct Part));

    struct Customer *head_customer = NULL;
    struct Customer *tail_customer = NULL;
    

	read_customers(argv[1], head_part, tail_part);

    printf("Head: %s\n", head_part->pid);

    
    return 1;
}
