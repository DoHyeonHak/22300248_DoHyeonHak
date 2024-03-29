#include "subscribeF.h"


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
	if(yon == 1){
		printf("\n> Modified Favorite Contact List\n");				// for checking Favorite Contact List
		for(int i = 0; i < size; i ++){
			if(c[i]->favorite == 1){
				printf("[%2d] %-8s : %s | %-23s | %-10s\n", i + 1, c[i]->name, c[i]->phone_num, c[i]->email, c[i]->relationship);
			}
		}
	}
}
