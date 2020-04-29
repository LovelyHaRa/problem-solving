#include<cstdio>

using namespace std;

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int btn[10] = { 0, }; // 고장난 버튼 여부
	// 1. 단순 +, - 로 목표 채널까지 이동값 구하기
	int min = n - 100;
	if (min < 0) min *= -1; // 절대값 처리
	// 2. 고장난 버튼 1로 처리
	for (int i = 0; i < m; i++)
	{
		int x;
		scanf("%d", &x);
		btn[x] = 1;
	}
	// 3. 1~ 10e6-1 까지 완전 탐색(6자리 최댓값: 999999)
	for (int i = 0; i < 1000000; i++)
	{
		int cnt = 0; // 버튼 누른 횟수
		int k = 0; // 숫자 버튼 누른 횟수(자릿수)
		int t = i; // 자릿수 체크를 하기 위해 i값 복사
		// 4. 버튼을 모두 누를 수 있는지 체크
		while (t)
		{
			k++;
			if (btn[t % 10]) break; // 버튼이 고장났으면 break
			t /= 10;
		}
		// 5. 버튼을 모두 눌렀을 경우 버튼 누른 값 계산
		if (!t)
		{
			// i=0 일 때 처리
			if (!i)
			{
				if (btn[0]) continue; // i==0이고 버튼이 고장 났으면 무시
				k = 1; // 그렇지 않으면 버튼을 누를 수 있으므로 k=1 대입
			}
			// 버튼 누른 횟수 = 숫자버튼 누른 값(k)+abs(목표값(n)-현재 값(i))
			if(n > i) cnt += k + n - i; 
			else cnt += k + i - n;
			// 6. 최솟값 갱신
			min = min > cnt ? cnt : min;
		}		
	}
	// 7. 최솟값 출력
	printf("%d", min);
}