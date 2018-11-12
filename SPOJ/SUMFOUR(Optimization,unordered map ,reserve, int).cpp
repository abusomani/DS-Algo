//Sometimes I feel like giving up, then I remember I have a lot of motherfuckers to prove wrong!
//@BEGIN OF SOURCE CODE ( By Abhishek Somani)
/*
    Going by the comments this question has very tough time limits
    SORT()  is faster than QSORT()
    UNORDERED_MAP is faster than MAP
    RESERVE space for unordered_map
    AxBxCxD means, all numbers of their respective sets
*/
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define sc(x) scanf("%d", &x)
#define fastio ios_base::sync_with_stdio(false)
#define MAX_SIZE 4005

int main()
{
    int a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE], d[MAX_SIZE];
    unordered_map<int, int> UMP;
    UMP.reserve(MAX_SIZE * MAX_SIZE);
    int N, ans = 0, tempSum;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            UMP[c[i] + d[j]]++;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            tempSum = -(a[i] + b[j]);
            if (UMP.find(tempSum) != UMP.end())
                ans += UMP[tempSum];
        }

    cout << ans << endl;

    return 0;
}
// END OF SOURCE CODE