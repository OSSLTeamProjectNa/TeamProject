#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct diary{
    int year;
    int month;
    int date;
    int bookMark;
    char names[100];
    char title[100];
    char content[1000]; //공백포함
    int password;
    int weather; //맑음, 바람, 비, 눈, 흐림 중에 설정
} Diary;
