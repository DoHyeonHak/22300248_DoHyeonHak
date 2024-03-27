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

// function
int loadData(Contact* c[]);
void printContact(Contact* c[], int size);
int addContact(Contact* c[], int size);
int deleteContact(Contact* c[], int size);
void editContact(Contact* c[], int size);
void searchContact(Contact* c[], int size);
void saveContact(Contact* c[], int size);
void subscribeFavorite(Contact* c[], int size);