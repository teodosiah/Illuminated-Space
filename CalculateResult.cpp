#include"CalculateResult.h"
#include <math.h>
void IlluminatedSpace::calculateIlluminatedSpacePoints(double &baseEdge, double &Height, double &blendSize, double &rotationAngle)
{
    point A, B, C, D;
    A.z = B.z = C.z = D.z = Height;
    Formulas formula;

    double heightOfPrysm = formula.FindHeight(baseEdge);

    double alpha = fabs(rotationAngle) - formula.FindAngleBetweenHeightAndAsymptote(blendSize, heightOfPrysm);
    double beta = fabs(rotationAngle) + formula.FindAngleBetweenHeightAndAsymptote(blendSize, heightOfPrysm);

    //Х coordinates of the small base
    double x_smaller = formula.FindX(blendSize, alpha, Height, heightOfPrysm);
    A.x = -x_smaller;
    B.x = x_smaller;
    //Х coordinates of the big base
    double x_bigger = formula.FindX(blendSize, beta, Height, heightOfPrysm);
    C.x = -x_bigger;
    D.x = x_bigger;

    //У coordinates of the small base
    double y_smaller = formula.FindY(alpha, Height);
    //Y coordinates of the big base
    double y_bigger = formula.FindY(beta, Height);

    if(rotationAngle<0)
    {
        A.y = B.y = -y_smaller;
        C.y = D.y = -y_bigger;
    }
    else
    {
        A.y = B.y = y_smaller;
        C.y = D.y = y_bigger;
    }

    //output
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;


}
void IlluminatedSpace::printSpace()
{
    A.printPoint();
    B.printPoint();
    C.printPoint();
    D.printPoint();
}


