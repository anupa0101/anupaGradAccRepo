#include<iostream>
#include<cmath> //to do math operations
using namespace std;


int main()
{
    char grade='B';
    string characterName="Anupa Satharasinghe";
    int characterAge=25;
    float gpa=2.3;
    double cgpa=3.2;
    bool isMale= false;

    cout<<characterName <<" is amazing"<<endl;
    cout<<characterName << " is " << characterAge<<" old"<<endl;
    cout <<characterName.length()<<endl; //return the length of the string
    cout <<characterName[0]<<endl;
    characterName[0]=grade;
    cout <<characterName<<endl;   
    cout <<isMale<<endl; //false prints as 0
    cout<<characterName.find("Sath",2)<<endl; //find a character or string's starting position, position from which to search
    cout<<characterName.substr(6,4)<<endl; //starting position, length of the string required
    cout<<pow(2,3)<<sqrt(8)<<round(4.3)<<ceil(4.1)<<floor(3.4)<<fmax(2,3)<<fmin(3,4)<<endl;
    
    int age, height;
    string name;
    cin>>age>>height; //cin used to take char or numbers not strings
    getline(cin,name);//to get a string
    cout<<age<<name;
    


    return 0;
}