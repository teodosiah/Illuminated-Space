#ifndef RESULTINROOM_H_INCLUDED
#define RESULTINROOM_H_INCLUDED
#include"CalculateResult.h"
class IlluminatedSpaceInRoom
{
public:
    void FindWhereTheFloorIsIlluminated(double, IlluminatedSpace&);
private:
    IlluminatedSpace roomSpace;
    point M, N, P, Q; //coordinates of the floor

    void initializeTheFloor(double&, double&);
    double calculateFloorCoordinates(double&);
    void swapPoints(point&, point&);
    bool IsPointInInterval(double, double, double);
    point findPointBetweenTwoLines(point&, point&, point&, point&);

};




#endif // RESULTINROOM_H_INCLUDED
