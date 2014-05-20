#include "bunny.h"
//public
char Bunny::getSex(){ return Sex;}
int  Bunny::getAge(){ return age;}
bool Bunny::isRad(){ return radioactive_mutant_vampire_bunny;}

void Bunny::setSex(char _sex){    Sex = _sex;}
void Bunny::setAge(int  ages){    age = ages;}
void Bunny::setRad(bool isIll){   radioactive_mutant_vampire_bunny = isIll;}

void Bunny::addAge(){
    age++;
}
Bunny::Bunny(char _Sex, int _age, bool _ill)
{
    //ctor
    setSex(_Sex);
    setAge(_age);
    setRad(_ill);
}
Bunny::~Bunny()
{
    //dtor
}

//protected
void  Bunny::agingBun() {
        age++;
}

bool Bunny::dyingBun(){
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
