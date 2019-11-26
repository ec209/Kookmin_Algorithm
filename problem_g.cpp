//
//  problem_g.cpp
//  
//
//  Created by TAEGIKIM on 16/09/2017.
//
//
//x좌표로 먼저 정렬을하고, 근접하는 y좌표값을 비교??

/*
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int TestNumCases;
    cin >> TestNumCases;
    while(TestNumCases--)
    {
        int T;
        cin >> T;
        while(T--)
        {
            int n;
            cin >> n;
            int arr[n][2];
            for(int i=0; i<n;i++)
            {
                
                cin >> arr[i][0] >> arr[i][1]; // x,y축 각각
            }
        }
        
    }
}*/


#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int n,m;
vector<pair<int,int> > ret;
vector<int> adj[100001];
int main(){
    int T; // 테스트할 횟수
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n); // 점의 갯수
        for(int i=0,u,v;i<n;++i){
            scanf("%d %d",&u,&v); // 각각 x y 좌표 입력 받음
            adj[u].push_back(v); // key(x좌표) 에 value (y좌표) 를 입력한다
        }
        ret.push_back(make_pair(-1,0)); // 포맷에 맞춰서 -1,0 좌표를 시작점으로 설정
        for(int i=0;i<100001;++i){
            if(adj[i].size()==0) continue;
            if(adj[i].size()==1) ret.push_back(make_pair(i,adj[i][0]));
            else{
                sort(adj[i].begin(),adj[i].end());
                if(ret[ret.size()-1].second==adj[i][0]) for(int j=0;j<adj[i].size();++j) ret.push_back(make_pair(i,adj[i][j]));
                else for(int j=adj[i].size()-1;j>=0;j--) ret.push_back(make_pair(i,adj[i][j]));
            }
        }
        scanf("%d",&m);
        for(int i=0,x;i<m;++i){
            scanf("%d",&x);
            printf("%d %d\n",ret[x].first,ret[x].second);
        }
        ret.clear();
        for(int i=0;i<100001;++i) adj[i].clear();
    }
}
