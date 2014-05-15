#include "farm_stat.h"

#include <cstdlib>
#include <iostream>
void Farm_stat::showStat(Farm & far)
{
    std::cout <<std::endl << (int)&far <<std::endl;
    std::cout << "males\tfemales\tmutant"<<std::endl;
    std::cout << far.getBmales()<<"\t"<< far.getBfemales()<<"\t"<< far.getBmutant()<<"\r";
}
Bunny Farm_stat::newBunny()
{
    const int age = 0;
    const char sex = 'M';
    const bool rad = false;

    Bunny oBunny(age, sex, rad);

    int chance = rand()%100;
    if (chance % 2 == 0){
          oBunny.setSex('F');
    }else oBunny.setSex('M');

    if (chance < 2){
          oBunny.setRad(true);
    }else oBunny.setRad(false);

    return oBunny;
}
void Farm_stat::init( Farm & farm1)
{
    const int initialPopulation = 5;
    for (int i = 0; i < initialPopulation; i++)
    farm1.addBunny(newBunny());
}
Farm_stat::Farm_stat(Farm & farm1)
{
    //ctor
    init(farm1);
}
Farm_stat::Farm_stat()
{
    //ctor
}
Farm_stat::~Farm_stat()
{
    //dtor
}
