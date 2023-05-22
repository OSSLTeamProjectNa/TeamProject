#include "diaryCRUD.h"



void readDiary(Diary d){
    
    char isLocked = 'X';
    char isBookMark = 'X';
    if (d.password != -1) isLocked = 'O';
    if (d.bookMark != 0) isBookMark = 'O';
    printf("| %c | %d-%d-%d | %s | %c |", isBookMark, d.year, d.month, d.date, d.title, isLocked);
}

void viewDiary(Diary *d){
    if(d->year == -1){
        printf("�ش� ��ȣ�� �ϱ�� �̹� ���� �Ǿ����ϴ�.");
        return;
    }
    printf("��¥: %d�� %d�� %d��\n", d->year, d->month, d->date);
    printf("����: %d\n", d->weather);
    printf("����: %s\n", d->title);
    printf("\n%s\n\n", d->content);
    printf("�߾��� �Բ��� ���: %s\n", d->names);
}

int addDiary(Diary *d){
        printf("��¥�� �⵵, ��, �� ������ �������� �����Ͽ� �Է����ּ���. (ex. 2023 05 16): ");
        scanf("%d %d %d", &d->year, &d->month, &d->date);

        printf("�ϱ��� ������ ���ڷ� �Է� ���ּ���. (1.����, 2.�ٶ�, 3.�� 4.�� 5.�帲): ");
        scanf("%d", &d->weather);

        getchar();
        printf("�ϱ��� ������ �Է� ���ּ���. (���� �� ����: 15����): ");
        fgets(d->title, 100, stdin);
        if(d->title[strlen(d->title)-1]=='\n') d->title[strlen(d->title)-1]=0;
        
        printf("�ϱ��� ������ �Է� ���ּ���. (���� �� ����: 1000����): ");
        fgets(d->content, 1000, stdin);
        if(d->content[strlen(d->content)-1]=='\n') d->content[strlen(d->content)-1]=0;

        printf("�� �߾￡ �Բ��� �ι����� �����ּ���. (���� �� ����: 100����): ");
        fgets(d->names, 100, stdin);
        if(d->names[strlen(d->names)-1]=='\n') d->names[strlen(d->names)-1]=0;

        d->password = -1;
        d->bookMark = 0;

        return 1;
}


int updateDiary(Diary *d){
        printf("��¥�� �⵵, ��, �� ������ �������� �����Ͽ� �Է����ּ���. (ex. 2023 05 16): ");
        scanf("%d %d %d", &d->year, &d->month, &d->date);
        printf("�ϱ��� ������ ���ڷ� �Է� ���ּ���. (1.����, 2.�ٶ�, 3.�� 4.�� 5.�帲): ");
        scanf("%d", &d->weather);
        
        getchar();
        printf("�ϱ��� ������ �Է� ���ּ���. (���� �� ����: 15����): ");
        fgets(d->title, 100, stdin);
        if(d->title[strlen(d->title)-1]=='\n') d->title[strlen(d->title)-1]=0;
        
        printf("�ϱ��� ������ �Է� ���ּ���. (���� �� ����: 1000����): ");
        fgets(d->content, 1000, stdin);
        if(d->content[strlen(d->content)-1]=='\n') d->content[strlen(d->content)-1]=0;

        printf("�� �߾￡ �Բ��� �ι����� �����ּ���. (���� �� ����: 100����): ");
        fgets(d->names, 100, stdin);
        if(d->names[strlen(d->names)-1]=='\n') d->names[strlen(d->names)-1]=0;

        d->password = -1;

    printf("=> ��������!");
    return 1;
}

void deleteDiary(Diary *d){
    free(d);
    d->year = -1;
}
        