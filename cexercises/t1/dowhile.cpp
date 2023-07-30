#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    double pow, eff;
  
  do{
        cout<<"Ip power"<<endl;
        cin>>pow;
        if((pow<0))
        {
            cout<<"Invalid"<<endl;
        }


    }
    while((pow<0));
    do{
        cout<<"Ip eff"<<endl;
        cin>>eff;
        if((eff<10)||(eff>100))
        {
            cout<<"Invalid"<<endl;
        }


    }
    while((eff<10)||(eff>100));
    cout<<pow/eff;
    _getch;
    return 0;
}