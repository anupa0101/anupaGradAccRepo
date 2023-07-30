#include "vector.h"
#include<iostream>
#include<conio.h>

using namespace std;




int main(){


    vector3d v1,add,sub,v2(1,2,3);//from constructor
    float cord[3]={0};
    cout<<"Enter v1:"<<endl;
    for(int i=0; i<3;i++){
        cin>>cord[i];
        
    }
    v1.setVect(cord[0],cord[1],cord[2]);

    add=add.addV(v1,v2);
    sub.subV(v1,v2);
    add.printVector();
    sub.printVector();

    




    getch();
    return 0;
}
