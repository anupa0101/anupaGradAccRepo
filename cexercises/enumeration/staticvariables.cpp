#include<iostream>
#include<conio.h>
using namespace std;
void TestCall();
int main(){
TestCall();
TestCall();
TestCall();
TestCall();
TestCall();
TestCall();

return 0;

}

void TestCall()
{
    static int counter=0;
    counter++;
    if(counter==1){
        cout<<"1"<<endl;
    
    }
    else if(counter==2){
        cout<<"2"<<endl;
    
    }
    else{
        cout<<"3 or more"<<endl;
    
    }
}