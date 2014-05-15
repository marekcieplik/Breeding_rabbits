#include <iostream>
#include <cstdlib>
#include <time.h>
#include "farm_stat.h"
#include "farm.h"
//#include "bunny.h"

int main()
{
    srand(time(NULL));
    std::cout << "Hello! This is a simulation of rabbits population on a farm.\n"<<std::endl;
    Farm farm1;
    Farm_stat statFarm1(farm1);
    statFarm1.showStat(farm1);
    return 0;
}
