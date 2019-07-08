#ifndef INITIALISATION_H_INCLUDED
#define INITIALISATION_H_INCLUDED

#include"Validation.h"

void init(double &baseEdge, double &Height, double &blendSize, double &rotationAngle)
{
    std::cout<<"Enter the value of base edge (between 10.0 and 25.0) : ";
    std::cin>>baseEdge;
    validationOfBaseEdge(baseEdge);

    std::cout<<"Enter the value of room height (between 260.0 and 480.0) : ";
    std::cin>>Height;
    validationOfRoomHeight(Height);

    std::cout<<"Enter the value of blend size (positive number smaller than base edge) : ";
    std::cin>>blendSize;
    validationOfBlend(baseEdge, blendSize);

    std::cout<<"Enter the value of angle (between -60.0 and 60.0) : ";
    std::cin>>rotationAngle;

    validationOfAngle(rotationAngle);
}

void area_initialization(double &area){
    std::cout<<"Enter the room area (in square meters): ";
    std::cin>>area;
    while(area < 0){
        std::cout<<"Wrong value!\nEnter number greater than 0: ";
        std::cin>>area;
    }
}
#endif // INITIALISATION_H_INCLUDED
