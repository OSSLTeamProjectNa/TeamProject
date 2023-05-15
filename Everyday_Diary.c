#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "diaryStruct.h"

int main(void){
    Diary *d[20];
    int menu, count, index;
    count = 0;
    index = 0;

    while (1){
        printf("menu num? : ");
        scanf("%d",&menu);
        if (menu == 0) break;
        if (menu == 1){printf("menu 1");}
        else if (menu == 2){printf("menu 2");}
        else if (menu == 3){printf("menu 3");}
        else if (menu == 4){printf("menu 4");}
    }
        
    return 0;
}