#include <bits/stdc++.h>
using namespace std;

struct park {
	int cost;
	bool isPark;
};

struct car {
	int weight;
	int pnum;
};

int N, M, answer;
vector<park> parks(101, { 0, false });
vector<car> cars(2001, { 0, 0 });
queue<int> waitlist;


// 빈자리 찾거나 없으면 -1 반환
int CheckEmptyPark() {
	for (int i = 1; i <= N; i++) {
		if (!parks[i].isPark) return i;
	}
	return -1;
}

// 차량 진입
void CarIn(int cnum, int pnum) {
	// 주차장 자리 있음
	if (pnum > 0) {
		parks[pnum].isPark = true;
		cars[cnum].pnum = pnum;
	}
	// 주차장 자리 없음
	else {
		waitlist.push(cnum);
	}
}

// 차량 나감
void CarOut(int cnum, int pnum) {
	parks[pnum].isPark = false;
	answer += parks[pnum].cost * cars[cnum].weight;

	if (!waitlist.empty()) {
		CarIn(waitlist.front(), CheckEmptyPark());
		waitlist.pop();
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;


	for (int i = 1; i <= N; i++) {
		cin >> parks[i].cost;
	}

	for (int i = 1; i <= M; i++) {
		cin >> cars[i].weight;
	}

	for (int i = 0; i < 2 * M; i++) {
		int cnum; cin >> cnum;

		if (cnum > 0) CarIn(cnum, CheckEmptyPark());
		else CarOut(-cnum, cars[-cnum].pnum);
	}

	cout << answer;

	return 0;
}