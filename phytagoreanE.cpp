//
//  phytagoreanE.cpp
//  
//
//  Created by TAEGIKIM on 29/09/2017.
//
//

#include <stdio.h>
#include <cmath>
//#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int A[1004], B[1004];

int main()
{
    for (scanf("%d", &T);T--;){
        scanf("%d%d", &N, &M);
        for (int i=1;i<=N;i++) A[i] = B[i] = 0;
        for (int i=1;i<=M;i++){
            int a, b, p, q;
            scanf("%d%d%d%d", &a, &b, &p, &q);
            A[a] += p; B[a] += q;
            A[b] += q; B[b] += p;
        }
        double mx = 0, mn = 2e9;
        for (int i=1;i<=N;i++){
            double v = A[i] + B[i] ? ((double)(A[i]*A[i]) / (A[i]*A[i] + B[i]*B[i])) : 0;
            mx = fmax(mx, v);
            mn = fmin(mn, v);
        }
        printf("%d\n%d\n", (int)(mx * 1000 + 1e-8), (int)(mn * 1000 + 1e-8));
    }
}


