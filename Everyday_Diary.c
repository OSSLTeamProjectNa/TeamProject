#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "diaryStruct.h"

int selectMenu(){
    int menu;
    printf("\n|------------ 매일매일 다이어리 ------------|\n");
    printf("| 1. 일기 조회 | 2. 일기 추가 | 3. 일기 수정 | 4. 일기 삭제 | 0. 종료 |\n\n=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int main(void){
    Diary *d[20];
    int menu, count, index;
    count = 0;
    index = 0;

    while (1){
        if (menu == 0) break;
        if (menu == 1){printf("menu 1");}
        else if (menu == 2){printf("menu 2");}
        else if (menu == 3){printf("menu 3");}
        else if (menu == 4){printf("menu 4");}
    }
        
    return 0;
}