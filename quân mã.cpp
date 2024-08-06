#include <bits/stdc++.h>
using namespace std;
int dx[4]={-1,1,2,2};
int dy[4]={2,2,1,-1};
int m,n,k,q;
int p=0;
int socach(int x,int y,int m,int n,int a[101][101]){
    for(int i=0;i<4;i++){
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1>0 && x1<=m && y1>0 && y1<=n && a[x1][y1]==0){
            if(x1==m && y1==n) p++; 
            else socach(x1,y1,m,n,a); 
        }
}
    return p;
}
int main(){
    cin>>m>>n>>k>>q;
    int a[101][101];
    memset(a,0,sizeof(a));
    for(int i=0;i<k;i++){
        int x,y;cin>>x>>y;
        a[x][y]=1;
    }
    while(q--){
        int x,y;cin>>x>>y;
        if(a[x][y]==1) cout<<0<<endl;
        else{int k=p;
        int h=(socach(x,y,m,n,a)-k);
        int h1=pow(10,9);
        cout<<h%h1<<endl;
}
}
    return 0;
}