#include<iostream>
#include<conio.h>

using namespace std;

class bankacc
{
private:
    char *name[10]; //need * need  to work
    char *address[20];
    float bal;
    int accnum;
    bool isBalSuff(float);

    
public:
    int getacc();
    void openacc(char [], char[],int);
    bool withdraw(float);
    void deposit(float amount);
    void disp();


    
};




int main(){

   
    bankacc acz[3];

    int siz=sizeof(acz)/sizeof(acz[0]);

    for(int i=0; i<siz; i++){

        char namex[10];
        char addx[20];
        int accnumX;

        cout<<"ip name, address, acc num "<<i+1<<endl;
        
        cin.getline(namex,10);
       
        cin.getline(addx,20);
        
        cin>>accnumX;
        acz[i].openacc(namex,addx,accnumX);
        
        
    }
    acz[0].deposit(100);
    acz[0].disp();
    acz[0].withdraw(10);
    acz[0].disp();
    


    getch();
    return 0;
}
int bankacc::getacc(){
    return accnum;
}

bool bankacc::isBalSuff(float amount)
{
    return (amount<=bal)?true:false;
}

void bankacc::openacc(char nam[], char add[],int acc){
    *name=nam;
    *address=add;
    accnum=acc;
    bal=0;
}

bool bankacc::withdraw(float amount){
    if(isBalSuff(amount)) { // FUCNTION IS CALLED INSIDE A FUNCTION OF THE CLASS. THIS CANNOT BE CALLED INJ THE MAIN FUCNTION
        bal-=amount;
        return true;
    }
    else{
        return false;
    }
}


void bankacc::deposit(float amount){
    
        bal+=amount;
    
}


void bankacc::disp(){
    
        //cout<<name<<endl;
       
        cout<<name;
       
        cout<<"  ";
        cout<<bal<<endl;
    
}
