#include<iostream>
#include<mutex>

class Base{

    public:
        int a;
        mutable int b;// can be changed inside const fucntions despite
        mutable std::mutex mutLock;// MARK MUTEXES AS MUTABLE (M&M RULE)
        //beacuse mutexes are going to change states

        void changeA() const{ //although we declaare no changes can be made to member cvvariable we can due to mutable
            b=344;
        }

        int get() const{// lock even the read functions 
            std::lock_guard<std::mutex> lg(mutLock);// mutex state will change so mark it as mutable(if inside const func)
            return b;
        }
        int inc(){
            std::lock_guard<std::mutex> lg(mutLock);
            ++b;
        }
};
int main(){


    return 0;
}