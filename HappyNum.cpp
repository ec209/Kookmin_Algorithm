//
//  HappyNum.cpp
//
//
//  Created by TAEGIKIM on 15/11/2017.
//
//

#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int happy(int,int);

int main()
{
    int TestNum;
    int a,b;
    
    cin >> TestNum;
    while(TestNum--)
    {
        cin >> a;
        b = happy(a,0);
        
        if(b == 1)
        {
            printf("HAPPY\n");
        }
        else
        {
            printf("UNHAPPY\n");
        }

    }
    
    return 0;
}

int happy(int num, int num2)
{
    int temp[10] ={0};
    int tempnum = num;
    int i=0;
    int count = num2;
    while(true)
    {
        
        temp[i] = tempnum%10;
        i++;
        tempnum = tempnum/10;
        if(tempnum == 0)
        {
            break;
        }
        
    }
    
    while(i--)
    {
        tempnum += pow(temp[i],2);
    }
    
    
    if(tempnum == 1)
    {
        return 1;
    }
    else if(count > 1000)
    {
        return 0;
    }
    else
    {
        count++;
        return happy(tempnum,count); //recursive
    }
    
    
}
