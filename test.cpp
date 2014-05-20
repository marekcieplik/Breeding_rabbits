#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include "farm_stat.h"
#include "farm.h"
//#include "D:\\kuzniacpp\\Code_Blocks_Files\\kp\\Kroliki\\bunny.h"

bool Kroliki_test_FarmaNotEmpty(){
    Farm farm1;
    if (0 == (farm1.getBfemales()+farm1.getBmales()+ farm1.getBmutant()) )
    {
          return false;
    }else return true;
}

bool Kroliki_test_FarmaInit5(){
    Farm farm1;
    Farm_stat statFarm1(farm1);

    if (5 == (farm1.getBfemales()+farm1.getBmales()+ farm1.getBmutant()) )
    {
          return true;
    }else return false;
}

bool Kroliki_test_FarmaInitThreeDifferent(){
    Farm farm1;
    Farm_stat statFarm1(farm1);
    Farm farm2;
    Farm_stat statFarm2(farm2);
    Farm farm3;
    Farm_stat statFarm3(farm3);
    statFarm1.showBeginStat(farm1);
    statFarm2.showBeginStat(farm2);
    statFarm3.showBeginStat(farm3);
    std::cout << std::endl;

    if ( farm1.getBfemales() != farm2.getBfemales()||
         farm1.getBfemales() != farm3.getBfemales()
        )
    {
          return true;
    }else return false;
}

bool Kroliki_test_FarmaInitProcMutant(int howManyProc, int howManyFarms){
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

bool Kroliki_test_BunnyBornZeroAge(){
    Bunny b1;
    if ( 0 == b1.getAge() ){
          return true;
    }else return false;
}

bool Kroliki_test_BunnyAgingOneYear(){
    Bunny b1;
    b1.agingBun();
    if ( 1 == b1.getAge() ){
          return true;
    }else return false;
}

bool Kroliki_test_BunnyDying(){
    Bunny b1;
    for (int i = 0; i < Bunny::maxAgeNormal; i++)
        b1.agingBun();
    if ( true == b1.dyingBun() ){
          return true;
    }else return false;
}

void test()
{
    std::cout << std::endl<< "Kroliki_test_FarmaNotEmpty() ";
    if (Kroliki_test_FarmaNotEmpty()){
        std::cout << ".";
    }else std::cout << "x";

    std::cout << std::endl<< "Kroliki_test_FarmaInit5() ";
    if (Kroliki_test_FarmaInit5()){
        std::cout << ".";
    }else std::cout << "x";

    std::cout << std::endl<< "Kroliki_test_FarmaInitThreeDifferent() ";
    if (Kroliki_test_FarmaInitThreeDifferent()){
        std::cout << ".";
    }else std::cout << "x";

    std::cout << std::endl<< "Kroliki_test_FarmaInitProcMutant(illsProcent=2,buildFarm=100) ";
    const int buildFarm = 100;
    const int illsProcent = 2;
    if (Kroliki_test_FarmaInitProcMutant(illsProcent,buildFarm)){
        std::cout << ".";
    }else std::cout << "x";
    //

    std::cout << std::endl<< "Kroliki_test_BunnyBornZeroAge() ";
    if (Kroliki_test_BunnyBornZeroAge()){
        std::cout << ".";
    }else std::cout << "x";

    std::cout << std::endl<< "Kroliki_test_BunnyAgingOneYear() ";
    if (Kroliki_test_BunnyAgingOneYear()){
        std::cout << ".";
    }else std::cout << "x";

    std::cout << std::endl<< "Kroliki_test_BunnyDying() ";
    if (Kroliki_test_BunnyDying()){
        std::cout << ".";
    }else std::cout << "x";
}
int main()
{
    std::cout << "Hello! Test of rabbits population!" << std::endl;
    srand(time(NULL));
    test();
    return 0;
}
