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
	char *cid;
    struct Customer *next_customer;
	struct Part **purchased_parts;
};

#endif
