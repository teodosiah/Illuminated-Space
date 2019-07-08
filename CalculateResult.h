#ifndef CALCULATERESULT_H_INCLUDED
#define CALCULATERESULT_H_INCLUDED

#include"Formulas.h"
#include <iomanip>
#include<iostream>
struct point
{
    double x, y, z;
    void printPoint()
    {
        std::cout<<std::fixed<<std::setprecision(2)<<"("<<x<<", "<<y<<", "<<z<<")\n";
    }
};

struct IlluminatedSpace
{
    void calculateIlluminatedSpacePoints(double&, double&, double&, double&);
    void printSpace();

    point A, B, C, D;

};

#endif // CALCULATERESULT_H_INCLUDED
