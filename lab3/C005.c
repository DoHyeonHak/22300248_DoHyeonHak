// Enter your student ID and Fullname

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 50

char LNAME[5][30]={"Graphite","Opal","Bronze","Silver","Gold"}; // labels by level

struct st_channel{
	char name[100]; // Channel name
	int count;	  // # of subscriptions
	int level;	  // index of level (0~4)
};

int loadData(struct st_channel* c[]); 
int findLevel(int num); 
void printStatistics(struct st_channel* c[], int size);
void printChannels(struct st_channel* c[], int size);
void pickupRandomChannels(struct st_channel* c[], int size);
void searchChannel(struct st_channel* c[], int size);
int addChannel(struct st_channel* c[], int size);
void updateChannel(struct st_channel* c[], int size);
int deleteChannel(struct st_channel* c[], int size);
void makeReport(struct st_channel* c[], int size); 

int main(void) {
	int no;	// amount of channels
	struct st_channel* clist[SIZE]; // channel list
	int menu; // menu number 

	srand(time(0));
	no = loadData(clist);

	while(1)
	{
		// Print menu
		printf("\n[1]List [2]Statistics [3]Random pick [4]Search [5]Add [6]Modify [7]Delete [8]Report [0]Exit\n> Enter a menu >> ");
		scanf("%d",&menu);	

		if(menu==1){
			printChannels(clist, no); // Print all list of channels
		}
		else if(menu==2){
			printStatistics(clist, no);	// Print statistics of each level
		}
		else if(menu==3){
			pickupRandomChannels(clist, no); // Pick up random channels
		}
		else if(menu==4){
			searchChannel(clist, no);	// Search a channel
		}
		else if(menu==5){
			no = addChannel(clist, no); // Add a channel
		}
		else if(menu==6){
			updateChannel(clist, no); // Modify a channel
		}
		else if(menu==7){
			no = deleteChannel(clist, no); // Delete a channel
		}
		else if(menu==8){
			makeReport(clist, no);	// Make a Report
		}
		else {
			break;
		}
	}
	return 0;
}

int loadData(struct st_channel* c[]){
	int no=0;
	FILE* file;

	file=fopen("channels.txt", "r");
	while(!feof(file)){
		struct st_channel* t = (struct st_channel*)malloc(sizeof(struct st_channel));
		int r=fscanf(file, "%s %d", t->name, &(t->count));
		if(r<2) break;
		t->level = findLevel(t->count);
		c[no] = t;
		no++;
	}
	fclose(file);
	printf("> %d channels are loaded.\n", no);
	return no;
}

int findLevel(int num){
	int range[5]={1000,10000,100000,1000000,10000000}; // range for level
	for(int j=0;j<5;j++)
		if(num<range[j])
			return j;
	return 0;
}

void printChannels(struct st_channel* c[], int size){
	printf("> List of Channels\n");
	for(int i=0; i<size; i++){
		printf("[%2d] %-20s %10d peoples [%s] \n",i+1, c[i]->name, c[i]->count,LNAME[c[i]->level]);
	}
}

int addChannel(struct st_channel* c[], int size){
	struct st_channel* temp;
	printf("> Add a new Channel\n");
	temp = (struct st_channel*)malloc(sizeof(struct st_channel));
	printf("> Enter a name of channel > ");
	scanf("%s", temp->name);
	printf("> Enter an amount of peoples > ");
	scanf("%d", &(temp->count));
	temp->level = findLevel(temp->count);
	c[size] = temp;
	printf("> New channel is added.\n");
	printf("[%2d] %-20s %10d peoples [%s] \n",size+1, c[size]->name, c[size]->count,LNAME[c[size]->level]);
	return size+1;
}

void printStatistics(struct st_channel* c[], int size){
	printf("> Statistics of Channels\n");
	// 각 레벨마다의 통계 자료를 보여주는 함수이다.
	// 1. 레벨이 5개이므로 각 레벨에 따라 필요한 변수를 선안한다. (합, 인원, 최대 계산 배열, 인덱스)
	// 2. 사이즈만큼 반복한다.
	// 3. 각 레벨에 맞는 조건문을 통하여, 합, 인원, 최대 채널 확인 작업을 거친다.
	// 4. 최종 결과를 출력한다.
	float sum[5] = {0};
	int count[5] = {0};
	int max[5] = {0};
	int idx[5] = {0};
	// loop from 0 to size
	for(int i = 0; i < size; i ++){
		// along level
		if(c[i]->level == 0){			// Graphite
			count[0]++;					// count channel
			sum[0] += c[i]->count;		// save c[i]->count for average
			if(max[0] < c[i]->count){	// check max c[i]->count
				max[0] = c[i]->count;
				idx[0] = i;
 			}
		}else if(c[i]->level == 1){		// Opal
			count[1]++;
			sum[1] += c[i]->count;
			if(max[1] < c[i]->count){
				max[1] = c[i]->count;
				idx[1] = i;
 			}
		}else if(c[i]->level == 2){		// Bronze
			count[2]++;
			sum[2] += c[i]->count;
			if(max[2] < c[i]->count){
				max[2] = c[i]->count;
				idx[2] = i;
 			}
		}else if(c[i]->level == 3){		// Silver
			count[3]++;
			sum[3] += c[i]->count;
			if(max[3] < c[i]->count){
				max[3] = c[i]->count;
				idx[3] = i;
 			}
		}else{							// Gold
			count[4]++;
			sum[4] += c[i]->count;
			if(max[4] < c[i]->count){
				max[4] = c[i]->count;
				idx[4] = i;
 			}
		}
	}

	// display result
	for(int i = 0; i < 5; i ++){
		printf("%-8s : %d channels, Average %.1f peoples, Top channel : %s (%d peoples)\n", LNAME[i], count[i], (sum[i] / count[i]), c[idx[i]]->name, c[idx[i]]->count);
	}


}

void pickupRandomChannels(struct st_channel* c[], int size){
	// 랜덤으로 채널 목록을 올리는 함수이다.
	// 1. 몇 개를 뽑을 것인지 읽어야 한다. 읽은 값만큼 반복하여 출력한다.
	// 2. 랜덤 변수가 있어야 한다.
	// 3. 결과 화면 비교했을 때 중복 제거가 필요하므로, 이미 출력된 것에 대하여 인덱스 저장 변수를 만든다.
	int num = 0;
	int random = 0;
	int idx[50] = {0};
	printf("> Pick up Channels\n");
	printf("> How much channels you want to pick up? > ");
	// read num
	scanf("%d", &num);									
	// use loop from 0 to num
	for(int i = 0; i < num; i++){						
		random = rand()% + size;		
		// use if station
		// idx[random] == 0, first time. so display result
		// idx[random] == 1, second time. so i--;
		if(idx[random] == 0){							
			printf("[%d] %s (%s level, %d peoples)\n", random, c[random]->name, LNAME[c[random]->level], c[random]->count);
			idx[random] = 1;							// save index number
		}else if(idx[random] == 1){					
			i--;
		}
	}


}
void searchChannel(struct st_channel* c[], int size){
	printf("> Search Channels\n");
	printf("> Choose one (1:by peoples 2:by names) > ");





}

void updateChannel(struct st_channel* c[], int size){
	printf("> Modify a new Channel\n");
	printf("> Enter a number of channel > ");


}

int deleteChannel(struct st_channel* c[], int size){
	int no, yesno;
	printf("> Delete a new Channel\n");
	printf("> Enter a number of channel > ");

	return size;
}


void makeReport(struct st_channel* c[], int size){


}