#include "farm_stat.h"

#include <cstdlib>
#include <iostream>
void Farm_stat::showStat(Farm & far){
        std::cout <<std::endl << "Year: " << far.getFAges()<<")\t" << far.getBmales()<<" M\t"<< far.getBfemales()<<" F\t"<< far.getBmutant()<<" X\t";
}
void Farm_stat::showBeginStat(Farm & far){
    std::cout   <<std::endl
                << "Address: "
                <<(long long)&far
                << ". Until: "
                << far.getFAges()
                <<" year(s).\nStatus:"
                << "\t\tmales\tfemales\tmutant\tAGES"
                <<std::endl;
    std::cout  <<"\t\t" << far.getBmales()<<"\t"<< far.getBfemales()<<"\t"<< far.getBmutant()<<"\t" << far.getFAges();
}
void Farm_stat::showAgesOfBunnys(Farm & far){
    std::cout<<far.showBunnyAges();
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
