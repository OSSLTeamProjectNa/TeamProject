#include "diaryCRUD.h"

void readDiary(Diary d){
    char isLocked = 'X';
    if (d.password[0] != -1) isLocked = 'O';
    printf("| %d-%d-%d | %s | %c |", d.year, d.month, d.date, d.title, isLocked);
}

int addDiary(Diary *d){
        printf("날짜를 년도, 월, 일 순서로 공백으로 구분하여 입력해주세요. (ex. 2023 05 16): ");
        scanf("%d %d %d",d->year, d->month, d->date);
        printf("일기의 날씨를 입력 해주세요. (ex. 맑음, 흐림, 비 등): ");
        scanf("%s", d->weather);
        printf("일기의 제목을 입력 해주세요. (글자 수 제한: 15글자): ");
        scanf("%s",d->title);
        printf("일기의 내용을 입력 해주세요. (글자 수 제한: 1000글자): ");
        scanf("%s",&d->content);
        printf("이 추억에 함께한 인물들을 적어주세요. (글자 수 제한: 100글자): ");
        scanf("%s", &d->names);
        d->password[0] = -1;

        return 1;
}


int updateDiary(Diary *d){
    printf("날짜를 년도, 월, 일 순서로 공백으로 구분하여 입력해주세요. (ex. 2023 05 16): ");
    scanf("%d %d %d",d->year, d->month, d->date);
    printf("일기의 날씨를 입력 해주세요. (ex. 맑음, 흐림, 비 등): ");
    scanf("%s", d->weather);
    printf("일기의 제목을 입력 해주세요. (글자 수 제한: 15글자): ");
    scanf("%s",d->title);
    printf("일기의 내용을 입력 해주세요. (글자 수 제한: 1000글자): ");
    scanf("%s",d->content);
    printf("이 추억에 함께한 인물들을 적어주세요. (글자 수 제한: 100글자): ");
    scanf("%s", d->names);
    d->password[0] = -1;

    printf("=> 수정성공!");
    return 1;
}
