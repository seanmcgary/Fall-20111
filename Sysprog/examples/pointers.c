#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person {
	char *name;
};

int main(){
	struct person **array = malloc(sizeof(struct person) * 100);
	
	printf("size: %d\n", (int)sizeof(array));
	
	struct person *p = (struct person *) malloc(sizeof(struct person));
	p->name = "Foo";
	array[0] = (struct person *) malloc(sizeof(struct person));
	memcpy(&array[0], &p, sizeof(p));

	printf("name: %s\n", array[0]->name);
	p->name = "Foobar";
	printf("name: %s\n", array[0]->name);

	int i;
	for(i = 0; i < 10; i++){
		struct person *t = (struct person *) malloc(sizeof(struct person));

		t->name = "string";

		array[i] = (struct person*) malloc(sizeof(struct person));
		memcpy(&array[0], &t, sizeof(t));
		
	}

	for(i = 0; i < 10; i++){
		printf("%d - Name: %s\n", i, array[i]->name);
	}


	return 0;
}
