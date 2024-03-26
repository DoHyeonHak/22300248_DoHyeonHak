#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
	char name[30]; 	
	char email[50];	
	char phone_num[14];	
    char relationship[10];
    int favorite;
} Contact;

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

	srand(time(0));
	size = loadData(contact);

	while(1){
		printf("\n> Menu 1.List 2.Add 3.Delete 4.Search 5.Edit 6.Favorite 7.Save 0.Quit\n");
		printf(">> Menu? > ");
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

}

void printContact(Contact *c, int size){

}

int addContact(Contact *c, int size){

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
