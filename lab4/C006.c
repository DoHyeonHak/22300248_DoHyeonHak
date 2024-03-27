#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Contact.h"
#include "loadD.h"
#include "printC.h"
#include "addC.h"
#include "deleteC.h"
#include "editC.h"
#include "searchC.h"
#include "saveC.h"
#include "subscribeF.h"

// function
//int loadData(Contact* c[]);
//void printContact(Contact* c[], int size);
//int addContact(Contact* c[], int size);
//int deleteContact(Contact* c[], int size);
//void editContact(Contact* c[], int size);
//void searchContact(Contact* c[], int size);
//void saveContact(Contact* c[], int size);
//void subscribeFavorite(Contact* c[], int size);


int main(void) {
	int amount;	                            // amount of Contact
    int menu;
    Contact* contact[80];                   // Info list (0 ~ 80)

	amount = loadData(contact);
	printf("Contact CRUD!\nWhat do you want to do?\n");
	while(1){
		printf("\n> Menu 1.List 2.Add 3.Delete 4.Search 5.Edit 6.Favorite 7.Save 0.Quit\n");
		printf(">>>> ");
		scanf("%d", &menu);

		if(menu == 1){ 
			printContact(contact, amount);
		}
		else if(menu == 2){ 
			amount = addContact(contact, amount);
		}
		else if(menu == 3){ 
			amount = deleteContact(contact, amount);
		}
		else if(menu == 4){
			searchContact(contact, amount);
		}
		else if(menu == 5){
			editContact(contact, amount);
		}
		else if(menu == 6){
            subscribeFavorite(contact, amount);
		}
		else if(menu == 7){
			saveContact(contact, amount);
		}
		else break;
	}
	return 0;
}
/*
int loadData(Contact *c[]){
	// load Data
	// file open
	// 	use loop until feof
	// 		declare pointer struct variable and allocate
	//		read contents
	//	assignment
	//	count++
	// file close
	int count = 0;
	int ret = 0;
	FILE* fp = 0;
	fp = fopen(FILENAME, "r");
	while(!feof(fp)){
		Contact* Info = (Contact*)malloc(sizeof(Contact));
		ret = fscanf(fp, "%s %s %s %s %d", Info->name, Info->phone_num, Info->email, Info->relationship, &Info->favorite);
		if(ret < 5){
			break;
		}
		c[count] = Info;
		count++;
	}
	return count;
}

void printContact(Contact* c[], int size){
	// use loop from 0 to size
	// display Contact Information!
	printf("> Contact List\n");
	for(int i = 0; i < size; i ++){
		printf("[%2d] %-8s : %s | %-23s | %-10s\n", i + 1, c[i]->name, c[i]->phone_num, c[i]->email, c[i]->relationship);
	}
}

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

void searchContact(Contact* c[], int size){
	// search contact
	// make mode [input name, phone number]
	// point!
	//	1) use strstr
	// 	2) sort out cases [no > 1 | no == 1 | no == 0]
	int mode = 0;
	int no = 0;
	char name[100] = "";
	char p_num[14] = "";
	printf("> Search Contact\n");
	printf("> Select searching mode (1: name, 2: phone number): ");
	scanf("%d", &mode);
	if(mode == 1){
		printf("> Enter name (You can enter some or all of the names.)\n: ");
		scanf("%s", name);
		for(int i = 0; i < size; i ++){
			if(strstr(c[i]->name, name) != NULL){
				printf("[%2d] %-8s : %s | %-23s | %-10s\n", no + 1, c[i]->name, c[i]->phone_num, c[i]->email, c[i]->relationship);
				no++;
			}
		}
	}else if(mode == 2){
		printf("> Enter phone number (You can enter some or all of the phone number.)\n: ");
		scanf("%s", p_num);
		for(int i = 0; i < size; i ++){
			if(strstr(c[i]->phone_num, p_num) != NULL){
				printf("[%2d] %-8s : %s | %-23s | %-10s\n", no + 1, c[i]->name, c[i]->phone_num, c[i]->email, c[i]->relationship);
				no++;
			}
		}
	}
	if(no > 1){
		printf("> %d Contacts are founded.\n", no);
	}else if(no == 1){
		printf("> %d Contact is founded.\n", no);
	}else if(no == 0){
		printf("> Contact does not exist.\n");
	}
}

void saveContact(Contact* c[], int size){
	// 1 is Contact list
	// save in contact.txt
	// and make report
	// All Contact list and Favorite Contact list
	
	// save new Contacts
	printf("> Save Contact\n");
	int count = 0;
	FILE* fp = NULL;
	fp = fopen(FILENAME, "w");
	for(int i = 0; i < size; i ++){
		fprintf(fp, "%s %s %s %s %d\n", c[i]->name, c[i]->phone_num, c[i]->email, c[i]->relationship, c[i]->favorite);
	}
	fclose(fp);

	// write new report including Contact list and Favorite Contact List
	fp = fopen("report.txt", "w");
	fprintf(fp, "1. Contact List\n");
	for(int i = 0; i < size; i ++){
		fprintf(fp, "[%2d] %-8s : %s | %-23s | %-10s\n", i + 1, c[i]->name, c[i]->phone_num, c[i]->email, c[i]->relationship);
	}
	fprintf(fp, "Total : %d\n\n", size);
	
	fprintf(fp, "2. Favorite Contact List\n");
	for(int i = 0; i < size; i ++){
		if(c[i]->favorite == 1){
			fprintf(fp, "[%2d] %-8s : %s | %-23s | %-10s\n", count + 1, c[i]->name, c[i]->phone_num, c[i]->email, c[i]->relationship);
			count++;
		}
	}
	fprintf(fp, "Total : %d\n\n", count);
	fclose(fp);
	printf("> Saved all of Contact in 'contact.txt'\n");
	printf("> Made 'report.txt'\n");
}


void subscribeFavorite(Contact* c[], int size){
	// subscribe or unsubscribe favorite contact
	// make favorite contact list for users to refer
	int num = 0;
	int yon = 0;

	printf("> Subscribe Favorite Contact\n");
	printf("> Favorite Contact List\n");				// for checking Favorite Contact List
	for(int i = 0; i < size; i ++){
		if(c[i]->favorite == 1){
			printf("[%2d] %-8s : %s | %-23s | %-10s\n", i + 1, c[i]->name, c[i]->phone_num, c[i]->email, c[i]->relationship);
		}
	}

	// read num
	// if contact is not favorite
	//		if yon is 1, subscribe. else pass
	// if contact is favorite
	//		if yon is 1, unsubscribe. else pass 
	printf("\n> Enter Contact number: ");
	scanf("%d", &num);
	if(c[num - 1]->favorite == 0){
		printf("> This contact is not favorite.\n");
		printf("> Do you want to subscribe this contact as a favorite? (yes = 1, no = 0): ");
		scanf("%d", &yon);
		if(yon == 1){
			c[num - 1]->favorite = 1;
			printf("> Subscribed!\n");
		}
	}else if(c[num - 1]->favorite == 1){
		printf("> This contact is already favorite.\n");
		printf("> Do you want to unsubscribe from this contact? (yes = 1, no = 0): ");
		scanf("%d", &yon);
		if(yon == 1){
			c[num - 1]->favorite = 0;
			printf("> Unsubscribed!\n");
		}
	}

}

*/