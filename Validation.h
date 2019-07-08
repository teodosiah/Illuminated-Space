#ifndef VALIDATION_H_INCLUDED
#define VALIDATION_H_INCLUDED


//between 10 and 25
void validationOfBaseEdge(double &baseEdge)
{
    while (baseEdge < 10.0 || baseEdge > 25.0)
    {
        std::cout<<"Wrong value of base edge! \n Please enter value between 10.0 and 25.0: ";
        std::cin>>baseEdge;
    }
}
//between 260 and 480
void validationOfRoomHeight(double &height)
{
    while (height < 260.0 || height > 480.0)
    {
        std::cout<<"Wrong value of room height! \n Please enter value between 260.0 and 480.0: ";
        std::cin>>height;
    }
}
//smaller than baseEdge
void validationOfBlend(double &baseEdge, double &blendSize)
{
    while (blendSize < 0 || blendSize > baseEdge)
    {
        std::cout<<"Wrong value of blend size! \n Please enter positive value smaller than"<<baseEdge<<": ";
        std::cin>>blendSize;
    }
}
void validationOfAngle(double &angle)
{
    while (angle < -60.0 || angle > 60.0)
    {
        std::cout<<"Wrong value of angle! \n Please enter value between -60.0 and 60.0: ";
        std::cin>>angle;
    }
}
#endif // VALIDATION_H_INCLUDED
