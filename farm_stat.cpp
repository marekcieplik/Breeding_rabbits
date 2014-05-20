#include "farm_stat.h"

#include <cstdlib>
#include <iostream>
void Farm_stat::showStat(Farm & far){
        std::cout <<std::endl << "Year: " << far.getAgesOfFarm()<<")\t" << far.getBmales()<<" M\t"<< far.getBfemales()<<" F\t"<< far.getBmutant()<<" X\r";
}
void Farm_stat::showBeginStat(Farm & far){
    std::cout   <<std::endl
                << "Address: "
                <<(int)&far
                << ". Until: "
                << far.getAgesOfFarm()
                <<" year(s).\nStatus:"
                << "\tmales\tfemales\tmutant\tAGES"
                <<std::endl;
    std::cout  <<"\t" << far.getBmales()<<"\t"<< far.getBfemales()<<"\t"<< far.getBmutant()<<"\t";
}
void Farm_stat::showAgesOfBunnys(Farm & far){
    far.showBunnyAges();
}

Farm_stat::Farm_stat(Farm & farm1)
{
    //ctor
}
Farm_stat::Farm_stat()
{
    //ctor
}
Farm_stat::~Farm_stat()
{
    //dtor
}
