#include <stdio.h>
#include <stdlib.h>

void read_customers(const char* file_name){
	FILE *fp;
	
	fp = fopen(file_name, "r");
	
	char line[128];

	int counter = 0;
	
	int current_index = 0;

	while(fgets(line, sizeof line, fp) != NULL){
		printf("%d\n", counter);
		// if counter % 3 == 0, we need to create a new customer entry
		if(counter == 2){
			counter = 0;

		} else {
			// else we can put it in the current one

			counter++;
		}

		

	}

}
