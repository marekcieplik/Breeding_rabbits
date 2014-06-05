#ifndef BUNNY_H
#define BUNNY_H

class Bunny{
public:
    static const int maxAgeNormal = 10;
    static const int maxAgeMutant = 50;
    static const int reproductiveAge = 2;

    Bunny();
    Bunny(char _sex, int _age, bool _rad);
    virtual ~Bunny();

    bool addOneYear(); //added one year to ages of bunny. starzenie sie krolikow
    bool hasMaxAge(); //is true if Ages equal to maxAge. umieranie krolikow
    bool reproductive();

    int getAge();
    char getSex();//is equal 'M' , 'F'
    bool isRad();//gives true if bunny is radioactive
    void setSex(char);
    void setAge(int);
    void setRad(bool);

protected:
private:
    char Sex; //: Male, Female (random at creation 50/50)
    int Age;  //: 0-10 (years old)
    bool Radioactive_mutant_vampire_bunny; //: true/false (decided at time of bunny creation 2% chance of true)
};
#endif // BUNNY_H
