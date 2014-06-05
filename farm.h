#ifndef FARM_H
#define FARM_H

#include <list>
#include <string>
#include "bunny.h"
class Farm{
public:
    /*Bunny newBunny()     */


    /*bool addBunny( Bunny bun );   */
    bool addBunny( Bunny bun );

    /*std::string init(int initialPopulation) method adds bunnies to the farm
    Args: int initialPopulation gives how many bunnies it should by added
    Return: std::string which consists letters M, F or X.
    M for male, F for female, X for mutant, e.g MXMFF*/
    std::string init(int initialPopulation, bool showSpecyficaion = false); //return string e.g MXMFF

    /*Farm(int initialPopulation = 5) constructor*/
    Farm(int initialPopulation = 5, bool showSpecyficaion = false );
    virtual ~Farm();

    int getFarmQuantity();//sum of males + females + mutant; if -1 then list population.size != sum. it's mean that private members male, female, mutant had bad increment.
    bool subBunny();
	bool popBunnyFront();
	
    void addOneYear();
    void checkBunnysAge();

    Bunny getBunnyFront();
    void moveBunnyToEndOfList();

    std::string showBunnyAges();

    int reproductivePair();
    bool radioactive();

    void subBfemalesRep();
    void addAgesOfFarm();

    void addBfemalesRep();

   

    int getFAges(); //agesOfFarm

    int getBmales();
    int getBfemales();
    int getBmutant();
    
    int getBfemalesRep();
protected:
private:
    int agesOfFarm;
    std::list<Bunny> population;
    int males, females , mutants;
    int femalesRep;

};

#endif // FARM_H
