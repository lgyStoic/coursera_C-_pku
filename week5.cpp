#include<iostream>
#include<string>

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
    Static int SolderCost;
    Dragon(int no_, int lifeValue_):Solder(no_, lifeValue_){
        weapon = Solder::no % 3;
    }

};

class ninja:public Solder {
private:
    int weapon1;
    int weapon2;
public:
    Static int SolderCost;
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
    Static int SolderCost;
    iceman(int no_, int lifeValue_):Solder(no_, lifeValue_){
        weapon = Solder::no % 3;
    }
};

class lion:public Solder {
private:
    int loyalty;
public:

    Static int SolderCost;
    lion(int no_, int lifeValue_, int loyalty_):Solder(no_, lifeValue_), loyalty(loyalty_){
        
    }
};

class wolf:public Solder {
public:
    Static int SolderCost;
    wolf(int no_, int lifeValue_):Solder(no_, lifeValue_){
        
    }

};


class CommanderHouse
{
private:
    int totalLifeValue;
    string solderOrder[5];
    int currentIndex;
public:
    CommanderHouse(int totalLifeValue_, string[] solderOrder_):totalLifeValue(totalLifeValue_), solderOrder(solderOrder_){
        currentIndex = 0;
    }

    ~CommanderHouse();

};

int int main(int argc, char const *argv[])
{
    
    return 0;
}