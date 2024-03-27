#include "saveC.h"

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