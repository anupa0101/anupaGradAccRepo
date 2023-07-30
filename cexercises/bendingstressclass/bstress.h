#ifndef BSTRESS_H
#define BSTRESS_H

class bstress{
    
    protected:
        double E, y, M, b, h, I; 
        void Intertia(double b, double h); 

    public:
        bstress(); 
        bool CheckDimension(double y, double b, double h);    
        void SetVal(double E, double y, double M, double h, double b); 
        double GetStress(); 
        double GetRadius();



};


#endif