#ifndef INPUT_H
#define INPUT_H

void insert_part(struct Part *new_part, struct Part *head){
    
}

void read_customers(const char* file_name, struct Part *head, struct Part *tail){
	FILE *fp;
	
	fp = fopen(file_name, "r");
	
	char line[128];

	int counter = 0;
	
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
            
            current_part->pid = allocate(strlen(line) - 1);

            strncpy(current_part->pid, line, strlen(line) - 1);

            //printf("PID: %s\n", current_part->pid);
            
            
            // set the head pointer to the current part
            *head = *current_part;

            printf("head: %s\n", head->pid);
            
            counter++;
		} else if(counter == 1){
            // part qty
			counter++;
        }		

	}

}


#endif
