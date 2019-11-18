//
//  problem_b.cpp
//  
//
//  Created by TAEGIKIM on 16/09/2017.
//
//

#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

inline void alice(int, int[]);

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
            int numOfCards;
            cin >> numOfCards;
            int *arr = new int[numOfCards];
            alice(numOfCards, arr);
        }
    }
    return 0;
}

inline void alice(int num, int arr[])
{
    int start=0;
    int end=num;
    int i=0;
    int arr2[num];
    int maxnum;
    while(start != end)
    {
        if(arr[start]>arr[end]) // ascending
        {
            arr2[i++] = arr[start++];
        }
        else
        {
            arr2[i++] = arr[end--];
        }
    }
    for(int i=0; i<num;i+=2)
    {
        maxnum += arr2[i];
    }
    printf("%d",maxnum);
    
    
    
}
