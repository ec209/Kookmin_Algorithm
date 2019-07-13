//
//  eureka.cpp
//  
//
//  Created by TAEGIKIM on 21/09/2017.
//
//
//삼각수배열을 만들고 그값을 채운다
//for 문을 돌려서 조건에 맞는 것이 있는지 확인해 본다


#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int tri[101];
int T,K,temp;

int main()
{
    std::ifstream in;
    in.open("input_eureka.txt"); //file input
    
    if(in.fail())//error checks
    {
        std::cerr << "Input file opening failed.\n";
        exit(1);
    }
    for(int i=0; i<101; i++)
    {
        tri[i+1] = tri[i] + (i+1);
        //cout << tri[i];
    }
    in >> T;
here:
    while(T--)
    {
        in >> K;
        for(int i=1; i<101;i++)
        {
            for(int j=1; j<101; j++)
            {
                for(int k=1; k<101; k++)
                {
                    temp = tri[i] + tri[j] + tri[k];
                    if(temp == K)
                    {
                
                        cout << 1 << endl;
                        goto here;
                    }
                }
            }
        }
        cout << 0 << endl;
    }
    return 0;
}
