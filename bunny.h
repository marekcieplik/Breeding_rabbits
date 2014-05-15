#ifndef BUNNY_H
#define BUNNY_H

class Bunny
{
    public:
        char getSex();
        int getAge();
        bool getRad();

        void setSex(char);
        void setAge(int);
        void setRad(bool);

        Bunny(char,int,bool);
        virtual ~Bunny();
    protected:
    private:
        char Sex; //: Male, Female (random at creation 50/50)
        int age;  //: 0-10 (years old)
        bool radioactive_mutant_vampire_bunny; //: true/false (decided at time of bunny creation 2% chance of true)

};

#endif // BUNNY_H
