#include "farm.h"
#include <iostream>
#include <cstdlib>
void Farm::agingFar(){
    for (unsigned int i = 0; i < population.size(); i++)
    {
        population.front().agingBun();
        population.push_back(population.front());
        population.pop_front();
    }

}

void Farm::dyingFar(){
    unsigned int populationSize = population.size();
    for (unsigned int i = 0; i < populationSize; i++)
    {
        if( population.front().dyingBun())
        {
            if('M' == population.front().getSex())
                subBmales();
            if('F' == population.front().getSex())
                subBfemales();
            if('X' == population.front().getSex())
                subBmutant();
            population.pop_front();


        }
        else
        {
            population.push_back(population.front());
            population.pop_front();
        }

    }

}

void Farm::showBunnyAges(){
    unsigned int populationSize = population.size();
    for (unsigned int i = 0; i < populationSize; i++)
    {
        //TODO
        std::cout<<population.front().getAge()<< population.front().getSex();
        population.push_back(population.front());
        population.pop_front();
    }
}

Bunny Farm::newBunny(){
    const int age = 0;
    const char sex = 'M';
    const bool rad = false;

    Bunny oBunny(sex, age, rad);

    int chance = rand()%100;
    if (chance % 2 == 0){
          oBunny.setSex('F');
    }else oBunny.setSex('M');

    if (chance < 2){
          oBunny.setRad(true);
    }else oBunny.setRad(false);

    return oBunny;
}

void Farm::init( int initialPopulation){
    for (int i = 0; i < initialPopulation; i++)
        addBunny(newBunny());
}

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

void Farm::addBunny(Bunny bun){
    if (false == bun.isRad())
    {
        if ('M' == bun.getSex()) addBmales();
        if ('F' == bun.getSex()) addBfemales();
    }
    else addBmutant();

    population.push_back(bun);
}

Farm::Farm(){
    agesOfFarm =1;
    males=0;
    females=0;
    mutant=0;
    const int initialPopulation = 5;
    init(initialPopulation);
}

Farm::~Farm()
{
    //dtor
}
