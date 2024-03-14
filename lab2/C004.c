// Enter your student ID and Fullname

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct st_class{
	int code;		// class code
	char name[30]; 	// class name
	int unit;		// credites
	int grading;	// grading (1:A+~F, 2:P/F)
};

char kname[2][10] = {"A+~F", "P/F"}; // String for grading

// Functions provided
int loadData(struct st_class* c[]); // Load all class list from data file.
void printAllClasses(struct st_class* c[], int csize); // Print all class list

// Functions for modifying
int addNewClass(struct st_class* c[], int csize); // Add a class into the list
void editClass(struct st_class* c[], int csize); // Modify a class in the list
void findClasses(char* name, struct st_class* c[], int csize); // Search a class by name from the list

// Functions for making
int applyMyClasses(int my[], int msize, struct st_class* c[], int csize); // Apply a class
void printMyClasses(int my[], int msize, struct st_class* c[], int csize); // Print my classes
void saveMyClass(int my[], int msize, struct st_class* c[], int csize); // Save my classes
void saveAllClasses(struct st_class* c[], int csize); // Save all class list


int main(void) {
	int no;	// menu number 
	struct st_class* classes[50]; // Class list (max. 50 classes)

	int myclass[10]; // My classes (max. 10 classes of code)
	int mycount = 0; // Amount of my classes

	srand(time(0));
	int count = loadData(classes);
	printf("> Load %d classes.\n", count);

	while(1){
		printf("\n> Menu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save 0.Quit\n");
		printf(">> Menu? > ");
		scanf("%d", &no);

		if(no == 1){ 
			printf("> 1.Class list (%d classes)\n", count);
			printAllClasses(classes, count);
		}
		else if(no == 2){ 
			printf("> 2.Add a Class\n");
			count = addNewClass(classes, count);
		}
		else if(no == 3){ 
			printf("> 3.Modify a Class\n");
			editClass(classes, count);
		}
		else if(no == 4){
			printf("> 4.Search a Class\n");
			printf(">> Enter class name > ");
			char name[30];
			scanf("%s", name);
			findClasses(name, classes, count);
		}
		else if(no == 5){
			printf("> 5.Apply a class\n");
			mycount = applyMyClasses(myclass, mycount, classes, count);
			printf("%d classes has been applied.\n", mycount);
		}
		else if(no == 6){
			printf("> 6.My classes\n");
			printMyClasses(myclass, mycount, classes, count);
		}
		else if(no == 7){
			printf("> 7.Save\n");
			saveMyClass(myclass, mycount, classes, count);
			printf("\n> All my classes ware saved to my_classes.txt.\n");
			saveAllClasses(classes, count);
			printf("\n> All of class list ware saved to classes.txt.\n");
		}
		else break;
	}
	return 0;
}

int loadData(struct st_class* c[]){
	int count=0;
	FILE* file;

	file=fopen("classes.txt", "r");
	while(!feof(file)){
		c[count] = (struct st_class*)malloc(sizeof(struct st_class));
		int r = fscanf(file, "%d %s %d %d", &(c[count]->code),c[count]->name, &(c[count]->unit), &(c[count]->grading));
		if(r < 4) break;
		count++;
	}
	fclose(file);
	return count;
}

void printAllClasses(struct st_class* c[], int csize){
	for(int i=0; i<csize; i++){
		printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
	}
}

void saveAllClasses(struct st_class* c[], int csize){
	FILE* file;
	file = fopen("classes.txt", "w");
	for(int i=0; i<csize; i++){
		fprintf(file, "%d %s %d %d\n",c[i]->code, c[i]->name, c[i]->unit, c[i]->grading);
	}
	fclose(file);	
}

void findClasses(char* name, struct st_class* c[], int csize){
	int count = 0;

	printf("Searching (keyword : %s)\n", name);
	for(int i=0; i<csize; i++){
		if(strstr(c[i]->name, name)){
			printf("[%d] %s [credit %d - %s]\n",c[i]->code, c[i]->name, c[i]->unit, kname[c[i]->grading-1]);
			count++;
		}
	}
	printf("%d classes found.\n", count);
}

// You must complete these functions.
int addNewClass(struct st_class* c[], int csize){
// Caution : Don't allow the duplicate class code.
// You must complete this function.


	struct st_class* p = (struct st_class*)malloc(sizeof(struct st_class));

	// 주의사항 : 중복 시 중복 메시지 및 재입력 받기
	// 1. 반복문에서 사용할 중복 확인용 Integer 변수 선언
	// 변수 pass가 0이면 반복 무한
	//	입력 코드
	// 	2. 반복문으로 확인 작업 from i = 0 to csize
	// 		만약 입력 코드와 목록 내 코드와 동일할 시 중복. 중복 메시지 및 2 반복문 종료 (pass == 0)
	// 		아니면 pass = 1 (중복 X)
	// 	만약 중복 아닐 시 break
	
    int pass = 0;      // 1 pass, 0 not pass
    while(pass == 0){
        printf(">> code number > ");
	    scanf("%d", &(p->code));
        
        for(int i = 0; i < csize; i ++){
            if(p->code == c[i]->code){
                printf(">> Code duplicated! Retry.\n");
				pass = 0;
                break;
            }else{
                pass = 1;
            }
        }
        if(pass == 1){
            break;
        }
    }

	printf(">> class name > ");
	scanf("%s", p->name);
	printf(">> credits > ");
	scanf("%d", &(p->unit));
	printf(">> grading (1: A+~F, 2: P/F) > ");
	scanf("%d", &(p->grading));

	c[csize] = p;
	return csize+1;
}

