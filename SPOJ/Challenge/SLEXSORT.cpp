#include <bits/stdc++.h>
using namespace std;
string key,x;
int main()
{
    int T,N;
    cin>>T;
    while(T--)
    {
        map<int,string> V;
        cin>>key;
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>x;

        }
        for(map<int,string>::iterator it=V.begin();it!=V.end();it++)cout<<(*(it)).second<<endl;
        cin.ignore();
    }
}
