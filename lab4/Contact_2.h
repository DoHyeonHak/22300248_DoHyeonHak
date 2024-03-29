#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Contact.h"

// another function
int loadData(Contact* c[]);
void searchContact(Contact* c[], int size);
void saveContact(Contact* c[], int size);
void subscribeFavorite(Contact* c[], int size);