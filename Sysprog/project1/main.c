#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "objects.h"
#include "input.h"
#include "allocate.h"

int main(int argc, char *argv){
   	
	if(argc != 2){
		return 0;
	}

	struct part *parts_list;

    /*struct customer *me;
	
    me = (struct customer *) malloc(sizeof(struct customer));

    me->name = "Sean McGary\0";
    me->credit = 9000;
    me->uid = "S1234\0";

    printf("Name: %s", me->name);
    
    int i;
    for(i = 0; i < 5000; i++){
        struct customer *c;
        c = (struct customer *) malloc(sizeof(struct customer));

        c->credit = i;

        me->customers[i] = c;
    }

	*/
	//read_customers(argv[0]);
    read_customers("./project_files/custs.6");


    
    return 1;
}
