#ifndef INPUT_H
#define INPUT_H

void insert_part(struct Part *new_part, struct Part *head){
    
}

void read_parts(const char* file_name, struct Part *head, struct Part *tail){
	FILE *fp;
	
	fp = fopen(file_name, "r");
	
	char line[128];

	int counter = 0;
    int total_counter = 0;
	
	int current_index = 0;

    struct Part *current_part = NULL;


	while(fgets(line, sizeof line, fp) != NULL){
		//printf("%s\n", line);
		
        // if counter % 3 == 0, we need to create a new customer entry
		if(counter == 2){
			counter = 0;

            // part price

            // add to the linked list
            

		} else if(counter == 0){
            // create a new temp struct and 
            
            current_part = allocate(sizeof(struct Part));
            current_part->next_part = NULL;
            
            current_part->pid = allocate(strlen(line) - 1);

            strncpy(current_part->pid, line, strlen(line) - 1);

            //printf("PID: %s\n", current_part->pid);
            if(total_counter == 0){ 
                *head = *current_part;
                *tail = *current_part;
                //printf("head: %s\n", head->pid);
            } else {
                tail->next_part = allocate(sizeof(struct Part));

                *tail->next_part = *current_part;

                //printf("tail: %s, next: %s\n", tail->pid, tail->next_part->pid);

                *tail = *current_part;
                //printf("new tail: %s\n", tail->pid);
            }

            
            counter++;
		} else if(counter == 1){
            // part qty
            
			counter++;
        }	

        total_counter++;

	}

}


#endif
