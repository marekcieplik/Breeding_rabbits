#ifndef BUNNY_H
#define BUNNY_H

class Bunny{
public:
    static const int maxAgeNormal = 10;
    static const int maxAgeMutant = 5;

    char getSex();
    int getAge();
    bool isRad();

    void setSex(char);
    void setAge(int);
    void setRad(bool);

    void addAge();

    Bunny(char a_char = 'M',int a_age = 0, bool a_rad = false);
    virtual ~Bunny();
    bool dyingBun(); //umieranie krolikow
    void agingBun(); //starzenie sie krolikow
protected:
private:
    char Sex; //: Male, Female (random at creation 50/50)
    int age;  //: 0-10 (years old)
    bool radioactive_mutant_vampire_bunny; //: true/false (decided at time of bunny creation 2% chance of true)


};

#endif // BUNNY_H
