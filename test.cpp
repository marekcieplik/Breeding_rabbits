#include "gmock/gmock.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>
#include "farm_stat.h"
#include "farm.h"
//#include "D:\\kuzniacpp\\Code_Blocks_Files\\kp\\Rabbits\\bunny.h"

using namespace testing;

class TestBunny : public Test{
public:
    TestBunny() : b2('F', 0, true), b3('F',0,false) {}
protected:
    Bunny b1;
    Bunny b2;
    Bunny b3;
};
//constructor Bunny();
TEST_F(TestBunny, BunnyDefaultConstructor){
       ASSERT_THAT(b1.getSex(), AnyOf('M','F'));
       ASSERT_THAT(b1.getAge(), Eq(0));
       ASSERT_THAT(b1.isRad(),AnyOf(true, false));
}
//addOneYear();
TEST_F(TestBunny,AgingOneTwoYears){
    b1.addOneYear();
    ASSERT_THAT(b1.getAge(),Eq(1));
    b1.addOneYear();
    ASSERT_THAT(b1.getAge(),Eq(2));
}
//hasMaxAge();
TEST_F(TestBunny,BunnyDying){
    for (int i = 0; i < Bunny::maxAgeNormal; i++)
        b1.addOneYear();
    ASSERT_THAT(b1.hasMaxAge(),Eq(true));
}
//reproductive();
TEST_F(TestBunny,BunnyIsReproductive){
	b3.addOneYear();
	b3.addOneYear();
	ASSERT_THAT(b3.reproductive(),Eq(true));
	
    for (int i = 2; i < Bunny::maxAgeNormal; i++)
        b3.addOneYear();
    ASSERT_THAT(b3.reproductive(),Eq(true));
}
////////////////////////////////////////////////////////////////////////
class TestFarm : public Test{
public:
    TestFarm() : f1(5), f2(2), f0(0,false),
    	bunnyMaleWell('M',0,false), bunnyFemaleWell('F',0,false),
    	bunnyMaleX('M',0,true), bunnyFemaleX('F',0,true),
    	bunnyU0F('U',0,false)
     {
        strInit = "M";
    }
    std::string strInit;
protected:
    Farm f1,f2,f0;
    Bunny b1, bunnyMaleWell, bunnyFemaleWell,bunnyMaleX, bunnyFemaleX,bunnyU0F;
};
//constructor Bunny();
TEST_F(TestFarm, RandomingNewBunny){
    ASSERT_THAT(b1.getSex(), AnyOf('M','F'));
    ASSERT_THAT(b1.getAge(), AnyOf(Ge(0), Lt(10)));
    ASSERT_THAT(b1.isRad(), AnyOf(true, false));
}

TEST_F(TestFarm, AddNewBunny){
    ASSERT_THAT(f0.getFarmQuantity(), Eq(0));
    ASSERT_THAT(f0.getBmales(),   Eq(0));
    ASSERT_THAT(f0.getBfemales(), Eq(0));
    ASSERT_THAT(f0.getBmutant(),  Eq(0));

    ASSERT_THAT(f0.addBunny(b1),Eq(true));
    ASSERT_THAT(f0.getFarmQuantity(), Eq(1));

    f0.popBunnyFront();
    ASSERT_THAT(f0.getFarmQuantity(), Eq(0));
}

TEST_F(TestFarm, NotAddBunny){
    ASSERT_THAT(f0.getFarmQuantity(), Eq(0));
    ASSERT_THAT(f0.addBunny(bunnyU0F),Eq(false));
    ASSERT_THAT(f0.getFarmQuantity(), Eq(0));
}

TEST_F(TestFarm, AddAndSubBunnyMaleWell){

    ASSERT_THAT(f0.getFarmQuantity(), Eq(0));
    ASSERT_THAT(f0.getBmales(),   Eq(0));
    ASSERT_THAT(f0.getBfemales(), Eq(0));
    ASSERT_THAT(f0.getBmutant(),  Eq(0));

    ASSERT_THAT(f0.addBunny(bunnyMaleWell),Eq(true));

    ASSERT_THAT(f0.getFarmQuantity(), Eq(1));
    ASSERT_THAT(f0.getBmales(),   Eq(1));
    ASSERT_THAT(f0.getBfemales(), Eq(0));
    ASSERT_THAT(f0.getBmutant(),  Eq(0));

    f0.popBunnyFront();
    
    ASSERT_THAT(f0.getFarmQuantity(), Eq(0));
    ASSERT_THAT(f0.getBmales(),   Eq(0));
    ASSERT_THAT(f0.getBfemales(), Eq(0));
    ASSERT_THAT(f0.getBmutant(),  Eq(0));
}

