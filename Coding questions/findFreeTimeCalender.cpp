#include<iostream>
#include<conio.h>
#include<vector>
#include<string>

//PASS VECTORS BY REFFERENCE IF CHANGING INSIDE THE FUNCTION

// when the busy schedules of two people are given, find time for a meeting  of h time. upper and lower bounds for each person are given
//{{"09:00","10:30"},{"12:00","13:00"},{"16:00","10:00"}}
//{"09:00","20:00"}

//{{"10:00","11.30"},{"12:30","14:30"},{"14:30","15:00"},{"16:00","17:00"}}
//{"10:00","18:30"}

//combine the two and sort

//{{"09:00","10:30"},{"12:00","13:00"},{"16:00","10:00"}, {"10:00","11.30"},{"12:30","14:30"},{"14:30","15:00"},{"16:00","17:00"}}
std::vector<std::vector<std::string>> merge(std::vector<std::vector<std::string>> , std::vector<std::vector<std::string>> );
bool compareTime(std::string, std::string);
void sortVec(std::vector<std::vector<std::string>> &);
int DifferenceTime(std::string t1, std::string t2);
void startNEndTimeslot(std::vector<std::vector<std::string>> &freetime, std::vector<std::string> bounds);

std::vector<std::vector<std::string>> freeTimes(std::vector<std::vector<std::string>> sch);
bool ifoverlap(std::vector<std::string> ft1, std::vector<std::string> ft2);
int val(std::string t1);

std::string min(std::string t1, std::string t2);
int main(){

    std::vector<std::vector<std::string>> schedule1{{"09:00","10:30"},{"12:00","13:00"},{"16:00","10:00"}};
    std::vector<std::vector<std::string>> schedule2{{"10:00","11.30"},{"12:30","14:30"},{"14:30","15:00"},{"16:00","17:00"}};
    std::vector<std::vector<std::string>> freetime1=freeTimes(schedule1);//
    std::vector<std::vector<std::string>> freetime2=freeTimes(schedule2);//  

    startNEndTimeslot(freetime1,{"09:00","20:00"});//adjust the startingand ending timeslots
    startNEndTimeslot(freetime2,{"10:00","18:30"});
    std::vector<std::vector<std::string>> bothFree;//where both are free

    //std::vector<std::vector<std::string>> combined= merge(schedule1,schedule2);
    for(int i=0;i<freetime1.size();i++){
        std::cout<<'{'<<freetime1.at(i)[0]<<","<<freetime1.at(i)[1]<<"}\t";
     }
     std::cout<<std::endl;

    for(int i=0;i<freetime2.size();i++){
        std::cout<<'{'<<freetime2.at(i)[0]<<","<<freetime2.at(i)[1]<<"}\t";
     }
     std::cout<<std::endl;


    for(int i=0;i<freetime1.size() ;i++){
          for(int j=0;j<freetime2.size() ;j++){
            if(ifoverlap(freetime1.at(i),freetime2.at(j))){
                if(compareTime(freetime2.at(j).at(0),freetime1.at(i).at(0))&& compareTime(freetime1.at(i).at(1), freetime2.at(j).at(0)) ){// see if starting time of ft2 is between start and end of t1
                    bothFree.push_back({freetime2.at(j).at(0),min(freetime1.at(i).at(1), freetime2.at(j).at(1))});// start time of ft2 and minmum of end times of both
                }
                else if(compareTime(freetime1.at(i).at(0),freetime2.at(j).at(0))&& compareTime(freetime2.at(j).at(1), freetime1.at(i).at(0))){// see if starting time of ft1 is between start and end of t2
                    bothFree.push_back({freetime1.at(i).at(0),min(freetime1.at(i).at(1), freetime2.at(j).at(1))});
               }
            }
            }
    }

    std::cout<<"both free time slots"<<std::endl;
    for(int i=0;i<bothFree.size();i++){
        std::cout<<'{'<<bothFree.at(i)[0]<<","<<bothFree.at(i)[1]<<"}\t";
     }



    return 0;
}


int val(std::string t1){
    int Time1= 60*stoi(t1.substr(0,2)) +stoi(t1.substr(t1.size()-2,2));//convert to minutes
    return Time1;

}

std::string min(std::string t1, std::string t2){
    return val(t1)<val(t2)? t1:t2;
}


bool compareTime(std::string t1, std::string t2){

    int Time1= 60*stoi(t1.substr(0,2)) +stoi(t1.substr(t1.size()-2,2));//convert to minutes
    int Time2= 60*stoi(t2.substr(0,2)) +stoi(t2.substr(t2.size()-2,2));
   
    return Time1>Time2? true:false;
}


std::vector<std::vector<std::string>> freeTimes(std::vector<std::vector<std::string>> sch){
        std::vector<std::vector<std::string>> freetime;
         for(int i=0;i<sch.size()-1;i++){
            if(sch.at(i).at(1)==sch.at(i+1).at(0)){
                continue;
            }
            std::vector<std::string> tim= {sch.at(i).at(1),sch.at(i+1).at(0)};
            freetime.push_back(tim);
            
     }
     return freetime;
}

void startNEndTimeslot(std::vector<std::vector<std::string>> &freetime, std::vector<std::string> bounds){
    std::string start=bounds.at(0);
    std::string end=bounds.at(1);
    if(start!=freetime.at(0).at(0)){
        freetime.at(0).at(0)=start;
    }
        if(end!=freetime.at(freetime.size()-1).at(1)){
        freetime.at(freetime.size()-1).at(1)=end;
    }
}

bool ifoverlap(std::vector<std::string> ft1, std::vector<std::string> ft2){
    
    if(compareTime(ft2.at(0),ft1.at(0))&& compareTime(ft1.at(1), ft2.at(0)) ){// see if starting time of ft2 is between start and end of t1
        return true;
    }
    else if(compareTime(ft1.at(0),ft2.at(0))&& compareTime(ft2.at(1), ft1.at(0))){// see if starting time of ft1 is between start and end of t2
        return true;
    }
    else{//no
        return false;
    }
}
/* 

std::vector<std::vector<std::string>> merge(std::vector<std::vector<std::string>> sh1, std::vector<std::vector<std::string>> sh2){
    
     std::vector<std::vector<std::string>> combSh;
     for(int i=0;i<sh1.size();i++){
        combSh.push_back(sh1.at(i));
     }
     for(int i=0;i<sh2.size();i++){
        combSh.push_back(sh2.at(i));
     }
     sortVec(combSh);

     return combSh;
     
   


}

void sortVec(std::vector<std::vector<std::string>> &comb){//bubble sort
    for(int i=0; i<comb.size();i++){//i reduces ther sorting array
        for (int j=0;j<comb.size()-1-i;j++){
            if(compareTime(comb.at(j).at(0), comb.at(j+1).at(0)))//comapare the starting times to sort
            {
                std::vector<std::string> temp= comb.at(j);
                comb.at(j)=comb.at(j+1);
                comb.at(j+1)=temp;
            }
        }
    }
    
} */