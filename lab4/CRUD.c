#include "Contact.h"
#include "CRUD.h"

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

void printContact(Contact* c[], int size){
	// use loop from 0 to size
	// display Contact Information!
	printf("> Contact List\n");
	for(int i = 0; i < size; i ++){
		printf("[%2d] %-8s : %s | %-23s | %-10s\n", i + 1, c[i]->name, c[i]->phone_num, c[i]->email, c[i]->relationship);
	}
	printf("\n> Favorite Contact List\n");				
	for(int i = 0; i < size; i ++){
		if(c[i]->favorite == 1){
			printf("[%2d] %-8s : %s | %-23s | %-10s\n", i + 1, c[i]->name, c[i]->phone_num, c[i]->email, c[i]->relationship);
		}
	}
}

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

