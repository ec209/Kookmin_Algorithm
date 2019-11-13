//
//  problem_a2015.cpp
//
//
//  Created by TAEGIKIM on 17/09/2017.
//
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

#define pb push_back
#define all(v) (v).begin(), (v).end()

int T, N, M;
int par[1003], ecnt[1003], sz[1003];
int w[1003][1003];

struct Z{
    int a, b, c;
} E[1000006];

bool cmp(const Z &a, const Z &b)
{
    return a.c < b.c;
};

int cp(int n){ return par[n] == n ? n : (par[n] = cp(par[n])); }

int main()
{
    scanf("%d", &T);//cin >> T;
    while(T--) //
    {
        scanf("%d", &N);//in >> N;//
        M = 0;
        for (int i=1;i<N;i++)
        {
            for (int j=i+1;j<=N;j++)
            {
                //int w;
                scanf("%d", w[i]+j);//in >> w[i]+j;//[i][j];//
                //E[++M] = {i, j, w[i][j]}; // c++ 11 이하에서는 지원 안함, 위의 structure Z와 연관이 있는것 같은데....
                E[++M].a = i;
                E[++M].b = j;
                E[++M].c = w[i][j];//[i][j];
            }
        };
        sort(E+1, E+M+1, cmp); // c++ 11이하에서는 지원 안함
        
        vector <int> cand;
        for (int i=1;i<=N;i++) par[i] = i, ecnt[i] = 0, sz[i] = 1;
        int ans = 0;
        for (int i=1;i<=M;i++)
        {
            int a = cp(E[i].a), b = cp(E[i].b);
            ecnt[a]++;
            if (a != b)
            {
                par[b] = a;
                ecnt[a] += ecnt[b]; sz[a] += sz[b];
                ecnt[b] = sz[b] = 0;
            }
            cand.pb(a);
            if (i < M && E[i].c == E[i+1].c) continue;
            sort(all(cand));
            int last = -1;
            for (vector<int>::iterator t=cand.begin(); t!=cand.end(); ++t) //int t: cand
            {
                if (last == *t || par[*t] != *t) continue;
                last = *t;
                if (ecnt[*t] == sz[*t]*(sz[*t]-1)/2) ans++;
            }
            cand.clear();
        }
        printf("%d\n", --ans);
    };
}

