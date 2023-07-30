#include<iostream>
#include<conio.h>

using namespace std;
int main()
{
    int a,b,c,max;
    cin>>a>>b>>c;
    if(a>c)
    {
        if(a>b)
        {
            max=a;
        }
        else{
            max=b;
        }
    }
    else{
        if(c>b)
        {
            max=c;
        }
        else{
            max=b;
        }
    }
    cout<<max;
    _getch;
    return 0;
}