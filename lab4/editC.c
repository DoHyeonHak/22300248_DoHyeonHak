#include "editC.h"

void editContact(Contact* c[], int size){
	// edit contact
	// allocate *new for assignment
	// read number
	// if number in size, display Info and read information
	// display edited infomation and display the message for editing information
	// if yon is 1, edit
	int number = 0;
	int yon = 0;
	Contact* new ;
	new = (Contact*)malloc(sizeof(Contact));
	printf("> Edit Contact\n");
	printf("> Enter a number of Contact : ");
	scanf("%d", &number);
	if(number - 1 < size){
		printf("> Contact Information\n");
		printf("[%2d] %-8s : %s | %-23s | %-10s\n", number, c[number - 1]->name, c[number - 1]->phone_num, c[number - 1]->email, c[number - 1]->relationship);
		printf("> Edit process\n");
		printf("Enter name : ");
		scanf("%s", new->name);
		printf("Enter phone number : ");
		scanf("%s", new->phone_num);
		printf("Enter email : ");
		scanf("%s", new->email);
		printf("Enter relationship : ");
		scanf("%s", new->relationship);
		new->favorite = 0;						// default
		printf("> %-8s : %s | %-23s | %-10s\n", new->name, new->phone_num, new->email, new->relationship);
		printf("> Do you want to edit this contact? (yes = 1, no = 0)\n: ");
		scanf("%d", &yon);
		if(yon == 1){
			c[number - 1] = new;
			printf("> Contact is edited.\n");
		}
	}else{
		printf("> Wrong number\n");
	}
}