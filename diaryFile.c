#include "diaryFile.h"

/*
2002 3 6 0 1754 맑음
나시윤 홍길동
일기 제목 입니다
일기 내용 입니다 일기 내용 입니다 일기 내용 입니다
*/

void saveDiary(Diary *d[], int count){
    FILE *fp;
    fp = fopen("diary.txt", "wt");
    for(int i = 0; i < count; i++){

        if(d[i]->year == -1) continue;
        fprintf(fp, "%d %d %d %d %d %d\n", d[i]->year, d[i]->month, d[i]->date, d[i]->bookMark, d[i]->weather);
        fprintf(fp, "%s\n", d[i]->names);
        fprintf(fp, "%s\n", d[i]->title);
        fprintf(fp, "%s\n", d[i]->content);
    }
    fclose(fp);
    printf("=> 저장됨!\n ");
}


int loadDiary (Diary *d[]){
    FILE *fp;
    fp = fopen("diary.txt", "rt");
    int i=0;
    
    if (fp == NULL){
        printf("텍스트 파일이 존재하지 않습니다! \n");
        return (0);
    }


    char str[100];
    while(fgets(str, 128, fp) != NULL){

        d[i]=(Diary*)malloc(sizeof(Diary));
        char * temp;
        temp = strtok(str," ");

        d[i]->year = atoi(temp);
        temp = strtok(NULL, " ");
        d[i]->month = atoi(temp);
        temp = strtok(NULL, " ");
        d[i]->date = atoi(temp);
        temp = strtok(NULL, " ");
        d[i]->bookMark = atoi(temp);
        temp = strtok(NULL, " ");
        d[i]->password = atoi(temp);
        temp = strtok(NULL, " ");
        d[i]->weather = atoi(temp);
        
        fgets(d[i]->names,100,fp);
        d[i]->names[strlen(d[i]->names)-1] = 0;
        fgets(d[i]->title,100,fp);
        d[i]->title[strlen(d[i]->title)-1] = 0;
        fgets(d[i]->content,500,fp);
        d[i]->content[strlen(d[i]->content)-1] = 0;

        i++;

    }   

    fclose(fp);
    printf("불러오기 성공!\n");

    return i;
}