void editClass(struct st_class* c[], int csize){
	struct st_class* p;
	int code;
	// You must complete this section.

	// addNewClass 함수의 입력 받기 반복문에서 수정하기
	// 중요사항 : 1) 수정할 위치의 index 저장하기 2) pass 1이면 ok, 0이면 목록에 입력된 코드가 없다는 의미이므로 무한 반복
	// 1 반복문
	// 	2 반복문
	// 		입력 코드와 목록 코드가 같을 때 pass, idx에 index number(i) 저장 및 반복문 종료

	int pass = 0;				// 1 pass, 0 not pass
	int idx = 0;				// save i
	while(pass == 0){
		printf(">> Enter a code of class > ");
		scanf("%d", &code);
		for(int i = 0; i < csize; i++){
			if(code == c[i]->code){
				pass = 1;
				idx = i;
				break;
			}
		}
		if(pass == 1){
			break;
		}else if(pass == 0){
			printf("> No such class.\n");
		}
	}

	p = c[idx];	// p에 struct type의 c[idx]를 assign			
	printf("> Current: [%d] %s [credits %d - %s]\n",p->code, p->name, p->unit, kname[p->grading-1]);
	printf("> Enter new class name > ");
	scanf("%s", p->name);
	printf("> Enter new credits > ");
	scanf("%d", &(p->unit));
	printf("> Enter new grading(1:Grade, 2: P/F) > ");
	scanf("%d", &(p->grading));

	c[idx] = p;					// save modified data
	printf("> Modified.\n");

}


// You must make all these functions.

int applyMyClasses(int my[], int msize, struct st_class* c[], int csize){
	// save idx in myclass
	// editClass와 입력 반복문 동일
	// 	이미 등록된 수업인 경우 다시 입력 받아야 한다.
	//	pass == 1인 경우에, 배열 my에 앞에서 저장한 idx가 있으면 이미 등록된 것이기에 pass == 2
	// 확인된 code의 수업을 출력. 저장된 idx로 출력
	// 배열 my에 index 순서대로 c[]의 idx 넣기 (* my_idx ++ 해주기. index 하나씩 밀기)
	// count ++로 추가된 과목 개수 늘리기
	// add more 메시지 추가 및 조건문 통하여 y or n 판단
	int code = 0;
	int pass = 0;
	int idx = 0;
	int my_idx = 0;
	int yon = 0;		// yes = 1, no = 2
	int count = 0;
	while(1){
		while(pass == 0 || pass == 2){
			pass = 0;								// reset pass
			printf(">> Enter a code of class > ");
			scanf("%d", &code);
			for(int i = 0; i < csize; i++){
				if(code == c[i]->code){
					pass = 1;
					idx = i;
					break;
				}
			}
			
			if(pass == 1){							
				for(int i = 0; i < my_idx; i ++){
					if(my[i] == idx){
						pass = 2;					// Already applied
						break;
					}else{
						pass = 1;
					}
				}
			}
			
			if(pass == 0){
				printf("> No such class.\n");
			}
			if(pass == 1){
				break;
			}
			if(pass == 2){
				printf(">> Already applied.\n");
			}
		}
		printf("[%d] %s [credit %d - %s]\n",c[idx]->code, c[idx]->name, c[idx]->unit, kname[c[idx]->grading-1]);
		my[my_idx++] = idx;		// class 추가 이후에 배열 my의 인덱스 증가
		count ++;				// 추가한 class count
		
		printf(">> Add more?(1:Yes 2:No) > ");
		scanf("%d", &yon);
		if(yon == 1){
			pass = 0;
		}
		if(yon == 2){
			break;
		}
	}
	msize = count;				// 카운트된 class를 msize에 넣기
	return count;
}

void printMyClasses(int my[], int msize, struct st_class* c[], int csize){
	// 전체 크레딧 출력해야 하므로 integer all_credit 선언
	// from 0 to msize 만큼 반복하여 신청한 class 출력
	// 결과 출력
	int all_credit = 0;
	for(int i = 0; i < msize; i ++){
		printf("%d. [%d] %s [credit %d - %s]\n",i + 1 ,c[my[i]]->code, c[my[i]]->name, c[my[i]]->unit, kname[c[my[i]]->grading-1]);
		all_credit += c[my[i]]->unit;
	}
	printf("All : %d credits\n", all_credit);
}

void saveMyClass(int my[], int msize, struct st_class* c[], int csize){
	// credit 변수 선언(all, grade, pf)
	// 파일 my_classes.txt 쓰기 모드로 열기
	// 양식대로 메시지 출력
	// from 0 to msize 만큼 my class 정보 출력
	// 만약 (c[my[i]]->grading) == 1 이면 grade_credit을 늘리고, 아니면 pr_credit 늘리기
	// all credit 늘리기
	// 양식대로 출력
	// 파일 닫기
	int all_credit = 0;
	int grade_credit = 0;
	int pf_credit = 0;
	FILE* file;
	file=fopen("my_classes.txt", "w");
	fprintf(file, "My Classes\n");
	for(int i = 0; i < msize; i ++){
		fprintf(file, "%d. [%d] %s [credit %d - %s]\n", i + 1, (c[my[i]]->code),c[my[i]]->name, (c[my[i]]->unit),  kname[c[my[i]]->grading-1]);
		if( (c[my[i]]->grading) == 1 ){	
			grade_credit += c[my[i]]->unit;
		}else{
			pf_credit += c[my[i]]->unit;
		}
		all_credit += c[my[i]]->unit;

	}
	fprintf(file, "All : %d classes, %d credits (A+~F %d credits, P/F %d credits)\n", msize, all_credit, grade_credit, pf_credit );
	fclose(file);
}