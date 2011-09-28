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

	printf("%s\n", argv[1]);

    struct Part *head_part = allocate(sizeof(struct Part));

    struct Customer *head_customer = allocate(sizeof(struct Customer));
    

	read_parts(argv[2], head_part);
    
    read_customers(argv[1], head_customer);

    printf("Head: %s\n", head_part->pid);
    //printf("Tail: %s\n", tail_part->pid);
	
	if(head_part->next_part == NULL){
		printf("Head next is null\n");
	}

	print_all_parts(head_part);
    
	if(head_customer->next_customer == NULL){
		printf("Head next is null\n");
	}

    //printf("head.next: %s\n", head_part->next_part->pid);

    
    return 1;
}
