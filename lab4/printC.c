#include "printC.h"

void printContact(Contact* c[], int size){
	// use loop from 0 to size
	// display Contact Information!
	printf("> Contact List\n");
	for(int i = 0; i < size; i ++){
		printf("[%2d] %-8s : %s | %-23s | %-10s\n", i + 1, c[i]->name, c[i]->phone_num, c[i]->email, c[i]->relationship);
	}
}