#include "Contact.h"
#include "Contact_2.h"

// another functions
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
	// read num
	// if contact is not favorite
	//		if yon is 1, subscribe. else pass
	// if contact is favorite
	//		if yon is 1, unsubscribe. else pass 
	printf("> Enter Contact number: ");
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