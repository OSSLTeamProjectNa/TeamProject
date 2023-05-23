
#include "diaryFile.h"

int selectMenu(){
    int menu;
    printf("\n|------------ 매일매일 다이어리 ------------|\n");
    printf("| 1. 일기 조회 | 2. 일기 추가 | 3. 일기 수정 | 4. 일기 삭제 | 5. 즐겨찾기 목록 | 6. 즐겨찾기 추가/삭제 |\n| 7. 함께한 인물 이름별 검색 | 8. 제목으로 검색 | 9. 비밀 일기 목록 | 10. 비밀 일기 설정/해제 | 14. 일기 저장 | 0. 종료 |\n\n=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

void listDiary(Diary *d[], int count){
    printf("\n| NO | BookMark | YYYY-MM-DD | Title         Locked\n");
    printf("=====================================================\n");
    for(int i =0; i <count ; i++){
        if(d[i]->year != -1){
            printf("%2d ", i+1);
            readDiary(*d[i]);
            printf("\n");
        }
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
        printf("\n");
        }
}

void setBookmark(Diary *d){
    if (d->bookMark == 1){
        d->bookMark = 0;
    }
    else d->bookMark = 1;
}

void listSecretDiary(Diary *d[], int count){
    printf("\n| NO | BookMark | YYYY-MM-DD | Title         Locked\n");
    printf("=====================================================\n");
    
    for(int i =0; i <count ; i++){
        if(d[i]->year == -1) continue;
        if (d[i]->password == -1) continue;
        printf("%2d ", i+1);
        readDiary(*d[i]);
        printf("\n");
        }
}

void switchSecretDiary(Diary *d){
    if (d->password == -1){
        int temp;
        printf("비밀번호를 설정해 주세요 (숫자 4자리 ~ 8자리) : ");
        scanf("%d", &temp);
        d->password = temp;
        printf("비밀번호가 설정되었습니다!\n");
    }
    else {
        int temp;
        while(1){
            printf("비밀번호를 입력해 주세요 (숫자 4자리 ~ 8자리, 취소 -1) : ");
            scanf("%d", &temp);
            if (temp == -1) break;
            else if (temp != d->password) printf("비밀번호가 틀렸습니다!\n");
            else{
                d->password = -1;  
                printf("일기 잠금이 해제 되었습니다!\n");
                break;
            }
        }
    }
}


int selectNum(Diary *d[], int max){
    listDiary(d,max);
    int no;
    printf("\n원하는 일기 번호는(취소 :0)? ");
    scanf("%d", &no);

    return no;
}


int searchName(Diary *d[], char *tname, int count){
    int index = 0;
    for (int i =0; i<count; i++){
        if (d[i]->year == -1) continue;
        if (strstr(d[i]->names,tname) != 0) {
            index++;
            printf("| %d |", index);
            readDiary(*d[i]);
            printf("\n");
        }
    }

    return index;
}

int searchTitle(Diary *d[], char *ttitle, int count){
    int index = 0;
    for (int i =0; i<count; i++){
        if (d[i]->year == -1) continue;
        if (strstr(d[i]->title,ttitle) != 0) {
            index++;
            printf("| %d |", index);
            readDiary(*d[i]);
            printf("\n");
        }
    }

    return index;
}


int main(){
    Diary *d[100];
    int menu, count, index;

    
    index = loadDiary(d);
    count = index;


    while (1){
        printf("\n>>>>>>>index: %d | count: %d<<<<<<<<<<<<\n", index, count);

        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            int no = -1;
            while (no != 0){
                no = selectNum(d,index);
                viewDiary(d[no-1]);
            }
        }
        else if (menu == 2){
            d[index] = (Diary *)malloc(sizeof(Diary));
            addDiary(d[index]);
            index++;
            count ++;
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
        }

        else if (menu == 6){
            int itemp;
            while(1){
                itemp = selectNum(d,index);
                if (itemp == 0) break;
                else setBookmark(d[itemp-1]);
            }
        }

        else if (menu == 7){
            char temp[20];
            int index;
            printf("검색 하실 이름을 입력해주세요. ");
            scanf("%s", temp);
            printf("\n| NO | BookMark | YYYY-MM-DD | Title         Locked\n");
            printf("=====================================================\n");

            index = searchName(d,temp, count);
            if (index == 0) printf("해당되는 일기가 없습니다! \n");

        }

        else if (menu==8){
            char temp[20];
            int index;

            printf("검색 하실 제목을 입력해주세요. ");

            scanf("%s", temp);
            printf("\n| NO | BookMark | YYYY-MM-DD | Title         Locked\n");
            printf("=====================================================\n");
            index = searchTitle(d,temp, count);
            if (index == 0) printf("해당되는 일기가 없습니다! \n");
        }

        else if (menu == 9){
            printf("\n=======비밀 일기 목록=======");
            listSecretDiary(d, count);
            int no = -1;
            while(no!=0){
                printf("원하는 비밀 일기 번호는(취소 :0)? ");
                scanf("%d", &no);
                int password;
                while (1){
                    printf("비밀번호를 입력 해주세요 (취소: -1):");
                    scanf("%d", &password);
                    if(password == -1) break;
                    else if (password != d[no-1]->password){
                        printf("비밀번호가 틀렸습니다!\n ");
                    }
                    else{
                        viewDiary(d[no-1]);
                        no = 0;
                        break;
                    }
                }
            }
        }

        else if (menu ==10){
            int itemp;
            while(1){
                printf("====일기 잠금/해제====\n");
                itemp = selectNum(d,index);
                if (itemp == 0) break;
                else switchSecretDiary(d[itemp-1]);
            }
        }
        
        else if (menu==14){
            saveDiary(d, count);
        }

    }
        
    return 0;
}