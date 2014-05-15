#ifndef FARM_STAT_H
#define FARM_STAT_H

#include "bunny.h"
#include "farm.h"

class Farm_stat
{
    public:
        void showStat(Farm &);
        Bunny newBunny();
        void init(Farm &);
        void aging(); //starzenie sie krolikow
        void dying(); //umieranie krolikow

        Farm_stat(Farm&);
        Farm_stat();

        virtual ~Farm_stat();
    protected:
    private:
};

#endif // FARM_STAT_H
