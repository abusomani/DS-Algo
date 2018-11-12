#include<bits/stdc++.h> 
#define sc(x) scanf("%d",&x);
main(){int t,x;sc(t);while(t--){sc(x); double val=x; val=((val*(val+1))/(2*(val*val+val+1)));printf("%0.5f\n",val);}}