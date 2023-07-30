#include<iostream>
#include<conio.h>
#include<cstdlib>
#include <ctime> // for time

using namespace std;

int main(){
    srand(time(nullptr));
    int cards[52]={0};
    

    for (int j=0;j<52;j++){

        while(true){
        int x=((rand()+1)%52)+1; //will get 52 results 0 to 51... 52 will come if 0 is the rand but avoided by adding +1 inside.... 
        //finally add +1 so 1 to 52
        bool flag=false;
        for (int i=0;i<=j;i++){
            if(cards[i]==x){
                flag=true; //break for loop if found similar
                break;
            }
            
        }
        if(flag==false)//break the while loop if no similar
        {
            cards[j]=x;
            break;
        }
        
        }

        
    }

    for (int j=0;j<52;j++){
        cout<<cards[j]<<" ";
    }

    getch();
    return 0;
}
