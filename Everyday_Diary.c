#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "diaryStruct.h"

int selectMenu(){
    int menu;
    printf("\n|------------ ���ϸ��� ���̾ ------------|\n");
    printf("| 1. �ϱ� ��ȸ | 2. �ϱ� �߰� | 3. �ϱ� ���� | 4. �ϱ� ���� | 0. ���� |\n\n=> ���ϴ� �޴���? ");
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