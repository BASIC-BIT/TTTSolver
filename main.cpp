#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void distboard(int value)
{
    int valleft=value;
    string vals[9];
    for(int n=8;n>=0;n--) //The space on the board
    {
        bool found = false;
        if(valleft>0) //Some optomizatio nif it has already found all of the values
        {
            for(int nn=2;nn>0;nn--) //Checking multipliers for base 3
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
        }
        if(found==false)
        {
            vals[n]=" "; //Adding in space if nothing is found
        }
    }
    cout << "[" << vals[0] << " " << vals[1] << " " << vals[2] << "]" << endl;
    cout << "[" << vals[3] << " " << vals[4] << " " << vals[5] << "]" << endl;
    cout << "[" << vals[6] << " " << vals[7] << " " << vals[8] << "]" << endl;
    return;
}
void explode(string& str, int index,double probs[][9])
{
    string delimiter = ",";
    int strleng = str.length();
    int delleng = delimiter.length();
    int i=0;
    int k=0;
    int numfound=0;
    while( i<strleng )
    {
        int j=0;
        while (i+j<strleng && j<delleng && str[i+j]==delimiter[j])
            j++;
        if (j==delleng)//found delimiter
        {
            stringstream ss;
            ss << str.substr(k, i-k);
            double output;
            ss >> output;
            probs[index][numfound]=output;
            numfound++;
            i+=delleng;
            k=i;
        }
        else
        {
            i++;
        }
    }
    stringstream ss2;
    ss2 << str.substr(k, i-k);
    double output2;
    ss2 >> output2;
    probs[index][numfound]=output2;
    return;
}
void savefile(double probs[][9], int width, int height)
{
    ofstream save;
    save.open("probs.txt");
    for(int n=0;n<width;n++)
    {
        for(int nn=0;nn<height;nn++)
        {
            stringstream ss;
            ss << probs[n][nn];
            double out;
            ss >> out;
            save << out;
            if(nn != height-1)
            {
                save << ",";
            }
        }
        if(n != width-1)
        {
            save << endl;
        }
    }
    save.close();
    return;
}
int main()
{
    const int WIDTH = pow(3,9);
    const int HEIGHT = 9;
    double probs[WIDTH][HEIGHT];
    for(int n=0;n<WIDTH;n++)
    {
        for(int nn=0;nn<HEIGHT;nn++)
        {
            probs[n][nn]=1.0;
        }
    }
    ifstream probfile("probs.txt");

    string line;
    if(probfile.is_open())
    {
        int n = 0;
        while(probfile.good())
        {
            cout << "PROCESSING LINE " << n << endl;
            getline(probfile,line);
            explode(line,n,probs);
            n++;
        }
        cout << "FILE VALUES: " << probs[0][0] << ", " << probs[0][1] << ", " << probs[1][0] << endl;
    }else
    {
        savefile(probs, WIDTH, HEIGHT);
    }
    distboard(11955);

    return 0;
}
