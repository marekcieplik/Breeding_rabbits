#include "farm.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <time.h>
//public
Farm::Farm(int initialPopulation, bool showSpecyfication){
    agesOfFarm =0;
    males=0;
    females=0;
    femalesRep=0;
    mutants=0;
    init(initialPopulation,showSpecyfication);
}

Farm::~Farm(){
    //dtor
}

std::string Farm::init( int initialPopulation, bool showSpecyfication){
    std::string specificationF = "";
    for (int i = 0; i < initialPopulation; i++){

        Bunny bun;
        addBunny( bun );
        if (true == population.back().isRad()){
            specificationF += 'X';
        }else{
            specificationF += population.back().getSex();
        }
    }
    if (showSpecyfication) std::cout << std::endl << specificationF;
    return specificationF;

}

bool Farm::addBunny(Bunny  bun){
	if (true == bun.isRad() && ( ('M' == bun.getSex()) || ('F' == bun.getSex()) ) && (0 == bun.getAge()) ){
		mutants++;
		population.push_back(bun);
        return true;
	}else if (false == bun.isRad() && ( ('M' == bun.getSex()) || ('F' == bun.getSex()) ) && (0 == bun.getAge())){
		if ('M' == bun.getSex()) males++; else females++;
		population.push_back(bun);
        return true;
	}else return false;
}


void Farm::addOneYear(){
    agesOfFarm++;
    for (unsigned int i = 0; i < population.size(); i++)    {
        population.front().addOneYear();
        if ('F' == getBunnyFront().getSex() &&
            Bunny::reproductiveAge == getBunnyFront().getAge())
                femalesRep++;
        population.push_back(population.front());
        population.pop_front();
    }
}

void Farm::checkBunnysAge(){
	//TODO fixme
    unsigned int populationSize = population.size();
    for (unsigned int i = 0; i < populationSize; i++)    {
        if( population.front().hasMaxAge())        {
            if('M' == population.front().getSex())
                males--;
            if('F' == population.front().getSex())
                females--;
            if('F' == population.front().getSex() &&
                Bunny::reproductiveAge == population.front().getAge())
                subBfemalesRep();

            if('X' == population.front().getSex())
                mutants--;
            population.pop_front();
        }
        else        {
            population.push_back(population.front());
            population.pop_front();
        }
    }
}

Bunny Farm::getBunnyFront(){
    return population.front();
}

bool Farm::popBunnyFront(){
	Bunny bun = population.front();
	if (true == bun.isRad() && ( ('M' == bun.getSex()) || ('F' == bun.getSex()) ) ){
		mutants--;
		population.pop_front();
        return true;
	}else if (false == bun.isRad() && ( ('M' == bun.getSex()) || ('F' == bun.getSex()) )){
		if ('M' == bun.getSex()) males--; else females--;
		population.pop_front();
        return true;
	}else {
    	std::cout <<"Farm::popBunnyFront(): There is bunny with wrong sex identyfier. ";
    	return false;
    }

}
	
void Farm::moveBunnyToEndOfList(){
    population.push_back(population.front());
    population.pop_front();
}

bool Farm::subBunny(){	
	Bunny bun = population.front();
	if (true == bun.isRad() && ( ('M' == bun.getSex()) || ('F' == bun.getSex()) ) && (Bunny::maxAgeMutant == bun.getAge()) ){
		mutants--;
		population.pop_front();
        return true;
	}else if (false == bun.isRad() && ( ('M' == bun.getSex()) || ('F' == bun.getSex()) ) && (Bunny::maxAgeNormal == bun.getAge())){
		if ('M' == bun.getSex()) males--; else females--;
		population.pop_front();
        return true;
	}else {
    	std::cout <<"Farm::popBunnyFront(): There is bunny with wrong sex identyfier. ";
    	return false;
    }
    
}

std::string Farm::showBunnyAges(){
    std::string specificationF = "";
    char buf[100];
    for ( int i = 0; i < getFarmQuantity(); i++)    {
        specificationF += itoa(population.front().getAge(),buf,10);
        specificationF += population.front().getSex();
        moveBunnyToEndOfList();
    }
    return specificationF;
}

int Farm::reproductivePair(){
	int malesRep = 0;
	int femalesRep = 0;
	Bunny bun;
	
    for (int i = 0 ; i < getFarmQuantity(); i++){
    	bun = population.front();
		if (false == bun.isRad() && ( ('M' == bun.getSex()) || ('F' == bun.getSex()) ) && (Bunny::reproductiveAge <= bun.getAge())){
			if ('M' == bun.getSex()) malesRep++; else femalesRep++;
		}
         moveBunnyToEndOfList();
    }
    
	if (0 < malesRep && 0 < femalesRep)
        return femalesRep;
    else
        return 0;
}

bool Farm::radioactive(){
///////////////////////// ALGORYTM LOSOWANIA BEZ POWTORZEN //////////////////////
//srand(time(NULL));

    int ile_pytan = 20; //z ilu pytan losujemy?
    int ile_wylosowac = 5; //ile pytan wylosowac?
    int ile_juz_wylosowano=0; //zmienna pomocnicza
    int *wylosowane = new int[ile_wylosowac+1]; //rezerwacja tablicy
    bool losowanie_ok;

    for (int i=1; i<=ile_wylosowac; i++)
    {
		do
		{
            int liczba=rand()%ile_pytan+1; //losowanie w C++
            losowanie_ok=true;

			for (int j=1; j<=ile_juz_wylosowano; j++)
			{
				//czy liczba nie zostala juz wczesniej wylosowana?
				if (liczba==wylosowane[j]) losowanie_ok=false;
			}

			if (losowanie_ok==true)
			{
				//mamy unikatowa liczbe, zapiszmy ja do tablicy
				ile_juz_wylosowano++;
				wylosowane[ile_juz_wylosowano]=liczba;
			}
		} while(losowanie_ok!=true);
    }

///////////////////////// ZOBACZ REZULTATY LOSOWANIA //////////////////////

	std::cout<<"Wylosowane numery: ";
    for (int i=1; i<=ile_wylosowac; i++)
    {
		std::cout<<wylosowane[i]<<" ";
	}

	return false;
}

void Farm::subBfemalesRep(){ femalesRep--;}

void Farm::addAgesOfFarm(){ agesOfFarm++;};

void Farm::addBfemalesRep(){ femalesRep++;}


int Farm::getFAges() {   return agesOfFarm; }
int Farm::getFarmQuantity(){
    int sizeFarm = (getBmales()+getBfemales()+getBmutant());
    if (int (population.size()) == sizeFarm)
        return sizeFarm;
    else
        return -1;
    }
int Farm::getBmales(){    return males;}
int Farm::getBfemales(){    return females;}
int Farm::getBfemalesRep(){    return femalesRep;}
int Farm::getBmutant(){ return mutants;}
