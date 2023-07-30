#ifndef VECTX_H
#define VECTX_H

class vectx{
    protected:
    float x,y;

    public:
        vectx();
        vectx(float,float); // USE MEMEBER INIIALIZER LISTS - MORE EFFICEINT THAN ASSIGNMENT. especially for large objects
        void show();
        vectx operator+(const vectx&) const;// outside const is to make sure no changes are made to the object inside the function
        void operator+=(const vectx&) ;// cant use const here outside the fucntion as we are making changes to the object
        friend vectx operator-(const vectx&,const vectx&);
        friend vectx operator*(float,const vectx&);
        friend vectx operator*(const vectx&,float);
        friend std::ostream& operator<<(std::ostream& os, const vectx& obj);// need to make it a friend fucntion because fucntion to access the private vairables
        friend std::istream& operator>>(std::istream& is,  vectx& obj); //no const vectx as vectx obj is modified

};



#endif