//
//  PhilaWalk_ver2.cpp
//  
//
//  Created by TAEGIKIM on 19/11/2017.
//
//

#include <stdio.h>
#include <vector>
using namespace std;

int N, M,Testnum;

void get(int n, int m, int sx, int sy, int order[])
{
    int orderr[4];
    int h = n/2, k = h*h; // h is height
    if (m < 1 || m > n*n) return; // base case
    if (n == 1){ printf("%d %d\n", sx, sy); return; }
    orderr[0]=order[0];orderr[1]=order[3];orderr[2]=order[2];orderr[3]=order[1];
    get(h, m,     sx+(order[0]&1)*h, sy+(order[0]&2)/2*h, orderr);
    //recursive case 0
    //order[0]=0; order[1]=2; order[2]=3; order[3]=1;
    //order = {0,2,3,1};
    get(h, m-k,   sx+(order[1]&1)*h, sy+(order[1]&2)/2*h, order);
    
    //order[0]=0; order[1]=2; order[2]=3; order[3]=1;
    get(h, m-k*2, sx+(order[2]&1)*h, sy+(order[2]&2)/2*h, order);
    //recursive case 1 2
    orderr[0]=order[2]; orderr[1]=order[1]; orderr[2]=order[0]; orderr[3]=order[3];
    //order = {2,1,0,3};
    get(h, m-k*3, sx+(order[3]&1)*h, sy+(order[3]&2)/2*h, orderr);
    //recursive case 3
}

int main()
{
    scanf("%d", &Testnum);
    while(Testnum--)
    {
        int order[] = {0,2,3,1};
        
        scanf("%d%d", &N, &M);
        get(N, M,1,1,order);
    }
    
}


