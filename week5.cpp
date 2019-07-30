#include<iostream>

using namespace std;


class Solder
{
protected:
    int no;
    int lifeValue;
public:
    Solder(int no_, int lifeValue_):no(no_), lifeValue(lifeValue_) {

    }
    ~Solder() {}
};

class Dragon:public Solder {
private:
    int weapon;
    float morale;
public:
    Dragon(int no_, int lifeValue_):Solder(no_, lifeValue_){
        weapon = Solder::no % 3;
    }

};

class ninja:public Solder {
private:
    int weapon1;
    int weapon2;

public:
    ninja(int no_, int lifeValue_):Solder(no_, lifeValue_){
        weapon1 = Solder::no % 3;
        weapon2 = (Solder::no + 1) % 3;
    }
};

class iceman:public Solder {
private:
    int weapon;
    float morale;
public:
    iceman(int no_, int lifeValue_):Solder(no_, lifeValue_){
        weapon = Solder::no % 3;
    }
};

class lion:public Solder {
private:
    int loyalty;
public:
    lion(int no_, int lifeValue_):Solder(no_, lifeValue_){
        
    }
};

class wolf:public Solder {

};