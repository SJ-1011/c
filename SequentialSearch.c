#define _CRT_SECURE_NO_WARNINGS
#define DATACOUNT 10000001    // 주어진 데이터의 개수
#include <stdio.h>
#include <time.h>             // 헤더 선언
int main(void) {
	clock_t start, stop = 0;                     // 코드 동작 시간 계산을 위해 선언
	double result = 0;                           // 코드 동작 시간 계산을 위해 선언
	int num;                                     // 접근할 데이터를 저장할 변수 선언
	printf("순차탐색을 위한 수 입력: ");           // 데이터 입력 문구 출력
	scanf_s("%d", &num);                         // 데이터를 num 변수에 저장
	
	FILE* fp = fopen("1.in", "r");         // 주어진 파일 읽어 옴
	start = clock();                       // 코드 동작 시간
	if (fp == NULL) {                      /* 파일을 읽어오지 못하면
		                                      파일 위치를 확인해달라는 문구를 출력 후 프로그램 종료*/
		printf("프로그램 종료, 파일의 위치를 확인해주세요. (c파일과 같은 위치로 1.in파일을 옮겨주세요.)"); return -1;
	}
	for (int i = 0; i < DATACOUNT; i++) {  // 모든 데이터에 접근할 수 있도록 반복문 선언
		int temp;                            // 줄 당 데이터들을 저장할 변수 선언
		fscanf_s(fp, "%d", &temp);           // str 타입의 데이터를 int로 temp 변수에 저장
		if (temp == num) {                   // 10000000, 2839004, 6896383 데이터에 접근 시 for문에서 빠져나옴
			break;
		}
	}
	stop = clock();	                                          // 코드 종료 시간
	result = (double)(stop - start) / CLOCKS_PER_SEC;         // 코드 수행에 소요된 시간 계산
	printf("걸린 시간은 %f초 입니다.", result);                 // 코드 수행에 소요된 시간 출력
	return 0;       // 프로그램 종료
}

