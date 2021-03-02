#include<iostream>
#include<cstring>

using namespace std;
void printDecimal(int a, int b); // 분수를 소수로 변환하는 함수

int main(void)
{
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int T; // 테스트케이스
	int a, b; // 분자, 분모
	cin.sync_with_stdio(false);
	cin >> T;
	while (T > 0)
	{
		cin >> a >> b; // 입력 받음
		printDecimal(a, b); // 함수 호출
		T--;
	}

}

void printDecimal(int a, int b)
{
	int p[10240 + 1]; // key : 나머지값, value : 소수점 위치
	int nature = a / b; // 소수점 윗부분	
	int k = 0; // 소수점 이하 위치
	int start = 0, end = 0; // 순환 시작, 끝 지점
	int res = (a%b) * 10; // 결과 초기값
	memset(p, -1, sizeof(p)); // 배열 -1로 초기화
	while (1)
	{
		a = (a%b) * 10; // 자릿수 계산
		// 순환지점 파악
		if (p[a] != -1)
		{
			start = p[a]; //시작지점 저장
			end = k; // 끝지점 저장
			break; // 반복문 종료
		}
		p[a] = k++; //
	}
	cout << nature << '.'; // 소수점 윗부분 출력
	// 순환되기 전 소수부분 출력
	for (int i = 0; i < start; i++)
	{
		cout << res / b;
		res = (res%b) * 10;
	}
	// 순환부분 출력
	cout << '(';
	for (int i = start; i < end; i++)
	{
		cout << res / b;
		res = (res%b) * 10;
	}
	cout << ')' << endl;
}
