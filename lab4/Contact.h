#ifndef __PREVENT__
#define __PREVENT__

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

// CRUD
int addContact(Contact* c[], int size);
void printContact(Contact* c[], int size);
void editContact(Contact* c[], int size);
int deleteContact(Contact* c[], int size);

#endif

/*
#ifndef __PREVENT__
#define __PREVENT__

...

#endif

for preventing typedef redefinition
*/