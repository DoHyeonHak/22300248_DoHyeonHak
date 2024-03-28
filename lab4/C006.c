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
