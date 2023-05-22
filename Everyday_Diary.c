
#include "diaryFile.h"

int selectMenu(){
    int menu;
    printf("\n|------------ ï¿½ï¿½ï¿½Ï¸ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½Ì¾î¸® ------------|\n");
    printf("| 1. ï¿½Ï±ï¿½ ï¿½È? | 2. ï¿½Ï±ï¿½ ï¿½ß°ï¿½ | 3. ï¿½Ï±ï¿½ ï¿½ï¿½ï¿? | 4. ï¿½Ï±ï¿½ ï¿½ï¿½ï¿? | 5. ï¿½ï¿½ï¿½Ã£ï¿½ï¿? ï¿½ï¿½ï¿? | 6. ï¿½ï¿½ï¿½Ã£ï¿½ï¿? ï¿½ß°ï¿½/ï¿½ï¿½ï¿? |\n| 7. ï¿½Ô²ï¿½ï¿½ï¿½ ï¿½Î¹ï¿½ ï¿½Ì¸ï¿½ï¿½ï¿½ ï¿½Ë»ï¿½ | 8. ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Ë»ï¿½ | 14. ï¿½Ï±ï¿½ ï¿½ï¿½ï¿½ï¿½ | 0. ï¿½ï¿½ï¿? |\n\n=> ï¿½ï¿½ï¿½Ï´ï¿½ ï¿½Þ´ï¿½ï¿½ï¿½? ");
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

int selectNum(Diary *d[], int max){
    listDiary(d,max);
    int no;
    printf("\nï¿½ï¿½ï¿½Ï´ï¿½ ï¿½Ï±ï¿½ ï¿½ï¿½È£ï¿½ï¿½(ï¿½ï¿½ï¿? :0)? ");
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
        if (menu == 1){listDiary(d, index);}
        else if (menu == 2){
            d[index] = (Diary *)malloc(sizeof(Diary));
            addDiary(d[index]);
            index++;
            count ++;
        }
        else if (menu == 3){
            int no = selectNum(d,index);
            if (no == 0) printf("Ãë¼ÒµÊ!\n");
            else updateDiary(d[no-1]);
        }
        else if (menu == 4){
            int no = selectNum(d,index);
            if (no == 0) printf("ï¿½ï¿½Òµï¿?!\n");
            else updateDiary(d[no-1]);
        }
        else if (menu == 5){
            int no = selectNum(d,index);
            if (no == 0) printf("ï¿½ï¿½Òµï¿?!\n");
            else {
                int temp;
                printf("ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ï½Ã°Ú½ï¿½ï¿½Ï±ï¿½? (ï¿½ï¿½ï¿½ï¿½ :1) ");
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
            printf("========ï¿½ï¿½ï¿½Ã£ï¿½ï¿? ï¿½ï¿½ ï¿½Ï±ï¿½ ï¿½ï¿½ï¿?=======");
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
            printf("ï¿½Ë»ï¿½ ï¿½Ï½ï¿½ ï¿½Ì¸ï¿½ï¿½ï¿½ ï¿½Ô·ï¿½ï¿½ï¿½ï¿½Ö¼ï¿½ï¿½ï¿½. ");
            scanf("%s", temp);
            printf("\n| NO | BookMark | YYYY-MM-DD | Title         Locked\n");
            printf("=====================================================\n");

            index = searchName(d,temp, count);
            if (index == 0) printf("ÇØ´çµÇ´Â ÀÏ±â°¡ ¾ø½À´Ï´Ù! \n");

        }
        else if (menu==9){
            char temp[20];
            int index;

            printf("°Ë»ö ÇÏ½Ç Á¦¸ñÀ» ÀÔ·ÂÇØÁÖ¼¼¿ä. ");

            scanf("%s", temp);
            printf("\n| NO | BookMark | YYYY-MM-DD | Title         Locked\n");
            printf("=====================================================\n");
            index = searchTitle(d,temp, count);
            if (index == 0) printf("ÇØ´çµÇ´Â ÀÏ±â°¡ ¾ø½À´Ï´Ù! \n");
        }
        else if (menu==14){
            saveDiary(d, count);
        }

    }
        
    return 0;
}