#include"Formulas.h"
#include<math.h>

#define PI 3.14159265
//Pythagorean formula - we will pass the unknown value as invalid -1 and we will calculate it
void Formulas::PythagoreanTheorem(double &a, double &b, double &c)
{
    if(c == -1)
    {
        c = sqrt(pow(a, 2) + pow(b, 2));  //c^2 = a^2 + b^2
    }
    else if(a == -1)
    {
        a = sqrt(pow(c, 2) - pow(b, 2));  //a^2 = c^2 - b^2
    }
    else
    {
        b = sqrt(pow(c, 2)- pow(a, 2));
    }
}
//finds a square diagonal with side a
double Formulas::FindDiagonalOfSquare(double &a)
{
    double diagonal = -1;
    PythagoreanTheorem(a, a, diagonal);
    return diagonal;
}
//Height of the pyramid (the luminaire)
double Formulas::FindHeight(double &baseEdge)
{
    double height = -1;
    double HalfDiagonal = FindDiagonalOfSquare(baseEdge)/2.0;
    PythagoreanTheorem(HalfDiagonal, height, baseEdge);    // по условие осалният и основният са равни
    return height;
}
//An edge
double Formulas::FindSurroundingEdge(double &blendSize, double &height)
{
    double surrEdge = -1;
    double HalfDiagonal = FindDiagonalOfSquare(blendSize)/2.0;
    PythagoreanTheorem(HalfDiagonal, height, surrEdge);
    return surrEdge;
}
//Asymptote
double Formulas::FindAsymptote(double &blendSize, double &height)
{
    double asymptote = -1;
    double HalfBase = blendSize/2.0;
    PythagoreanTheorem(height, HalfBase, asymptote);
    return asymptote;
}
//Angle between height and asymptote
double Formulas::FindAngleBetweenHeightAndAsymptote(double &blendSize, double &height)
{
    // Because it is the correct quadrangular pyramid, the asymptote is a median
    double HalfBase = blendSize/2.0;

    double angle = atan(HalfBase/height)* 180 / PI;
    return angle;
}
//Calculate the positive X coordinate by the angle we have given (angle between the asymptote and H) - alpha or beta
double Formulas::FindX(double &blendSize, double &angle, double &H, double &height)
{
    double BigAsymptote = H / cos(angle);
    double SmallAsymptote = FindAsymptote(blendSize, height);
    double SmallSurrEdge = FindSurroundingEdge(blendSize, height);
    double resultSurrEdge = (SmallSurrEdge * BigAsymptote) / SmallAsymptote;

    double x = -1;
    PythagoreanTheorem(x, BigAsymptote, resultSurrEdge);
    return x;
}
//Calculate the Y coordinate
double Formulas::FindY(double &angle, double &H)
{
    double Y = H * tan(angle);
    return Y;
}

