#include "bunny.h"
char Bunny::getSex(){ return Sex;}
int  Bunny::getAge(){ return age;}
bool Bunny::getRad(){ return radioactive_mutant_vampire_bunny;}

void Bunny::setSex(char _sex){    Sex = _sex;}
void Bunny::setAge(int  ages){    age = ages;}
void Bunny::setRad(bool isIll){   radioactive_mutant_vampire_bunny = isIll;}

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
