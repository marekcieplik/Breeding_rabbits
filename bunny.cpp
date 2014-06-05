#include "bunny.h"
#include <cstdlib>
//public
Bunny::Bunny(){
    int chance = rand()%100;
    if (chance % 2 == 0){ setSex('F');
    }else setSex('M');

    if (chance < 2){      setRad(true);
    }else setRad(false);
    Age = 0;
}

Bunny::Bunny(char _sex, int _age, bool _rad)
: Sex(_sex), Age(_age), Radioactive_mutant_vampire_bunny(_rad){}

Bunny::~Bunny(){
    //dtor
}

bool Bunny::addOneYear() {
    if (false == isRad()){
        if (maxAgeNormal > Age) {
            Age++;
            return true;
        }else
            return false;
    }else{
        if (maxAgeMutant > Age) {
            Age++;
            return true;
        }else
            return false;
    }
}


bool Bunny::hasMaxAge(){
    bool isDied = false;
    if( isRad()){
        if (maxAgeMutant == getAge()){
            isDied = true;
         }
    }
    else{
        if (maxAgeNormal == getAge()){
            isDied = true;
        }
    }
    return isDied;
}

bool Bunny::reproductive(){
    bool isReproductive = false;
    if (false == Radioactive_mutant_vampire_bunny){
        if((reproductiveAge<= Age)&&(maxAgeNormal > Age) )
            isReproductive = true;
        }
    return isReproductive;
}

char Bunny::getSex(){ return Sex;}
int  Bunny::getAge(){ return Age;}
bool Bunny::isRad(){ return Radioactive_mutant_vampire_bunny;}

void Bunny::setSex(char _sex){    Sex = _sex;}
void Bunny::setAge(int  ages){    Age = ages;}
void Bunny::setRad(bool isIll){   Radioactive_mutant_vampire_bunny = isIll;}





