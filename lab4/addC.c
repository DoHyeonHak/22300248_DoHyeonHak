#include "addC.h"

int addContact(Contact* c[], int size){
	// read name, phone number, email, relationship, favorite
	// assignment
	// display result
	// return size + 1 (because 'Add'!)
	Contact *new;
	int yon = 0;
	new = (Contact*)malloc(sizeof(Contact));
	printf("> Input name : ");
	scanf("%s", new->name);
	printf("> Input phone number : ");
	scanf("%s", new->phone_num);
	printf("> Input email : ");
	scanf("%s", new->email);
	printf("> Input relationship : ");
	scanf("%s", new->relationship);
	new->favorite = 0;				// default
	c[size]= new;
	printf("> New Contact!\n");
	printf("[%2d] %-8s : %s | %-23s | %-10s\n", size + 1, c[size]->name, c[size]->phone_num, c[size]->email, c[size]->relationship);

	return size + 1;
}