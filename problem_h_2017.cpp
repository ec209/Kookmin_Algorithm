//
//  problem_h_2017.cpp
//  
//
//  Created by TAEGIKIM on 23/09/2017.
//
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdlib.h>

using namespace std;

int N;
int maxx[6];
int maxX;
//vector<int> arr;

int main()
{
    
    int *arr;
    cin >> N;
    arr = new int[N];
    for(int i=0; i<N;i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+N);
    maxx[0] = arr[N-2] * arr[N-1];
    maxx[1] = arr[0] * arr [1];
    maxx[2] = maxx[0] * arr[N-3];
    maxx[3] = maxx[0] * arr[0];
    maxx[4] = maxx[1] * arr[2];
    maxx[5] = maxx[1] * arr[N-1];
    
    
    maxX = maxx[0];
    for(int k=0;k<6;k++)
    {
        if(maxX < maxx[k])
            maxX = maxx[k];
    }
    cout << maxX << endl;
    //maxx3 = arr[N-3] * arr[N-2] * arr[N-1];
    //maxx4 = arr[0] * arr[1] * arr[2];
    //cout << maxx(maxx(maxx1,maxx2),maxx(maxx3,maxx4)) << endl;
    
    /*
    if(maxx[0] > maxx[1])
    {
        maxx[2]= maxx[0] * arr[N-3];
        maxx[3]= maxx[0] * arr[0];
    }
    else
    {
        maxx[2] = maxx[1] * arr[2];
        maxx[3] = maxx[1] * arr[N-1];
    }
*/
    
}
