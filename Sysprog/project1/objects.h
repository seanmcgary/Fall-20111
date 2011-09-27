#ifndef OBJECTS_H
#define OBJECTS_H

/*struct part {
	char *pid;
	int qty;
	double price;
   
};

struct customer {
	char *name;
	int credit;
	char *uid;
	struct part *purchased_parts[];
};*/

struct Part {
    char *pid;
    int qty;
    double price;
    struct Part *next_part;
};

struct Customer{
	char *name;
	int credit;
	char *uid;
	struct Part **purchased_parts;
    int purchased_parts_count;
};

#endif
