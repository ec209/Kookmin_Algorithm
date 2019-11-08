//
//  PhilaWalk.cpp
//  
//
//  Created by TAEGIKIM on 16/11/2017.
//
//

#include <stdio.h>
#include <iostream>
#include <cmath>


using namespace std;


int philwalk(int int);

int x,y;

int main()
{
    int a,b,ans;
    cin >> a >> b; //a is size, b is steps
    ans = philawalk(a,b-1);
    //printf("%d",ans/10)
}

int philawalk(int a,int b)
{
    int size = a
    int steps = b;
    int pos;
    
    while(size--)
    {
        pos = steps%4;
        steps = stpes/4;
        switch(pos)
        {
            case 0: // 3사분면
                
                return philawalk(size,steps)
            case 1: // 2사분면
                
            case 2: //1사분면
                
            case 3: // 4사분면
        }
    }
    
    
}
