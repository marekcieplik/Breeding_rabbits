#include "farm.h"
#include <cstdlib>

void Farm::subBmales(){ males--;}
void Farm::subBfemales(){ females--;}
void Farm::subBmutant(){ mutant--;}

void Farm::addAgesOfFarm(){ agesOfFarm++;};
void Farm::addBmales(){ males++;}
void Farm::addBfemales(){ females++;}
void Farm::addBmutant(){ mutant++;}

int Farm::getAgesOfFarm() {   return agesOfFarm; }
int Farm::getBmales(){    return males;}
int Farm::getBfemales(){    return females;}
int Farm::getBmutant(){ return mutant;}

void Farm::addBunny(Bunny bun)
{
    if (false == bun.getRad())
    {
        if ('M' == bun.getSex()) addBmales();
        if ('F' == bun.getSex()) addBfemales();
    }
    else addBmutant();

    population.push_back(bun);
}
Farm::Farm()
{
    agesOfFarm =1;
    males=0;
    females=0;
    mutant=0;
}

Farm::~Farm()
{
    //dtor
}
