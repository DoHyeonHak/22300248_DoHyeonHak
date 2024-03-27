#include "deleteC.h"

int deleteContact(Contact* c[], int size){
	// delete Contact
	// read number
	// if number in size, display Info, else return size
	// display the message for checking Deleting
	// if yon is 1, delete, else cancel
	int number = 0;
	int yon = 0;
	printf("> Delete Contact\n");
	printf("> Enter a number of Contact : ");
	scanf("%d", &number);
	if(number - 1 < size){
		printf("> Contact Information\n");
		printf("[%2d] %-8s : %s | %-23s | %-10s\n", number, c[number - 1]->name, c[number - 1]->phone_num, c[number - 1]->email, c[number - 1]->relationship);
	}else{
		printf("> Wrong number\n");
		return size;
	}

	printf("> Do you want to delete this contact? (yes = 1, no = 0)\n: ");
	scanf("%d", &yon);

	if(yon == 1){
		for(int i = number - 1; i < size; i ++){
			c[i] = c[i + 1];
		}
		printf("> Contact is deleted.\n");
		return size - 1;
	}else{
		printf("> Canceled\n");
	}
	return size;
}