#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, m;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        vector<int> v(n);

        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }

        int find = v[m];
        int answer = 1;



        while (1) {
            int maxNum = 0;

            // 최대 찾기
            for (auto i : v) maxNum = max(maxNum, i);

            // 맨 앞 원소가 최대가 아니라면 뒤로 보내기
            if (maxNum > *v.begin()) {
                v.push_back(*v.begin());
                v.erase(v.begin());
                if (!m) m = v.size() - 1;
                else m--;
            }
            // 맨 앞 원소가 최대라면 인쇄
            else {
                // 맨 앞 원소가 내가 찾는 원소라면 정답 출력
                if (!m) {
                    cout << answer << endl;
                    break;
                }
                answer++;
                //cout << *v.begin() << " M:" << m << endl;
                v.erase(v.begin());
                m--;
            }


        }

    }
    return 0;
}