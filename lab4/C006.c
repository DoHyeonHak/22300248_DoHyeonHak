#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "contact.txt"

typedef struct{
	char name[30]; 	
	char email[50];	
	char phone_num[14];	
    char relationship[10];
    int favorite;
} Contact;

char sign[2][5] = {" ", "*"};

// function
int loadData(Contact* c[]);
void printContact(Contact* c[], int size);
int addContact(Contact* c[], int size);
int deleteContact(Contact* c[], int size);
void editContact(Contact* c[], int size);
void searchContact(Contact* c[], int size);
void saveContact(Contact* c[], int size);
void contactFavorite(Contact* c[], int size);


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
			contactFavorite(contact, amount);
		}
		else if(menu == 6){
            editContact(contact, amount);
		}
		else if(menu == 7){
			editContact(contact, amount);
		}
		else break;
	}
	return 0;
}

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
	printf("Contact List\n");
	for(int i = 0; i < size; i ++){
		printf("[%2d] %s : %s | %s | %s | %s\n", i + 1, c[i]->name, c[i]->phone_num, c[i]->email, c[i]->relationship, sign[c[i]->favorite]);
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
	printf("Input name : ");
	scanf("%s", new->name);
	printf("Input phone number : ");
	scanf("%s", new->phone_num);
	printf("Input email : ");
	scanf("%s", new->email);
	printf("Input relationship : ");
	scanf("%s", new->relationship);
	printf("Would you like to bookmark this contact?(yes = 1, no = 0): ");
	scanf("%d", &yon);
	if(yon == 1){
		new->favorite = 1;
	}else{
		new->favorite = 0;
	}
	c[size]= new;
	printf("New Contact!\n");
	printf("[%2d] %s : %s | %s | %s | %s\n", size + 1, c[size]->name, c[size]->phone_num, c[size]->email, c[size]->relationship, sign[c[size]->favorite]);

	return size + 1;
}

int deleteContact(Contact* c[], int size){
	int number = 0;
	int yon = 0;
	printf("> Delete Contact\n");
	printf("> Enter a number of Contact : ");
	scanf("%d", &number);
	if(number - 1 < size){
		printf("> Contact Information\n");
		printf("[%2d] %s : %s | %s | %s | %s\n", number, c[number - 1]->name, c[number - 1]->phone_num, c[number - 1]->email, c[number - 1]->relationship, sign[c[number - 1]->favorite]);
	}else{
		printf("> Wrong number\n");
		return size;
	}
	
	printf("> If you want to delete this contact? (yes = 1, no = 0)\n");
	scanf("%d", &yon);

	if(yon == 1){
		for(int i = number - 1; i < size; i ++){
			c[i] = c[i + 1];
		}
		printf("Contact is deleted.\n");
		return size - 1;
	}else{
		printf("Canceled\n");
	}
	return size;
}

void editContact(Contact* c[], int size){

}

void searchContact(Contact* c[], int size){

}

void saveContact(Contact* c[], int size){

}

void contactFavorite(Contact* c[], int size){

}
