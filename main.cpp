#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void distboard(int value)
{
    int valleft=value;
    string vals[9];
    for(int n=8;n>=0;n--)
    {
        bool found = false;
        for(int nn=2;nn>0;nn--)
        {
            if(valleft >=nn*pow(3,n))
            {
                if(nn==1)
                {
                    vals[n]="X";
                }
                if(nn==2)
                {
                    vals[n]="O";
                }
                found=true;
                valleft = valleft - nn*pow(3,n);
            }
        }
        if(found==false)
        {
            vals[n]=" ";
        }
    }
    cout << "[" << vals[0] << " " << vals[1] << " " << vals[2] << "]" << endl;
    cout << "[" << vals[3] << " " << vals[4] << " " << vals[5] << "]" << endl;
    cout << "[" << vals[6] << " " << vals[7] << " " << vals[8] << "]" << endl;
    return;
}

int main()
{
    distboard(11955);
    return 0;
}
