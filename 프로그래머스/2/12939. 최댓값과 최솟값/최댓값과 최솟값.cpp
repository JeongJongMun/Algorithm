#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

string solution(string s) {
    
    stringstream ss(s);
    
    vector<int> v((istream_iterator<int>(ss)),
                  istream_iterator<int>());
    
    int int_min = *min_element(v.begin(), v.end());
    int int_max = *max_element(v.begin(), v.end());
    
    string answer = "";
    answer += to_string(int_min);
    answer += " ";
    answer += to_string(int_max);
    
    return answer;
}