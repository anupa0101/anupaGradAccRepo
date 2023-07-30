#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
int main(){
    char choc;
    do
    {
        int arry[10]={0};
        int val;
        cout<<"enter marks"<<endl;
        for(int i=0; i<10;i++)
        {

        
            do{
                cin>>val;
                if((val>100)||(val<0)){
                    cout<<"invalid renter"<<endl;
                }
            }while ((val>100)||(val<0));
            
            
            arry[i]=val;;
            cout<<endl;
        }

        int arrayLength =sizeof(arry)/sizeof(arry[0]);//sizeof return the size of a data type in bytes, so divide by size of a single element. 
        //use different method to get size of dynamic arrays

        for(int i=0;i<arrayLength;i++)
        {
            cout<<arry[i]<<endl;
        }
        int max=arry[0];
        for(int i=0;i<arrayLength;i++)
        {
        if(arry[i]>max)
        {
            max=arry[i];
        }
        }
        cout<<"max "<<max;

        int min=arry[0];
        for(int i=0;i<arrayLength;i++)
        {
        if(arry[i]<min)
        {
            min=arry[i];
        }
        }
        cout<<"\nmin "<<min;

        float avg=0;
        float tot=0;
        for(int i=0;i<arrayLength;i++)
        {
        tot+=arry[i];
        }
        avg=static_cast<float>(tot)/arrayLength;
        cout<<"\navg "<<avg;
        
        do{
            cout<<"\nRepeat Y/N?"<<endl;
            cin>>choc;
            if((choc!='Y')&&(choc!='N')){
                cout<<"invalid ip"<<endl;
            }
        }while((choc!='Y')&&(choc!='N'));



    }while(choc=='Y');
    getch();
    return 0;
}