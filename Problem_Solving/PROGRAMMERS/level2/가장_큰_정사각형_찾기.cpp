#include <iostream>
#include<vector>
using namespace std;

int min(int a, int b, int c) {
	return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int solution(vector<vector<int>> board)
{
	int answer = board[0][0];
	// dp로 해결
	// 1. 점화식 => board[i][j]>0, i>0,j>0, board[i][j]=min(board[i-1][j-1],board[i-1][j],board[i][j-1])+1
	//              좌상단, 좌측, 상측 값중 최솟값에 1을 더해 저장
	//              board[i][j] = 만들 수 있는 정사각형의 한변의 길이
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			// 1. 점화식 적용
			if (i && j) {
				board[i][j] = board[i][j] > 0 ? min(board[i - 1][j - 1], board[i - 1][j], board[i][j - 1]) + 1 : 0;
			}
			// 2. 최댓값 갱신
			answer = answer < board[i][j] ? board[i][j] : answer;
		}
	}
	// 3. 넓이 리턴
	return answer * answer;
}