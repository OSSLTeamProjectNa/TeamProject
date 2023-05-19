#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct diary{
    int year;
    int month;
    int date;
    int bookMark;
    char names[100];
    char title[15];
    char content[1000]; //공백포함
    int password [4];
    char weather[10]; //맑음, 바람, 비, 눈, 흐림 중에 설정
} Diary;


void saveDiary(const Diary *diaryList, int countDiaries, const char *fileName) {

// diaryList: 일기 구조체(Diary) 배열의 포인터
// numDiaries: 저장할 일기의 개수
// fileName: 일기를 저장할 파일의 이름
    FILE *file = fopen(fileName, "wb");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    // 일기의 개수를 파일에 저장
    fwrite(&countDiaries, sizeof(int), 1, file);

    // 일기들을 순회하며 파일에 저장
    for (int i = 0; i < countDiaries; i++) {
        // 일기 구조체를 파일에 저장
        fwrite(&diaryList[i], sizeof(Diary), 1, file);
    }

    fclose(file);
    printf("Diaries saved successfully.\n");
}

#define MAX_DIARIES 100
//. 일기 구조체 배열(Diary 배열)에 저장할 수 있는 최대 일기 개수
// addSecretDiary(diaries, &numDiaries);

void addSecretDiary(Diary *diaryList, int *numDiaries) {
    if (*numDiaries >= MAX_DIARIES) {
        printf("Maximum number of diaries reached.\n"); // 정해진 일기 개수를 초과하였습니다.
        return;
    }

    Diary newDiary;
    printf("Enter the year: ");
    scanf("%d", &newDiary.year);
    printf("Enter the month: ");
    scanf("%d", &newDiary.month);
    printf("Enter the date: ");
    scanf("%d", &newDiary.date);

    printf("Set a password (4 digits): ");
    for (int i = 0; i < 4; i++) {
        scanf("%1d", &newDiary.password[i]);
    }

    printf("Enter the names: ");
    getchar(); // 버퍼 비우기
    fgets(newDiary.names, sizeof(newDiary.names), stdin);
    newDiary.names[strcspn(newDiary.names, "\n")] = '\0'; // 개행 문자 제거

    printf("Enter the title: ");
    fgets(newDiary.title, sizeof(newDiary.title), stdin);
    newDiary.title[strcspn(newDiary.title, "\n")] = '\0'; // 개행 문자 제거

    printf("Enter the content: ");
    fgets(newDiary.content, sizeof(newDiary.content), stdin);
    newDiary.content[strcspn(newDiary.content, "\n")] = '\0'; // 개행 문자 제거

    printf("Enter the weather: ");
    fgets(newDiary.weather, sizeof(newDiary.weather), stdin);
    newDiary.weather[strcspn(newDiary.weather, "\n")] = '\0'; // 개행 문자 제거

    diaryList[*numDiaries] = newDiary;
    (*numDiaries)++;

    printf("Secret diary added successfully.\n");
}

#include <time.h> // time 함수를 사용하기 위해 필요한 헤더 파일

// 주제로 사용할 수 있는 키워드 목록 배열
const char* keywords[] = {
    "Travel",
    "Food",
    "Nature",
    "Friendship",
    "Love",
    "Adventure",
    "Memories",
    "Reflection",
    // 추가적인 키워드를 필요에 따라 여기에 추가할 수 있습니다.
};

int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

const char* randomTopic() {
    srand(time(NULL)); // 시간을 기반으로 난수 생성기 초기화

    int randomIndex = rand() % numKeywords; // 0부터 numKeywords-1 사이의 난수 생성
    // printf("Random topic: %s\n", topic); 메인에 추가하거나 함수에서 바로 키워트 

    return keywords[randomIndex];
}

//날씨 선택 함수
//함수 호출하는 방법 
//const char* weather = selectWeather();
// printf("Selected weather: %s\n", weather);
const char* selectWeather() {
    char weather[10];
    printf("Select the weather (Sunny, Windy, Rainy, Snowy, Cloudy): ");
    fgets(weather, sizeof(weather), stdin);
    weather[strcspn(weather, "\n")] = '\0'; // 개행 문자 제거

    return weather;
}

//일기의 번호를 입력받아 해당 일기 삭제하는 기능
//diaryList: 일기 구조체(Diary) 배열의 포인터입니다.
//numDiaries: 현재까지 저장된 일기의 개수를 나타내는 변수의 포인터입니다.
void deleteDiary(Diary *diaryList, int *numDiaries) {
    if (*numDiaries == 0) {
        printf("No diaries available.\n");
        return;
    }

    //다이어리 번호 입력 기입
    int diaryIndex;
    printf("Enter the diary number to delete (1 - %d): ", *numDiaries);
    scanf("%d", &diaryIndex);

    //입력한 번호가 유효하지 않을 경우에는 적절한 오류 메시지를 출력
    if (diaryIndex < 1 || diaryIndex > *numDiaries) {
        printf("Invalid diary number.\n");
        return;
    }

    // 선택한 일기를 삭제하고 배열을 재정렬
    for (int i = diaryIndex - 1; i < *numDiaries - 1; i++) {
        diaryList[i] = diaryList[i + 1];
    }

    (*numDiaries)--; //일기 삭제 후 자동으로 감소
    printf("Diary deleted successfully.\n");
}

// 지금까지 작성한 일기 목록을 보여준다
// 각 일기의 번호와 제목을 출력하여 목록을 표시
void listDiary(const Diary *diaryList, int numDiaries) {
    printf("일기 목록:\n");
    for (int i = 0; i < numDiaries; i++) {
        printf("일기 %d: %s\n", i+1, diaryList[i].title);
    }
}

// 보고 싶은 일기의 번호를 입력받고, 해당 일기의 내용을 출력
void viewDiary(const Diary *diaryList, int numDiaries) {
    if (numDiaries == 0) {
        printf("일기가 없습니다.\n");
        return;
    }

    int diaryIndex;
    printf("보고 싶은 일기의 번호를 입력하세요 (1 - %d): ", numDiaries);
    scanf("%d", &diaryIndex);

    // 입력한 번호에 해당하는 일기 내용 출력
}
