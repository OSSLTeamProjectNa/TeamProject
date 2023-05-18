#include "diaryCRUD.h"

void readDiary(Diary d){
    char isLocked = 'X';
    char isBookMark = 'X';
    if (d.password[0] != -1) isLocked = 'O';
    if (d.bookMark != 0) isBookMark = 'O';
    printf("| %c | %d-%d-%d | %s | %c |", isBookMark, d.year, d.month, d.date, d.title, isLocked);
}

void viewDiary(Diary *d){
    printf("��¥: %d�� %d�� %d��\n", d->year, d->month, d->date);
    printf("����: %s\n", d->weather);
    printf("����: %s\n", d->title);
    printf("\n%s\n\n", d->content);
    printf("�߾��� �Բ��� ���: %s\n", d->names);
}

int addDiary(Diary *d){
        printf("��¥�� �⵵, ��, �� ������ �������� �����Ͽ� �Է����ּ���. (ex. 2023 05 16): ");
        scanf("%d %d %d", &d->year, &d->month, &d->date);
        printf("�ϱ��� ������ �Է� ���ּ���. (ex. ����, �帲, �� ��): ");
        scanf("%s", d->weather);
        printf("�ϱ��� ������ �Է� ���ּ���. (���� �� ����: 15����): ");
        scanf("%s",d->title);
        printf("�ϱ��� ������ �Է� ���ּ���. (���� �� ����: 1000����): ");
        scanf("%s",&d->content);
        printf("�� �߾￡ �Բ��� �ι����� �����ּ���. (���� �� ����: 100����): ");
        scanf("%s", &d->names);
        d->password[0] = -1;
        d->bookMark = 0;

        return 1;
}


int updateDiary(Diary *d){
    printf("��¥�� �⵵, ��, �� ������ �������� �����Ͽ� �Է����ּ���. (ex. 2023 05 16): ");
    scanf("%d %d %d", &d->year, &d->month, &d->date);
    printf("�ϱ��� ������ �Է� ���ּ���. (ex. ����, �帲, �� ��): ");
    scanf("%s", d->weather);
    printf("�ϱ��� ������ �Է� ���ּ���. (���� �� ����: 15����): ");
    scanf("%s",d->title);
    printf("�ϱ��� ������ �Է� ���ּ���. (���� �� ����: 1000����): ");
    scanf("%s",d->content);
    printf("�� �߾￡ �Բ��� �ι����� �����ּ���. (���� �� ����: 100����): ");
    scanf("%s", d->names);
    d->password[0] = -1;

    printf("=> ��������!");
    return 1;
}

void deleteDiary(Diary *d){
    free(d);
    d->year = -1;
}
        