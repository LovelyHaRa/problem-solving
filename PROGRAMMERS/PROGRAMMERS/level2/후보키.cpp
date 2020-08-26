#include <string>
#include <vector>
#include <set>
#include<iostream>

using namespace std;

int solution(vector<vector<string>> relation) {
	set<int> bitset; // 후보키 집합
	int colSize = relation[0].size(); // 열 사이즈
	int rowSize = relation.size(); // 행 사이즈
	// 모든 부분집합 생성(1 ~ 2^colSize-1)
	for (int i = 1; i < (1 << colSize); i++) {
		set<string> rowset; // 행 데이터 집합
		// 행 탐색
		for (int j = 0; j < rowSize; j++) {
			string rowData; // 행 데이터
			// 열 사이즈만큼 탐색
			for (int k = 0; k < colSize; k++) {
				// 현재 부분집합중에 1의 값이 들어있으면 데이터 삽입
				if (i&(1 << k)) {
					rowData += relation[j][k] + ',';// 데이터 삽입(,로 구분)
				}
			}
			// 만들어진 행 데이터를 집합에 추가
			rowset.insert(rowData);
		}
		// 행 데이터집합의 수가 열 집합의 수랑 일치하면 유일성 만족
		if (rowSize == rowset.size()) {
			// 후보키 집합 탐색
			set<int>::iterator iter;
			for (iter = bitset.begin(); iter != bitset.end(); iter++) {
				int t = *iter; // 후보키 집합의 원소
				if ((t&i) == t) break; // 후보키 원소가 i의 부분집합이면 최소성을 만족하지 못함
			}
			// 이미 포함된 후보키를 찾지 못하면 후보키 집합에 추가
			if (iter == bitset.end()) bitset.insert(i);
		}
	}
	// 후보키 집합의 사이즈 리턴
	return bitset.size();
}