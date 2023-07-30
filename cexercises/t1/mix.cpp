#include<iostream>
#include<conio.h>

using namespace std;
int main()
{
    int c;
    float val;

    cout<<" choose \n 1. to kg \n 2. to lbs\n";
    do{
        cin>>c;
        if((c!=1)&&(c!=2))
        {
            cout<<"Invalid"<<endl;
        }

    }while((c!=1)&&(c!=2));
    do{
        cin>>val;
        if((val<0))
        {
            cout<<"Invalid"<<endl;
        }

    }while((val<0));

    if(c==1)
    {
        cout<<val/22<<endl;
    }
    else{
        cout<<val*10<<endl;
    }

    _getch;
    return 0;
}