#ifndef FARM_STAT_H
#define FARM_STAT_H


#include "farm.h"

class Farm_stat
{
    public:
        void showStat(Farm &);
        void showBeginStat(Farm &);
        void showAgesOfBunnys(Farm &);
        Farm_stat(Farm&);
        Farm_stat();

        virtual ~Farm_stat();
    protected:
    private:
};

#endif // FARM_STAT_H
