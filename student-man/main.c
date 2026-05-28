#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. 구조체 정의: 학생 데이터를 하나로 묶음
typedef struct {
    char name[50];
    int score;
} Student;

int main() {
    Student students[100]; // 최대 100명의 학생 저장 가능
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== 📊 1학년 성적 관리 시스템 ===\n");
        printf("1. 학생 추가\n2. 전체 조회 및 평균\n3. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("이름 입력: ");
            scanf("%s", students[count].name);
            printf("점수 입력: ");
            scanf("%d", &students[count].score);
            count++;
            printf("✅ 추가 완료!\n");
        } 
        else if (choice == 2) {
            if (count == 0) {
                printf("📭 등록된 학생이 없습니다.\n");
                continue;
            }
            int sum = 0;
            printf("\n--- 성적 목록 ---\n");
            for (int i = 0; i < count; i++) {
                printf("%d. %s : %d점\n", i + 1, students[i].name, students[i].score);
                sum += students[i].score;
            }
            printf("-----------------\n");
            printf("평균 점수: %.2f점\n", (double)sum / count);
        } 
        else if (choice == 3) {
            printf("프로그램을 종료합니다.\n");
            break;
        } 
        else {
            printf("❌ 잘못된 입력입니다.\n");
        }
    }
    return 0;
}