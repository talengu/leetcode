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

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; scanf("%d",&x);
		i==(n-1)?cout<<n+1-x<<endl:cout<<n+1-x<<" ";
    }


}
