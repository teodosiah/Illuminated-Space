#include"ResultInRoom.h"
#include<math.h>
#include <algorithm>
double IlluminatedSpaceInRoom::calculateFloorCoordinates(double &area)
{
    double toCantimeter = area * 100;
    return (sqrt(toCantimeter)) / 2;
}
void IlluminatedSpaceInRoom::initializeTheFloor(double &area, double &height)
{
    double positiveCoordinate = calculateFloorCoordinates(area);
    double negativeCoordinate = -positiveCoordinate;

    //the floor - MNPQ
    M.x = negativeCoordinate;
    M.y = negativeCoordinate;
    N.x = positiveCoordinate;
    N.y = negativeCoordinate;
    P.x = positiveCoordinate;
    P.y = positiveCoordinate;
    Q.x = negativeCoordinate;
    Q.y = positiveCoordinate;

    M.z = N.z = P.z = Q.z = height;
}
void IlluminatedSpaceInRoom::swapPoints(point &A, point&B)
{
    point swapPoint = A;
    A = B;
    B = swapPoint;
}
bool IlluminatedSpaceInRoom::IsPointInInterval(double leftCoordinate, double rightCoordinate, double point)
{
    if (point >= leftCoordinate && point <= rightCoordinate) return true;
    return false;
}
point IlluminatedSpaceInRoom::findPointBetweenTwoLines(point &A, point &C, point &B, point &D)
{
    point Res;
    Res.z = A.z;
    // Line AC represented as a1x + c1y = d1
    double a1 = C.y - A.y;
    double c1 = A.x - C.x;
    double d1 = a1*(A.x) + c1*(A.y);

    // Line BD represented as a2x + c2y = d2
    double a2 = D.y - B.y;
    double c2 = B.x - D.x;
    double d2 = a2*(B.x)+ c2*(B.y);

    double determinant = a1*c2 - a2*c1;

    Res.x = (c2*d1 - c1*d2)/determinant;
    Res.y = (a1*d2 - a2*d1)/determinant;

    return Res;
}
void IlluminatedSpaceInRoom::FindWhereTheFloorIsIlluminated(double floorArea, IlluminatedSpace &space)
{
    double height = space.A.z;
    initializeTheFloor(floorArea, height);

    if(fabs(space.A.x) < fabs(space.C.x))
    {
        swapPoints(space.A, space.C);
        swapPoints(space.B, space.D);
    }
    bool isSwapedSquare = false;
    if(space.A.y > space.C.y)
    {
        swapPoints(M, Q);
        swapPoints(N, P);
        isSwapedSquare = true;
    }


    if((!isSwapedSquare && (space.C.y < M.y || space.A.y > Q.y)) ||
            (isSwapedSquare && (space.C.y > M.y || space.A.y < Q.y)) ) //0 points - space is not in the square
    {
        std::cout<<"The floor is not illuminated!\n";
        return;
    }
    else if(IsPointInInterval(0, fabs(M.x), fabs(space.C.x)) &&
            IsPointInInterval(0, fabs(M.x), fabs(space.A.x)) ) // 4 points
    {
        if(!(IsPointInInterval(0, fabs(M.y), fabs(space.C.y))) ) // VIII & VII graphics
        {
            space.C = findPointBetweenTwoLines(space.A, space.C, Q, P);
            space.D = findPointBetweenTwoLines(space.B, space.D, Q, P);
        }
        if(!(IsPointInInterval(0, fabs(M.y), fabs(space.A.y))) ) // VI & VII graphics
        {
            space.A = findPointBetweenTwoLines(space.A, space.C, M, N);
            space.B = findPointBetweenTwoLines(space.B, space.D, M, N);
        }

        space.printSpace();
        return;

    }
    else if(!(IsPointInInterval(0, fabs(M.x), fabs(space.C.x))) &&
            !(IsPointInInterval(0, fabs(M.x), fabs(space.A.x))) )  //II & IV & V graphics
    {
        space.A.x = std::max(space.A.x, M.x);
        if(space.A.y < 0) space.A.y = std::max(space.A.y, M.y);
        else space.A.y = std::min(space.A.y, M.y);

        space.C.x = std::max(space.C.x, Q.x);
        if(space.C.y > 0) space.C.y = std::min(space.C.y, Q.y);
        else space.C.y = std::max(space.C.y, Q.y);

        //because the figure is isosceles trapezoid
        space.B.x = -space.A.x;
        space.B.y = space.A.y;

        space.D.x = -space.C.x;
        space.D.y = space.C.y;

        space.printSpace();
        return;

    }
    else if(IsPointInInterval(0, fabs(M.x), fabs(space.C.x)) &&
            !(IsPointInInterval(0, fabs(M.x), fabs(space.A.x))) )  // 6 points
    {
        if(! IsPointInInterval(0, fabs(M.y), fabs(space.C.y)) )    //X & XI graphics
        {
            space.C = findPointBetweenTwoLines(space.A, space.C, Q, P);
            space.D = findPointBetweenTwoLines(space.B, space.D, Q, P);
        }

        point leftIntersectionSquareAndTrapezoid = findPointBetweenTwoLines(space.A, space.C, M, Q);
        point rightIntersectionSquareAndTrapezoid = findPointBetweenTwoLines(space.B, space.D, N, P);

        if(!(IsPointInInterval(0, fabs(M.y), fabs(space.A.y))) )   //IX & XII graphics
        {
            space.A = findPointBetweenTwoLines(space.A, space.C, M, N);
            space.B = findPointBetweenTwoLines(space.B, space.D, M, N);
        }
        space.A.printPoint();
        space.B.printPoint();
        leftIntersectionSquareAndTrapezoid.printPoint();
        rightIntersectionSquareAndTrapezoid.printPoint();
        space.C.printPoint();
        space.D.printPoint();
        return;
    }



}
