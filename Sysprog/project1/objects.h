#ifndef OBJECTS_H
#define OBJECTS_H

struct Part {
    char *pid;
    int qty;
    float price;
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
