// 선형 리스트의 응용 및 구현
// 순차 리스트를 이용해 다항식 덧셈하기


#pragma once
#define MAX(a, b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct {
	int degree;				// 차수 저장
	float coef[MAX_DEGREE];	// 계수 저장
}polynominal;

polynominal addPoly(polynominal A, polynominal B);
void printPoly(polynominal P);

