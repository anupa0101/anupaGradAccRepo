#include<iostream>
#include<conio.h>

using namespace std;
void minmaxavg(const int [], int , int &, int & , float &);
int main(){

    int min,max;
    float avg;
    const int size=5;
    int ary[size];

    for(int i=0;i<size; i++){
       cin>>ary[i];
    }
    minmaxavg(ary, size, min , max, avg);
    cout<<min<<" "<<max<<" "<<avg<<" "<<endl;



    getch();
    return 0;
}

void minmaxavg(const int ary[], int size,  int &min , int &max, float &avg)
{
    min=ary[0];
    max=ary[0];
    for(int i=0;i<size; i++){
        if(ary[i]>max){
            max=ary[i];
        }
        if(ary[i]<min){
            min=ary[i];
        }
        avg+=static_cast<float>(ary[i])/size;
    }
}