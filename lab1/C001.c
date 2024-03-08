#include <stdio.h>

int main()
{
    int size;
    int stars, blank1, blank2;
    int i, j;

    scanf("%d", &size);

    blank1 = 0; //  ++
    blank2 = (size * 2) - 2; //  -= 2
    for(i = 0; i < size; i ++){
        for(j = 0; j < blank1; j ++){
            printf(" ");
        }
        printf("*");
        for(j = 0; j < blank2; j ++){
            printf(" ");
        }
        blank1 ++;
        blank2 -= 2;
        printf("*\n");
    }

    for(i = 0; i < size; i ++){
        for(j = 0; j < size * 2; j++){
            printf("*");
        }
        printf("\n");
    }

    blank1 = 0;
    stars = size * 2;
    for(i = 0; i < size; i ++){
        for(j = 0; j < blank1; j++){
            printf(" ");
        }
        for(j = 0; j < stars; j++){
            printf("*");
        }
        blank1 ++;
        stars -= 2;
        printf("\n");
    }
    
    for(i = 0; i < size * 2; i ++){
        printf("*");
    }

    return 0;
}