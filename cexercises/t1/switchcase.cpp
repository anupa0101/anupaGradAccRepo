#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int c;
    cout<<"Input\n 1. E \n 2. S \n 3. T"<<endl;

    do
    {
        cin>>c;
        cout<<c<<endl;
        if((c!=1)&&(c!=2)&&(c!=3))
        {
            cout<<"invalidd\n";

        }
    }
    while((c!=1)&&(c!=2)&&(c!=3));
    switch (c){
        case 1:
            cout<<"Choose E\n";
            break;
        case 2:
            cout<<"Choose S\n";
            break;          
        default : //will be exxecuted if nothing matches
                cout<<"Choose T\n";
                break;   
        }
    _getch;
    return 0;
}