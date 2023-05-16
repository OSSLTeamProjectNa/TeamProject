#include "diaryCRUD.h"

void readDiary(Diary d){
    char isLocked = 'X';
    if (d.password[0] != -1) isLocked = 'O';
    printf("| %d-%d-%d | %s | %c |", d.year, d.month, d.date, d.title, isLocked);
}

int addDiary(Diary *d){
        printf("��¥�� �⵵, ��, �� ������ �������� �����Ͽ� �Է����ּ���. (ex. 2023 05 16): ");
        scanf("%d %d %d",d->year, d->month, d->date);
        printf("�ϱ��� ������ �Է� ���ּ���. (ex. ����, �帲, �� ��): ");
        scanf("%s", d->weather);
        printf("�ϱ��� ������ �Է� ���ּ���. (���� �� ����: 15����): ");
        scanf("%s",d->title);
        printf("�ϱ��� ������ �Է� ���ּ���. (���� �� ����: 1000����): ");
        scanf("%s",&d->content);
        printf("�� �߾￡ �Բ��� �ι����� �����ּ���. (���� �� ����: 100����): ");
        scanf("%s", &d->names);
        d->password[0] = -1;

        return 1;
}


int updateDiary(Diary *d){
    printf("��¥�� �⵵, ��, �� ������ �������� �����Ͽ� �Է����ּ���. (ex. 2023 05 16): ");
    scanf("%d %d %d",d->year, d->month, d->date);
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
