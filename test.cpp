#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include "farm_stat.h"
#include "farm.h"
//#include "D:\\kuzniacpp\\Code_Blocks_Files\\kp\\Kroliki\\bunny.h"

bool Kroliki_test_FarmaEmpty()
{
    Farm farm1;
    if (0 == (farm1.getBfemales()+farm1.getBmales()+ farm1.getBmutant()) )
    {
          return true;
    }else return false;
}
bool Kroliki_test_FarmaInit5()
{
    Farm farm1;
    Farm_stat statFarm1(farm1);

    if (5 == (farm1.getBfemales()+farm1.getBmales()+ farm1.getBmutant()) )
    {
          return true;
    }else return false;
}
bool Kroliki_test_FarmaInitThreeDifferent()
{
    Farm farm1;
    Farm_stat statFarm1(farm1);
    Farm farm2;
    Farm_stat statFarm2(farm2);
    Farm farm3;
    Farm_stat statFarm3(farm3);
    statFarm1.showStat(farm1);
    statFarm2.showStat(farm2);
    statFarm3.showStat(farm3);
    std::cout << std::endl;

    if ( farm1.getBfemales() != farm2.getBfemales()||
         farm1.getBfemales() != farm3.getBfemales()
        )
    {
          return true;
    }else return false;
}
bool Kroliki_test_FarmaInitProcMutant(int howManyProc, int howManyFarms)
{
    int ills = 0;
    int population = 0;

    std::vector <Farm> farms(howManyFarms);
    std::vector <Farm_stat> statFarms;
    for (int i = 0 ; i < howManyFarms; i++){
        statFarms.push_back(farms[i]);
        ills += farms[i].getBmutant();
        population += farms[i].getBmutant();
        population += farms[i].getBmales();
        population += farms[i].getBfemales();
    }
    //std::cout << ills << " * 100.0 / " << population << std::endl;
    if ( (ills * 100.0 / population) <= howManyProc)
        return true;

    return false;
}

void test()
{
    if (Kroliki_test_FarmaEmpty()){
        std::cout << ".";
    }else std::cout << "x";
    if (Kroliki_test_FarmaInit5()){
        std::cout << ".";
    }else std::cout << "x";
    if (Kroliki_test_FarmaInitThreeDifferent()){
        std::cout << ".";
    }else std::cout << "x";
    const int buildFarm = 100;
    const int illsProcent = 2;
    if (Kroliki_test_FarmaInitProcMutant(illsProcent,buildFarm)){
        std::cout << ".";
    }else std::cout << "x";
    //
}
int main()
{
    std::cout << "Hello! Test of rabbits population!" << std::endl;
    srand(time(NULL));
    test();
    return 0;
}
