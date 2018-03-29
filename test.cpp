#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>


using namespace std;

int main()
{
    srand (time(NULL));
    int c=10;
    int x[c];
    int y[c];

    for (int i=0; i!=c; i++)
    {
        int a=rand()%2;
        if (a==0)
            {a=-1;}
        x[i]=((rand() % 32767)*(rand() % 32767))*a;

        int b =rand()%2;
        if (b==0)
            {b=-1;}
        y[i]=((rand() % 32767)*(rand() % 32767))*b;
        cout<<"City"<<i+1<<": "<<x[i]<<"; "<<y[i]<<endl;
    }
    return 0;
}
