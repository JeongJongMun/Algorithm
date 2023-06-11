#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;

    cout << (N % 7 == 0 || N % 7 == 2 ? "CY" : "SK");

    return 0;
}