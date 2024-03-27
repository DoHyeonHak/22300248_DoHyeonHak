#include "searchC.h"

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