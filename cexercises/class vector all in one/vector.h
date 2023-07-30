
#ifndef VECTOR_H //avoids multiple inclucions
#define VECTOR_H


class vector3d
{
    protected:
        float x,y,z;
    public:
        vector3d();
        vector3d(int,int,int);
        void setVect(int,int ,int);
        void printVector();
        vector3d addV( vector3d,vector3d);
        void subV(vector3d,vector3d);
};
#endif