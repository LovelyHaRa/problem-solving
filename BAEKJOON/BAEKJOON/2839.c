/* 백준 2839 설탕배달 */

#include<stdio.h>

int main(void)
{
	int weight; // 무게
	int n; // 넣을 수 있는 5kg 봉지갯수
	int tmp; // 무게- (5kg 갯수 총합)
	int count = -1; // 봉지 총 개수
	scanf("%d", &weight); // 입력받음
	n = weight / 5; // 5kg 봉지 최대 갯수
	while (n >= 0) // 5kg 봉지에 담을 수 없을 때 까지
	{
		tmp = weight - (n * 5); // 무게 - (5kg 갯수 총합)
		if (tmp % 3 == 0) // 그 값이 3으로 나누어 떨어지면
		{
			count = n + tmp / 3; // 현재 5kg 봉지갯수 + 3kg 봉지 갯수
			break; // 결과 나왔으므로 루프 빠져나옴
		}
		n--; //안나누어지면 5kg 봉지 하나 뺌
	}
	//루프 끝날 때 까지 if문 false이면 봉투에 정확히 담을 수 없음.
	printf("%d", count); // 개수 출력
}