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

char sign[2][5] = {"*", " "};

// function
int loadData(Contact *c);
void printContact(Contact *c, int size);
int addContact(Contact *c, int size);
int deleteContact(Contact *c, int size);
void editContact(Contact *c, int size);
void searchContact(Contact *c, int size);
void saveContact(Contact *c, int size);
void contactFavorite(Contact *c, int size);


int main(void) {
	int amount;	                            // amount of Contact
    int menu;
    Contact *contact[80];                   // Info list (0 ~ 80)

	size = loadData(contact);
	printf("Contact CRUD!\nWhat do you want to do?\n");
	while(1){
		printf("\n> Menu 1.List 2.Add 3.Delete 4.Search 5.Edit 6.Favorite 7.Save 0.Quit\n");
		printf(">>>> ");
		scanf("%d", &menu);

		if(number == 1){ 
			printContact(contact, amount);
		}
		else if(number == 2){ 
			size = addContact(contact, amount);
		}
		else if(number == 3){ 
			size = deleteContact(contact, amount);
		}
		else if(number == 4){
			searchContact(contact, amount);
		}
		else if(number == 5){
			contactFavorite(contact, amount);
		}
		else if(number == 6){
            editContact(contact, amount);
		}
		else if(number == 7){
			editContact(contact, amount);
		}
		else break;
	}
	return 0;
}

int loadData(Contact *c, int size){
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
	fp = fopen(FILENAME, 'r');
	while(!feof(fp)){
		Contact* Info = (Contact*)malloc(sizeof(Contact));
		ret = fscanf("%s %s %s %s %d", Info->name, Info->phone_num, Info->email, Info->relationship, Info->favorite);
		if(ret < 5){
			break;
		}
		c[count] = Info;
		count++;
	}
	return count;
}

void printContact(Contact *c, int size){
	// use loop from 0 to size
	// display Contact Information!
	printf("Contact List\n");
	for(int i = 0; i < size; i ++){
		printf("[%2d] %s : %s | %s | %s | %s\n", i + 1, c->name, c->phone_num, c->relationship, c->relationship, sign[c->favorite]);
	}
}

int addContact(Contact *c, int size){
	// read name, phone number, email, relationship, favorite
	// assignment
	// display result
	// return size + 1 (because 'Add'!)
	Contact *new;
	new = (Contact*)malloc(sizeof(Contact));
	printf("Input name : ");
	scanf("%s", new->name);
	printf("Input phone number : ");
	scanf("%s", new->phone_num);
	printf("Input phone number : ");
	scanf("%s", new->phone_num);
	printf("Input relationship : ");
	scanf("%s", new->phone_num);
	printf("Would you like to bookmark this contact?(yes = 1, no = 0): ");
	scanf("%d", new->favorite);
	c[size]= new;
	printf("New Contact!\n");
	printf("[%2d] %s : %s | %s | %s | %s\n", size + 1, c[size]->name, c[size]->phone_num, c[size]->relationship, c[size]->relationship, sign[c[size]->favorite]);

	return size + 1;
}

int deleteContact(Contact *c, int size){

}

void editContact(Contact *c, int size){

}

void searchContact(Contact *c, int size){

}

void saveContact(Contact *c, int size){

}

void contactFavorite(Contact *c, int size){

}
