//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Two endpoints touch, so maximum area would be a semi circle
    So , Pi x r = X
    area is Pi x r x r => X^2 / Pi
*/
#include <bits/stdc++.h>
using namespace std;

#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

typedef long long ll;
typedef long double LD;
LD PI = acos(-1.0);

int main()
{
    fastio;
    //freopen('input.txt','r',stdin);
    //freopen('output.txt','w',stdout);
    ll N;
    while (cin >> N, N)
    {
        double sq = N * N;
        sq = sq/2.0;
        sq = (double)sq / PI;
        printf("%.2f\n", sq);
    }
    return 0;
}
// END OF SOURCE CODE