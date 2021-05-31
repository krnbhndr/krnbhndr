#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
// compexity O(n2)
int numOfPathsToDest( int n )
{ vector<vector<int>> vec(n,vector<int>(n,0)); //for dp
for(int i=0;i<n;i++)
vec[0][i]=1;
for(int i=1;i<n;i++){
for(int j=i;j<n;j++){
vec[i][j] = vec[i][j-1] + vec[i-1][j];
}
}
return vec[n-1][n-1];
}
//driver code
int main(){
cout<<numOfPathsToDest(4)<<endl;
return 0;
}