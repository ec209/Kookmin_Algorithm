#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    std::ifstream in;
    in.open("input_hotel.txt"); //file input
    
    if(in.fail())//error checks
    {
        std::cerr << "Input file opening failed.\n";
        exit(1);
    }
    int T;
    in >> T;
    while(T--)
    {
        int H,W,N;
        in >> H >> W >> N;
        N--; // 이건 왜 이렇게?? 
        cout << (((N)%H+1)*100) + (N/H+1) << endl;
    }
}
