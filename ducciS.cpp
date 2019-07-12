//
//  ducciS.cpp
//  
//
//  Created by TAEGIKIM on 29/09/2017.
//
//

/*
#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int Testnum, arrsize;
int *arr;

int main()
{
    int count = 0;
    cin >> Testnum;
    while(Testnum--)
    {
        cin >> arrsize;
        arr = new int[arrsize];
        for(int i=0;i<arrsize;i++)
        {
            cin >> arr[i];
        }
        
        int num = 1000;
        while(num--)
        {
            for(int i=0; i<arrsize-1;i++)
            {
                arr[i] = abs(arr[i] - arr[i+1]);
            }
            arr[arrsize] = abs(arr[arrsize] - arr[0]);
            
            //int count;
            
        }
        for(int j=0; j<arrsize; j++)
        {
            
            if(arr[j] != 0)
                count++;
        }
        cout << count << endl;
        if(count!=0)
        {
            cout << "LOOP" << endl;
            //count =0;
            //break;
            
        }
        else
        {
            cout << "ZERO" << endl;
            
        }
        
        
    }
    
    return 0;
}
*/


 #include <iostream>
 
 #define MAX 20 // max numbers
 
 using namespace std;
 
 int n; // numbers
 int i,j,c; // horse
 int _case; // case numbers..
 int num[MAX]; // input data
 
 int main()
 {
     cin>>_case;
     for(c=0;c<_case;c++)
     {
         
         cin>>n;
         
         for(i=0;i<n;i++)
         {
             cin>>num[i];
         }
         
         num[n] = num[0]; // 실제배열보다 하나 크게 잡아 놓고 마지막값을  인덱스 0으로 채워 넣는다
         
         for(i=0;i<1000;i++) // loop does not exceed 1,000
         { // (a1, a2, ... , an) = (|a1-a2|, |a2-a3|, ... , |an - a1|)
             
             for(j=0;j<n;j++)             {
                 num[j] = num[j] - num[j+1];
                 if(num[j] < 0) num[j] = -num[j];
             }
             num[n] = num[0]; // |an - a1|
         }
         
         for(j=0;j<n;j++)
         {
             num[n+1] += num[j];
         }
         if(num[n+1] == 0) // 마지막에 숫자들을 모두 더한값이 0 이면 zero
         {
             cout<<"ZERO"<<endl;
         }
         else // 아니면 loop
         {
             cout<<"LOOP"<<endl;
         }  
     }
 }
 
  
 
