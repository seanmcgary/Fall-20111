#include <math.h>
#ifndef INPUT_H
#define INPUT_H

void insert_part(struct Part *new_part, struct Part *head){
    
}

void insert_new_part(struct Part *new_part, struct Part *head, struct Part *current){

	if(current->next_part == NULL){
		// if next_part is null, we've sit the end, insert the new node
		current->next_part = allocate(sizeof(struct Part));

		*current->next_part = *new_part; 

		return;
	} else {
		
		insert_new_part(new_part, head, current->next_part);
		return;
	}
}

void print_all_parts(const struct Part *current){
	printf("PID: %s, QTY: %d, PRICE: %f\n", current->pid, current->qty, current->price);
	if(current->next_part != NULL){
		print_all_parts(current->next_part);
	}
}

void read_parts(const char* file_name, struct Part *head, struct Part *tail){
	FILE *fp;
	
	fp = fopen(file_name, "r");
	
	char line[128];

	int counter = 0;
    int total_counter = 0;
	
    struct Part *current_part = NULL;

	while(fgets(line, sizeof line, fp) != NULL){
		//printf("%s\n", line);
		
        // if counter % 3 == 0, we need to create a new customer entry
		if(counter == 2){

            // part qty
			char *tmp = allocate(strlen(line) - 1);

			strncpy(tmp, line, strlen(line) - 1);
			current_part->price = atof(tmp);

			unallocate(tmp);

			counter++;
            // part price

            // add to the linked list        
            if(total_counter == 0){ 
                *head = *current_part;
            } else {
				// insert the node
				insert_new_part(current_part, head, head);
            }

			// reset the local counter 
			counter = 0;

		} else if(counter == 0){
            // create a new temp struct and 
            current_part = allocate(sizeof(struct Part));
            current_part->next_part = NULL;

			// copy out the needed values
			char tmp[strlen(line)];
			memcpy(tmp, line, strlen(line) - 1);
			strcat(tmp, "\0");

			// allocate and copy the string to the current_part struct
			current_part->pid = allocate(sizeof(tmp));
            memcpy(current_part->pid, tmp, sizeof(tmp));
			

            counter++;
		} else if(counter == 1){
            // part qty
			char *tmp = allocate(strlen(line) - 1);

			strncpy(tmp, line, strlen(line) - 1);
			current_part->qty = atoi(tmp);

			unallocate(tmp);

			counter++;
        }	

        total_counter++;

	}

}


#endif
