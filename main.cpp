#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//#define LOCAL
int main()
{
#ifndef LOCAL
    freopen("in.txt", "r", stdin);
// freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    int a=1;
    int c=2*a;
    string aa;
    cin >> a;
    cin >> aa;
    cout << aa + " " << a << endl;
    return 0;
}