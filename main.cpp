#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include "farm_stat.h"
#include "farm.h"
//#include "bunny.h"

int main()
{
    srand(time(NULL));
    std::cout << "Hello! This is a simulation of rabbits population on a farm.\n"<<std::endl;
    Farm farm1;
    Farm_stat stat(farm1);
    stat.showBeginStat(farm1);

    //while( 0 < farm1.getFarmQuantity())   
	for (int t = 0 ; t < 20; t++)
	{
        farm1.init(farm1.reproductivePair());
        //farm1.radioactive(farm1.getBmutant());
        farm1.addOneYear();
        farm1.checkBunnysAge();
        stat.showStat(farm1);
        //stat.showAgesOfBunnys(farm1);
}

    return 0;
}