TEST_F(TestFarm, AddAndSubBunnyMaleX){
    ASSERT_THAT(f0.getFarmQuantity(), Eq(0));
    ASSERT_THAT(f0.getBmales(), 	Eq(0));
    ASSERT_THAT(f0.getBfemales(), 	Eq(0));
    ASSERT_THAT(f0.getBmutant(), 	Eq(0));

    ASSERT_THAT(f0.addBunny(bunnyMaleX),Eq(true));

    ASSERT_THAT(f0.getFarmQuantity(), Eq(1));
    ASSERT_THAT(f0.getBmales(),   Eq(0));
    ASSERT_THAT(f0.getBfemales(), Eq(0));
    ASSERT_THAT(f0.getBmutant(),  Eq(1));

    f0.popBunnyFront();
    ASSERT_THAT(f0.getFarmQuantity(), Eq(0));
    ASSERT_THAT(f0.getBmales(),   Eq(0));
    ASSERT_THAT(f0.getBfemales(), Eq(0));
    ASSERT_THAT(f0.getBmutant(),  Eq(0));
}

TEST_F(TestFarm, AddAndSubBunnyFemaleWell){
    ASSERT_THAT(f0.getFarmQuantity(), Eq(0));
    ASSERT_THAT(f0.getBmales(),   Eq(0));
    ASSERT_THAT(f0.getBfemales(), Eq(0));
    ASSERT_THAT(f0.getBmutant(),  Eq(0));

    ASSERT_THAT(f0.addBunny(bunnyFemaleWell),Eq(true));

    ASSERT_THAT(f0.getFarmQuantity(), Eq(1));
    ASSERT_THAT(f0.getBmales(),   Eq(0));
    ASSERT_THAT(f0.getBfemales(), Eq(1));
    ASSERT_THAT(f0.getBmutant(),  Eq(0));

    f0.popBunnyFront();
    ASSERT_THAT(f0.getFarmQuantity(), Eq(0));
    ASSERT_THAT(f0.getBmales(),   Eq(0));
    ASSERT_THAT(f0.getBfemales(), Eq(0));
    ASSERT_THAT(f0.getBmutant(),  Eq(0));
}

TEST_F(TestFarm, AddAndSubBunnyFemaleX){
    ASSERT_THAT(f0.getFarmQuantity(), Eq(0));
    ASSERT_THAT(f0.getBmales(),   Eq(0));
    ASSERT_THAT(f0.getBfemales(), Eq(0));
    ASSERT_THAT(f0.getBmutant(),  Eq(0));

    ASSERT_THAT(f0.addBunny(bunnyFemaleX),Eq(true));

    ASSERT_THAT(f0.getFarmQuantity(), Eq(1 ));
    ASSERT_THAT(f0.getBmales(),   Eq(0));
    ASSERT_THAT(f0.getBfemales(), Eq(0));
    ASSERT_THAT(f0.getBmutant(),  Eq(1));

    f0.popBunnyFront();
    
    ASSERT_THAT(f0.getFarmQuantity(), Eq(0));
    ASSERT_THAT(f0.getBmales(),   Eq(0));
    ASSERT_THAT(f0.getBfemales(), Eq(0));
    ASSERT_THAT(f0.getBmutant(),  Eq(0));
}

TEST_F(TestFarm, IsNotEmpty){
    ASSERT_THAT(f1.getFarmQuantity(), Ne(0));
    ASSERT_THAT(f1.getBmales()+f1.getBfemales()+f1.getBmutant(), Eq(5));
}

TEST_F(TestFarm, IsEmpty){
    ASSERT_THAT(f0.getFarmQuantity(), Eq(0));
    ASSERT_THAT(f0.getBmales(), Eq(0));
    ASSERT_THAT(f0.getBfemales(), Eq(0));
    ASSERT_THAT(f0.getBmutant(), Eq(0));
}

TEST_F(TestFarm, HasFiveBunnys){
    ASSERT_THAT(f1.getFarmQuantity(), Eq(5));
}

TEST_F(TestFarm, HasTwoBunnys){
    ASSERT_THAT(f2.getFarmQuantity(), Eq(2));
}

TEST_F(TestFarm, InitOneBunnyMore){
    ASSERT_THAT(f2.getFarmQuantity(), Eq(2));
    ASSERT_THAT(f2.init(1), AnyOf(StrEq("M"), StrEq("F"), StrEq("X") ));
    ASSERT_THAT(f2.getFarmQuantity(), Eq(3));
    }

TEST_F(TestFarm, InitZeroBunnyMore){
    ASSERT_THAT(f2.getFarmQuantity(), Eq(2));
    ASSERT_THAT(f2.init(0), StrEq(""));
    ASSERT_THAT(f2.getFarmQuantity(), Eq(2));
    }

TEST_F(TestFarm, InitMinusOneBunnyMore){
    ASSERT_THAT(f2.getFarmQuantity(), Eq(2));
    ASSERT_THAT(f2.init(-1), StrEq(""));
    ASSERT_THAT(f2.getFarmQuantity(), Eq(2));
    }

