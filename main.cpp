// 13. 罗马数字转整数
// https://leetcode-cn.com/problems/roman-to-integer/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

 class Solution {
 public:
     int romanToInt(string s) {
         unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};
         int r = m[s.substr(0, 1)];
         for(int i=1; i<s.size(); ++i){
             string two = s.substr(i-1, 2);
             string one = s.substr(i, 1);
             r += m[two] ? m[two] : m[one];
        }
         return r;
     }
 };


#define LOCAL
int main()
{
#ifndef LOCAL
    freopen("in.txt", "r", stdin);
// freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
     Solution mSolution;
     cout << mSolution.romanToInt("IX") << endl;
    return 0;
}
