#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <stdio.h>

using namespace std;

class Solder
{
protected:
    int no;
    int lifeValue;
    string name;
public:
    static string weaponName[];
    string getSolderName(){
        return name;
    };
    int getLifeValue(){
        return lifeValue;
    };
    int getSolderNo(){
        return no;
    }
    virtual void description() = 0;
    Solder(int no_, int lifeValue_):no(no_), lifeValue(lifeValue_) {

    }
    ~Solder() {}
};

string Solder::weaponName[] = {"sword", "bomb", "arrow"};

class Dragon:public Solder {
private:
    int weapon;
    float morale;   
public:
    static int SolderCost;
    Dragon(int no_, int lifeValue_):Solder(no_ + 1, lifeValue_){
        weapon = Solder::no % 3;
        name = "dragon";
    }
    void updateMorale(int commanderLife){
        morale = (float)commanderLife / Dragon::SolderCost;
    }
    void description(){
        cout << "It has a " << weaponName[weapon] << ",and it's morale is ";
        printf("%.2f\n", morale);
    }
};
int Dragon::SolderCost;

class Ninja:public Solder {
private:
    int weapon1;
    int weapon2;
public:
    static int SolderCost;
    Ninja(int no_, int lifeValue_):Solder(no_ + 1, lifeValue_){
        weapon1 = Solder::no % 3;
        weapon2 = (Solder::no + 1) % 3;
        name = "ninja";
    }
    void description(){
        cout << "It has a " << weaponName[weapon1] << " and a " << weaponName[weapon2] << endl;
    }
};
int Ninja::SolderCost;

class Iceman:public Solder {
private:
    int weapon;
public:
    static int SolderCost;
    Iceman(int no_, int lifeValue_):Solder(no_ + 1, lifeValue_){
        weapon = Solder::no % 3;
        name = "iceman";
    }
    void description(){
        cout << "It has a " << weaponName[weapon] << endl;
    }
};
int Iceman::SolderCost;

class Lion:public Solder {
private:
    int loyalty;
public:
    static int SolderCost;
    Lion(int no_, int lifeValue_, int loyalty_):Solder(no_ + 1, lifeValue_), loyalty(loyalty_){
        name = "lion";        
    }
    void description(){
        cout << "It's loyalty is " << loyalty << endl;
    }
};
int Lion::SolderCost;

class Wolf:public Solder {
public:
    static int SolderCost;
    Wolf(int no_, int lifeValue_):Solder(no_ + 1, lifeValue_){
        name = "wolf";
    }
    void description(){
    } 
};
int Wolf::SolderCost;


class CommanderHouse
{
private:
    int totalLifeValue; // 生命元
    string* solderOrder;
    string commanderName;
    int size;
    int currentIndex;
    int solderNum;
    map<string, int> solderCountDic;
public:
    CommanderHouse(int totalLifeValue_, string *solderOrder_, int size_, string commanderName_):totalLifeValue(totalLifeValue_), 
    size(size_), commanderName(commanderName_){
        solderOrder = new string[5];
        for (size_t i = 0; i < size; i++)
        {
            solderOrder[i] = solderOrder_[i];
            solderCountDic[solderOrder[i]] = 0;
        }
        currentIndex = 0;
        solderNum = 0;
        
    }
    bool productNext(int flagIndex = -1);
    // ~CommanderHouse();

};

bool CommanderHouse::productNext(int flagIndex){
    Solder *solder = NULL;
    if(solderOrder[currentIndex].compare("dragon") == 0){
        if (totalLifeValue >= Dragon::SolderCost)
        {
            solder =  new Dragon(solderNum, Dragon::SolderCost);
            totalLifeValue -= Dragon::SolderCost;
            dynamic_cast<Dragon *>(solder)->updateMorale(totalLifeValue);
            solderCountDic[solderOrder[currentIndex]]++;
        }       
    }
    if (solderOrder[currentIndex].compare("ninja") == 0){
        if (totalLifeValue >= Ninja::SolderCost)
        {
            solder = new Ninja(solderNum, Ninja::SolderCost);
            totalLifeValue -= Ninja::SolderCost;
            solderCountDic[solderOrder[currentIndex]]++;
        }
    }
    if (solderOrder[currentIndex].compare("lion") == 0){
        if (totalLifeValue >= Lion::SolderCost)
        {
            solder = new Lion(solderNum, Lion::SolderCost, totalLifeValue - Lion::SolderCost);
            totalLifeValue -= Lion::SolderCost;
            solderCountDic[solderOrder[currentIndex]]++;
        } 
    }
    if (solderOrder[currentIndex].compare("wolf") == 0){
        if (totalLifeValue >= Wolf::SolderCost)
        {
            solder = new Wolf(solderNum, Wolf::SolderCost);
            totalLifeValue -= Wolf::SolderCost;
            solderCountDic[solderOrder[currentIndex]]++;
        }  
    }
    if (solderOrder[currentIndex].compare("iceman") == 0){
        if (totalLifeValue >= Iceman::SolderCost)
        {
            solder = new Iceman(solderNum, Iceman::SolderCost);
            totalLifeValue -= Iceman::SolderCost;
            solderCountDic[solderOrder[currentIndex]]++;
        } 
    } 

    if (solder != NULL)
    {
        cout.fill('0');
        cout.width(3);
        cout << solderNum << " " << commanderName << " " << solder->getSolderName() << " " << solder->getSolderNo() << " born with strength " << solder->getLifeValue()
             <<"," << solderCountDic[solderOrder[currentIndex]] << " " <<solder->getSolderName() <<" in " << commanderName << " headquarter" << endl;
        solder->description();
        currentIndex++;
        currentIndex = currentIndex % size;
        solderNum++;
        return true;
    } else {
        if (currentIndex == flagIndex)
        {
            cout.fill('0');
            cout.width(3);
            cout << solderNum  << " " << commanderName << " headquarter stops making warriors" << endl;
            return false;
        }
        if (flagIndex == -1)
        {
            flagIndex = currentIndex;   
        }
        currentIndex++;
        currentIndex = currentIndex % size;
        return this->productNext(flagIndex);
    }
    
}

int  main(int argc, char const *argv[])
{
    int caseNo;
    cin >> caseNo;
    int totalCaseNo = caseNo;
    while (caseNo--)
    {
        
        int totalLifeValue;
        cin >> totalLifeValue;
        // int dragon, ninja, iceman, lion, wolf;
        cin >> Dragon::SolderCost >> Ninja::SolderCost >> Iceman::SolderCost >> Lion::SolderCost >> Wolf::SolderCost;
        cout << "Case:" << totalCaseNo - caseNo << endl;
        string redorder[5] = {"iceman", "lion", "wolf", "ninja", "dragon"};
        CommanderHouse red(totalLifeValue, redorder, 5, "red");
        string blueorder[5] = {"lion", "dragon", "ninja", "iceman", "wolf"};
        CommanderHouse blue(totalLifeValue, blueorder, 5, "blue");
        int redres, blueres;
        while(1){
            redres = red.productNext();
            blueres = blue.productNext();
            if (!redres || !blueres)
            {
                break;
            }
        }
        if (redres)
        {
            while (red.productNext());
        }
        if (blueres)
        {
            while(blue.productNext());
        }
    }
    return 0;
}