TEST_F(TestFarm, AddOneBunnyMore){
    ASSERT_THAT(f1.getFarmQuantity(), Eq(5));

    Bunny bA('A',0,false);
    Bunny b10('M',10,false);
    Bunny bunIllog('X',0,false);

    ASSERT_THAT(f1.addBunny(bA), Eq(false));
    ASSERT_THAT(f1.addBunny(b10), Eq(false));
    ASSERT_THAT(f1.addBunny(bunIllog), Eq(false));
    
    f1.init(1);
    
    ASSERT_THAT(f1.getFarmQuantity(), Eq(6));
    
    
}


TEST_F(TestFarm, AgingTwoYears){
	
    ASSERT_THAT(false, Eq(true));
}

bool Rabbits_test_FarmAgingTwoYears(){
    const int bunnysAtStart = 5;
    Farm farm1(bunnysAtStart);
    farm1.addOneYear();
    farm1.addOneYear();
    int sumBunnysAge = 0;
    for (int i = 0; i < farm1.getFarmQuantity();i++)    {
        sumBunnysAge += farm1.getBunnyFront().getAge();
        farm1.moveBunnyToEndOfList();
    }
    if ( 10 == sumBunnysAge){
          return true;
    }else return false;
}

bool Rabbits_test_FarmFirstGenerationDies(){
    Farm farm1;
    Farm_stat sf1(farm1);
    for (int i = 0 ; i < 13 ; i++)    {
        farm1.addOneYear();
        farm1.checkBunnysAge();
    }
    if ( 0 == farm1.getFarmQuantity()){
          return true;
    }else return false;
}

bool Rabbits_test_FarmNewGenerationBornOneBunny(){
    Farm farm1;
    int sizePopulationBefor = farm1.getFarmQuantity();
    farm1.init(1);
    int sizePopulationAfter = farm1.getFarmQuantity();

    if ( 1 == sizePopulationAfter - sizePopulationBefor){
          return true;
    }else return false;
}

bool Rabbits_test_FarmNewGenerationLogicalInit(){
    bool logicalInit = true;
    const int bunnysAtStart = 1000;
    Farm farm1(bunnysAtStart);
    std::cout << std::endl << std::endl;
    for (int i = 0 ; i < bunnysAtStart; i++){
        if ( 'X' == farm1.getBunnyFront().getSex() ){
            if ( true == farm1.getBunnyFront().isRad())
                logicalInit = logicalInit && true;
            else
                logicalInit = logicalInit && false;
            std::cout
            << farm1.getBunnyFront().getSex()
            << farm1.getBunnyFront().isRad();

        }
        farm1.moveBunnyToEndOfList();
    }
   return logicalInit;
}



bool Rabbits_test_FarmIsReproductivePar(){
    bool isMRep = false;
    bool isFRep = false;
    const int bunnysAtStart = 5;
    Farm farm1(bunnysAtStart);
    farm1.addOneYear();
    farm1.init(bunnysAtStart);
  //  farm1.agingFarm();
    farm1.init(bunnysAtStart);
    farm1.addOneYear();

    std::cout << std::endl << std::endl << farm1.getFarmQuantity();
    for (int i = 0 ; i < farm1.getFarmQuantity(); i++){
        if ( 'M' == farm1.getBunnyFront().getSex() &&
                2 == farm1.getBunnyFront().getAge())
                    isMRep = true;
        if ( 'F' == farm1.getBunnyFront().getSex() &&
                2 == farm1.getBunnyFront().getAge())
                    isFRep = true;
        farm1.moveBunnyToEndOfList();
    }
   return (isMRep&&isFRep );
}

//TODO class TestFarmRandomness{}
bool Rabbits_test_FarmInitThreeDifferent(){
    Farm farm1;
    Farm farm2;
    Farm farm3;
    if ( farm1.getBfemales() != farm2.getBfemales()||
         farm1.getBfemales() != farm3.getBfemales() ){
          return true;
    }else return false;
}

bool Rabbits_test_FarmInitProcMutant(int howManyProc, int howManyFarms)
//FIXME It should made 100 farms - I don't know how? And sum up mutant. And calculate the percentage of mutants on the farm.
{

/*    int ills = 0;
    int population = 0;

    std::vector <Farm> farms(howManyFarms);
    for (int i = 0 ; i < howManyFarms; i++){
        Farm f1;
        farms[i] = f1;
    }

    std::vector <Farm_stat> statFarms;
    for (int i = 0 ; i < howManyFarms; i++){
        statFarms.push_back(farms[i]);
        ills += farms[i].getBmutant();
        population += farms[i].getBmutant();
        population += farms[i].getBmales();
        population += farms[i].getBfemales();
    }
    std::cout << ills << " * 100.0 / " << population << std::endl;
    if ( (ills * 100.0 / population) <= howManyProc)
        return true;
*/
    return false;
}
