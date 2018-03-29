#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>


using namespace std;

int main()
{
    ofstream test10k;
    test10k.open("tester10k.benobogyo");
    srand (time(NULL));
    int c=100000;
    int x;
    int y;
    cout << c << " " << (int)(c / 3)<< endl;
    for (int i=0; i!=c; i++)
    {
        int a=rand()%2;
        if (a==0)
            {a=-1;}
        x=((rand() % 9999)*(rand() % 9999))*a;

        int b =rand()%2;
        if (b==0)
            {b=-1;}
        y=((rand() % 9999)*(rand() % 9999))*b;
        test10k<<"City"<<i+1<<" "<<x<<" "<<y<<endl;
    }

    test10k.close();
    return 0;
}
