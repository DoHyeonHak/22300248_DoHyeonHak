#include "loadD.h"

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