using namespace std;

// 최대 공약수
long long gcd(int a, int b) {
	if (a > b) return gcd(a%b, b);
	if (a == 0) return b;
	return gcd(b%a, a);
}

long long solution(int w, int h)
{
	// 1. 일정한 패턴이 반복되는데 이 패턴의 개수는 w, h의 최대 공약수임
	// 2. 가로 w, 세로 h(w, h는 서로소)를 대각선으로 나누었을 때
	//    멀쩡하지 않은 사각형의 개수는 w+h-1
	// 3. 이 패턴이 w, h의 최대 공약수 만큼 있으므로
	//    w, h의 최대공약수를 gcd라고 하면 멀쩡하지 않은 사각 형의 개수는
	//    w/gcd+h/gcd-1
	// 4. 3에 gcd를 곱하면 w+h-gcd (공식처럼 외우자)
	long long answer = (long long)w*(long long)h;
	// 멀쩡한 사각형 = (전체 사각형 개수) - (멀쩡하지 않은 사각형 개수)
	//                      (w * h)                 (w + h - gcd)
	answer -= w + h - gcd(w, h);
	return answer;
}
