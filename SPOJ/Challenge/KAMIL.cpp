#include <bits/stdc++.h>
using namespace std;
int main()
{string s;for (int i=1;i<=10;i++){cin >> s;int cnt = 1;for (int k = 0; k < s.size(); k++)if (s[k] == 'T' or s[k] == 'D' or s[k] == 'L' or s[k] == 'F')cnt *= 2;cout << cnt << endl;}
}