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
        printf("해당 번호의 일기는 이미 삭제 되었습니다.");
        return;
    }
    printf("날짜: %d년 %d월 %d일\n", d->year, d->month, d->date);
    printf("날씨: %d\n", d->weather);
    printf("제목: %s\n", d->title);
    printf("\n%s\n\n", d->content);
    printf("추억을 함께한 사람: %s\n", d->names);
}

int addDiary(Diary *d){
        printf("날짜를 년도, 월, 일 순서로 공백으로 구분하여 입력해주세요. (ex. 2023 05 16): ");
        scanf("%d %d %d", &d->year, &d->month, &d->date);

        printf("일기의 날씨를 숫자로 입력 해주세요. (1.맑음, 2.바람, 3.비 4.눈 5.흐림): ");
        scanf("%d", &d->weather);

        getchar();
        printf("일기의 제목을 입력 해주세요. (글자 수 제한: 15글자): ");
        fgets(d->title, 100, stdin);
        if(d->title[strlen(d->title)-1]=='\n') d->title[strlen(d->title)-1]=0;
        
        printf("일기의 내용을 입력 해주세요. (글자 수 제한: 1000글자): ");
        fgets(d->content, 1000, stdin);
        if(d->content[strlen(d->content)-1]=='\n') d->content[strlen(d->content)-1]=0;

        printf("이 추억에 함께한 인물들을 적어주세요. (글자 수 제한: 100글자): ");
        fgets(d->names, 100, stdin);
        if(d->names[strlen(d->names)-1]=='\n') d->names[strlen(d->names)-1]=0;

        d->password = -1;
        d->bookMark = 0;

        return 1;
}


int updateDiary(Diary *d){
        printf("날짜를 년도, 월, 일 순서로 공백으로 구분하여 입력해주세요. (ex. 2023 05 16): ");
        scanf("%d %d %d", &d->year, &d->month, &d->date);
        printf("일기의 날씨를 숫자로 입력 해주세요. (1.맑음, 2.바람, 3.비 4.눈 5.흐림): ");
        scanf("%d", &d->weather);
        
        getchar();
        printf("일기의 제목을 입력 해주세요. (글자 수 제한: 15글자): ");
        fgets(d->title, 100, stdin);
        if(d->title[strlen(d->title)-1]=='\n') d->title[strlen(d->title)-1]=0;
        
        printf("일기의 내용을 입력 해주세요. (글자 수 제한: 1000글자): ");
        fgets(d->content, 1000, stdin);
        if(d->content[strlen(d->content)-1]=='\n') d->content[strlen(d->content)-1]=0;

        printf("이 추억에 함께한 인물들을 적어주세요. (글자 수 제한: 100글자): ");
        fgets(d->names, 100, stdin);
        if(d->names[strlen(d->names)-1]=='\n') d->names[strlen(d->names)-1]=0;

        d->password = -1;

    printf("=> 수정성공!");
    return 1;
}

void deleteDiary(Diary *d){
    free(d);
    d->year = -1;
}
        