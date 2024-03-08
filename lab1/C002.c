#include <stdio.h>


int main()
{
    int person[4][3] = {0};             // 4개 층별 3개 호실의 점호 인원 수
    int sum[3] = {0, 0, 0};             // 점호 인원 수 합계 (남, 여, 전체)
    float ratio[3];                     // 점호 인원 수 비율 (남, 여, 전체)
    int i, j;                           // 반복문을 위한 변수
    
    //4층 짜리 생활관의 각 층에는 3개씩 호실이 있고, 각 호실은 모두 4인실이다. 즉, 총 48명이 입주해 있다.
    //1, 2층은 남학생용 호실이고, 3, 4층은 여학생용 호실이다.
    // checking Men and women
    // read person[i][j]
    // compute sum
    printf("Check room (Men)\n");
    for(i = 0; i < 2; i ++){
        for(j = 0; j < 3; j ++){
            printf("Room #%d > ", ((i + 1)* 100) + j + 1);
            scanf("%d", &person[i][j]);
            sum[0] += person[i][j];
        }
    }
    
    printf("Check room (Women)\n");
    for(i = 2; i < 4; i ++){
        for(j = 0; j < 3; j ++){
            printf("Room #%d > ", ((i + 1) * 100) + j + 1);
            scanf("%d", &person[i][j]);
            sum[1] += person[i][j];
        }
    }
    // sum2 is checked person's count
    sum[2] = sum[0] + sum[1];

    // compute percentage 
    for(i = 0; i <= 2; i ++){
        if(i < 2){
            ratio[i] = (sum[i] / 24.0) * 100;    
        }else{
            ratio[i] = (sum[i] / 48.0) * 100;
        }   
    }

    // display result
    printf("Check Result\n");
    printf("Men : %d/24 (%.1f%%)\n", sum[0], ratio[0]);
    printf("Women : %d/24 (%.1f%%)\n", sum[1], ratio[1]);
    printf("Total : %d/48 (%.1f%%)\n", sum[2], ratio[2]);


    return 0;
}