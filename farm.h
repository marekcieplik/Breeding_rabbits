#ifndef FARM_H
#define FARM_H

#include <list>
#include "bunny.h"
class Farm
{
    public:
        void subBmales();
        void subBfemales();
        void subBmutant();

        void addBmales();
        void addBfemales();
        void addBmutant();

        int getBmales();
        int getBfemales();
        int getBmutant();

        void addBunny( Bunny bun);
        Farm();
        virtual ~Farm();
    protected:
    private:
        std::list<Bunny> population;
        int males, females , mutant;

};

#endif // FARM_H
