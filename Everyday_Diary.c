#include "diaryCRUD.h"

int selectMenu(){
    int menu;
    printf("\n|------------ 매일매일 다이어리 ------------|\n");
    printf("| 1. 일기 조회 | 2. 일기 추가 | 3. 일기 수정 | 4. 일기 삭제 | 5. 즐겨찾기 목록 | 6. 즐겨찾기 추가/삭제 | 0. 종료 |\n\n=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

void listDiary(Diary *d[], int count){
    printf("\n| NO | BookMark | YYYY-MM-DD | Title         Locked\n");
    printf("=====================================================\n");
    for(int i =0; i <count ; i++){
        if(d[i]->year == -1) continue;
        printf("%2d ", i+1);
        readDiary(*d[i]);
        printf("\n");
    }
   
}

void listBookmark(Diary *d[], int count){
    printf("\n| NO | BookMark | YYYY-MM-DD | Title         Locked\n");
    printf("=====================================================\n");
    
    for(int i =0; i <count ; i++){
        if(d[i]->year == -1) continue;
        if (d[i]->bookMark == 0) continue;
        printf("%2d ", i+1);
        readDiary(*d[i]);
        }
    printf("\n");
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
        printf("\n>>>>>>>index: %d | count: %d<<<<<<<<<<<<\n", index, count);
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){listDiary(d, index);}
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
        else if (menu == 4){
            int no = selectNum(d,index);
            if (no == 0) printf("취소됨!\n");
            else {
                int temp;
                printf("정말로 삭제하시겠습니까? (삭제 :1) ");
                scanf("%d", &temp);

                if (temp == 1) {
                    if (d[no-1]) {
                        deleteDiary(d[no-1]);
                    }
                    count--;
                }
            }
        }
        else if (menu == 5){
            printf("========즐겨찾기 한 일기 목록=======");
            listBookmark(d, count);
            int imenu;
            int itemp;
        }

    }
        
    return 0;
}