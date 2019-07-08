#ifndef RUN_H_INCLUDED
#define RUN_H_INCLUDED

#include <stdlib.h>
#include"Initialisation.h"
#include"CalculateResult.h"
#include"ResultInRoom.h"
#include"ConsoleColor.h"

void menu()
{
    std::cout<<blue<<"Task: \n";
    std::cout<<"1. "<<white<<"Calculate the illuminated space in an unlimited plane \n";
    std::cout<<blue<<"2. "<<white<<"Calculating the illuminated floor space of a square room \n";
    std::cout<<red<<"\nIf you want to close the program enter 0\n"<<white;
}
void answerValidation(char &answer)
{
    while(answer != 'y' && answer != 'n')
    {
        std::cout<<red<<"Wrong answer!\n Choose between y(yes) or n(no): "<<white;
        std::cin>>answer;
    }
}
void subMenu(int option, char &answer)
{
    if(option == 0)
    {
        std::cout<<yellow<<"Do you want to see the result for this input but in square room?"<<white<<" (y/n):  ";
    }
    else if(option == 1)
    {
        std::cout<<yellow<<"Do you want to see the result for this input but in unlimited plane?"<<white<<" (y/n): ";
    }
    else
    {
        std::cout<<red<<"Do you want to close the program? "<<white<<"(y/n): ";
    }
    std::cin>>answer;
    answerValidation(answer);
}
void executeOption(int option, int coutOfExecutions, double &baseEdge, double &Height, double &blendSize, double &rotationAngle)
{
    //calculate points of illuminated space
    IlluminatedSpace space;
    space.calculateIlluminatedSpacePoints(baseEdge, Height, blendSize, rotationAngle);

    char answer;

    if(option == 1)
    {
        std::cout<<blue;
        space.printSpace();
        std::cout<<white;
        coutOfExecutions++;
        if(coutOfExecutions != 1) return;

        subMenu(0, answer);
        if(answer == 'y') executeOption(2, coutOfExecutions, baseEdge, Height, blendSize, rotationAngle);


    }
    else
    {
        double area;
        area_initialization(area);
        std::cout<<blue;
        IlluminatedSpaceInRoom room;
        room.FindWhereTheFloorIsIlluminated(area, space);
        std::cout<<white;
        coutOfExecutions++;
        if(coutOfExecutions != 1) return;

        subMenu(1, answer);
        if(answer == 'y') executeOption(1, coutOfExecutions, baseEdge, Height, blendSize, rotationAngle);
    }
    subMenu(2, answer);
    if(answer == 'y') exit(0);
}
void run()
{
    menu();
    int option;
    std::cout<<"\nEnter task number (or 0 if you want to exit): ";
    std::cin>>option;

    while(option < 0 || option > 2)
    {
        std::cout<<red<<"Wrong option!\n Enter task number (1 or 2) or 0 if you want to exit: "<<white;
        std::cin>>option;
    }
    if(option == 0)
    {
        exit(0);
    }
    else
    {
        double baseEdge, Height, blendSize, rotationAngle;
        std::cout<<blue<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"<<white;
        //initialisation and validation
        init(baseEdge, Height, blendSize, rotationAngle);

        int countOfExecution = 0;
        executeOption(option, countOfExecution, baseEdge, Height, blendSize, rotationAngle);


        run();
    }

}


#endif // RUN_H_INCLUDED
