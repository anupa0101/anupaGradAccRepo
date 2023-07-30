#include<iostream>
#include<fstream>///file stream
#include<conio.h>
#include<vector>
#include<string>

int main(){
    std::string fname;
    std::cout<<"Enter file name: "<<std::endl;
    std::cin>>fname;

    std::ofstream fileW(fname, std::ios::app);
   // std::ofstream fileW("helo.txt", std::ios::app);  //creating a output file stream object
   // fileW.open("helo.txt"); //

   if(fileW.is_open()){
    std::cout<<"file open"<<std::endl;
   }
    fileW<<"hey anipa"; //Like std::cout //
    //LIKE WRITING TO THE COSOLE ,WRITING TO FILE <<

    std::vector<std::string> names;
    names={"anupa","sattharas","bjhsg"};
    names.push_back("jnfdjvn");

    for(std::string n: names){
        fileW<<n<<std::endl;
    }


    fileW.close();
    return 0;
}