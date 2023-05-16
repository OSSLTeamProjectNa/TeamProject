#include "diaryCRUD.h"

int selectMenu(){
    int menu;
    printf("\n|------------ 매일매일 다이어리 ------------|\n");
    printf("| 1. 일기 조회 | 2. 일기 추가 | 3. 일기 수정 | 4. 일기 삭제 | 0. 종료 |\n\n=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

void listDiary(Diary *d[], int count){
    printf("\nNO | YYYY-MM-DD | Title                      Locked\n");
    printf("=====================================================\n");
    for(int i =0; i <count ; i++){
        if(d[i]->year == -1) continue;
        printf("%2d ", i+1);
        readDiary(*d[i]);
        printf("\n");
    }
   
}


int selectNum(Diary *d[], int max){
    listDiary(d,max);
    int no;
    printf("\n원하는 일기 번호는(취소 :0)? ");
    scanf("%d", &no);

    return no;
}


int main(){
    Diary *d[20];
    int menu, count, index;
    count = 0;
    index = 0;


    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){listDiary(d, count);}
        else if (menu == 2){
            d[index] = (Diary *)malloc(sizeof(Diary));
            addDiary(d[index]);
            index++;
            count++;
        }
        else if (menu == 3){
            int no = selectNum(d,index);
            if (no == 0) printf("취소됨!\n");
            else updateDiary(d[no-1]);
        }
        else if (menu == 4){printf("menu 4");}
    }
        
    return 0;
}