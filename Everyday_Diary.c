
#include "diaryFile.h"

int selectMenu(){
    int menu;
    printf("\n|------------ ���ϸ��� ���̾ ------------|\n");
    printf("| 1. �ϱ� �ȸ | 2. �ϱ� �߰� | 3. �ϱ� ��� | 4. �ϱ� ��� | 5. ���ã�� ��� | 6. ���ã�� �߰�/��� |\n| 7. �Բ��� �ι� �̸��� �˻� | 8. ������ �˻� | 14. �ϱ� ���� | 0. ��� |\n\n=> ���ϴ� �޴���? ");
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

void setBookmark(Diary *d){
    if (d->bookMark == 1){
        d->bookMark = 0;
    }
    else d->bookMark = 1;
}

int selectNum(Diary *d[], int max){
    listDiary(d,max);
    int no;
    printf("\n���ϴ� �ϱ� ��ȣ��(��� :0)? ");
    scanf("%d", &no);

    return no;
}


int searchName(Diary *d[], char *tname, int count){
    int index = -1;
    for (int i =0; i<count; i++){
        if (d[i]->year == -1) continue;
        if (strstr(d[i]->names,tname)== 0) {
            index = i;
            break;
        }
    }

    return index;
}

int searchTitle(Diary *d[], char *tname, int count){
    int index = -1;
    for (int i =0; i<count; i++){
        if (d[i]->year == -1) continue;
        if (strstr(d[i]->title,tname)== 0) {
            index = i;
            break;
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
        printf("%d", d[0]->year);

        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){listDiary(d, index);}
        else if (menu == 2){
            d[index] = (Diary *)malloc(sizeof(Diary));
            addDiary(d[index]);
            index++;
            count ++;
        }
            else if (menu == 3){ //파일에 저장 
             Diary diaryList[MAX_DIARIES];
            int numDiaries = 0;
            // 일기를 작성하고 diaryList에 추가하는 코드
            // 파일에 일기 저장
            saveDiary(diaryList, numDiaries, "diary.txt");
        }
        else if (menu == 4){
            int no = selectNum(d,index);
            if (no == 0) printf("��ҵ�!\n");
            else updateDiary(d[no-1]);
        }
        else if (menu == 5){
            int no = selectNum(d,index);
            if (no == 0) printf("��ҵ�!\n");
            else {
                int temp;
                printf("������ �����Ͻðڽ��ϱ�? (���� :1) ");
                scanf("%d", &temp);

                if (temp == 1) {
                    if (d[no-1]) {
                        deleteDiary(d[no-1]);
                    }
                    count--;
                }
            }
        }
        else if (menu == 6){
            printf("========���ã�� �� �ϱ� ���=======");
            listBookmark(d, count);
            int imenu;
            int itemp;
        }
        else if (menu == 7){
            int itemp;
            while(1){
                itemp = selectNum(d,index);
                if (itemp == 0) break;
                else setBookmark(d[itemp-1]);
            }
        }
        else if (menu == 8){
            char temp[20];
            int index;
            printf("�˻� �Ͻ� �̸��� �Է����ּ���. ");
            scanf("%s", temp);

            index = searchName(d,temp, count);
            if (index == -1) printf("�ش�Ǵ� �ϱⰡ �����ϴ�! \n");
            else{
                printf("\n| NO | BookMark | YYYY-MM-DD | Title         Locked\n");
                printf("=====================================================\n");
                readDiary(*d[index]);
            }

        }
        else if (menu==9){
            char temp[20];
            int index;
            printf("�˻� �Ͻ� �ϱ��� ������ �Է����ּ���. ");
            scanf("%s", temp);

            index = searchTitle(d,temp, count);
            if (index == -1) printf("�ش�Ǵ� �ϱⰡ �����ϴ�! \n");
            else{
                printf("\n| NO | BookMark | YYYY-MM-DD | Title         Locked\n");
                printf("=====================================================\n");
                readDiary(*d[index]);
            }
        }
        else if (menu==14){
            saveDiary(d, count);
        }


    }
        
    return 0;
}