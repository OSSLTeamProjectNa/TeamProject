#include "diaryFile.h"

/*
2002 3 6 0 1754 ����
������ ȫ�浿
�ϱ� ���� �Դϴ�
�ϱ� ���� �Դϴ� �ϱ� ���� �Դϴ� �ϱ� ���� �Դϴ�
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
    printf("=> �����!\n ");
}


int loadDiary (Diary *d[]){
    FILE *fp;
    fp = fopen("diary.txt", "rt");
    int i=0;
    
    if (fp == NULL){
        printf("�ؽ�Ʈ ������ �������� �ʽ��ϴ�! \n");
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
    printf("�ҷ����� ����!\n");

    return i;
}

