#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    cout << (N % 2 ? "SK" : "CY");

    return 0;
}


/*
1 S
2 C
3 S
4 C
5 S
6 C
7 S
남은 돌 수가 짝수라면 선공이 이김
*/