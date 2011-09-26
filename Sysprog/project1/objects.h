#include <stdio.h>
#include <string.h>

struct part {
	char *pid;
	int qty;
	double price;
};

struct customer {
	char *name;
	int credit;
	char *uid;
	struct part *purchased_parts[];
};
