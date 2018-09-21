#include <stdio.h>

int main(void)
{
	/* 선언부 */
	int max=0,i;
	char N[8];
	int num[10] = { 0 };
	/* 입력부 */
	scanf("%s", N);
	/* 프로세싱부 */
	i = 0;
	/* 숫자 개수 카운트 */
	while (N[i] != '\0')
		num[N[i++] - '0']++; 
	num[6] = (num[6] + num[9]) / 2 + (num[6] + num[9]) % 2; // 9의 카운트를 모두 6으로 전환, 이 때 반으로 나누고 나머지를 더한다
	/* 최댓값 추출 */
	for (i = 0; i < 9; i++)
		if (max < num[i]) max = num[i];
	/* 출력부 */
	printf("%d\n", max);
}