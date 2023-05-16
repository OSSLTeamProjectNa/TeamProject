#include <stdio.h>

typedef struct diary{
    int year[4];
    int month[2];
    int date[2];
    char names[100];
    char title[15];
    char content[1000]; //공백포함
    int password [4];
    char weather[3]; //맑음, 바람, 비, 눈, 흐림 중에 설정
} Diary;
