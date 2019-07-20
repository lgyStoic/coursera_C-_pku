#include <iostream>
using namespace std;

class Solder
{
	string solderName;
	const int cost;
public:
	friend class CommandRoom;
	Solder();
	~Solder();
	
};


class CommandRoom
{
	string roomName;
	int totalLive;
	int currentCur;
	string [] produceOrder;
	int *costNumber;
	int soldekinds;
public:
	bool product();
	CommandRoom(int totalLive_, string roomName_, string * produceOrder_, int *costNumber_, int solerkinds_){
		soldekinds = solerkinds_;
		for (int i = 0; i < solerkinds_; ++i)
		{
			produceOrder[i] = produceOrder_[i];
			costNumber[i] = costNumber_[i];
		}

		roomName = roomName_;
		currentCur = 0;
		totalLive = totalLive_;
	}
	~CommandRoom();
};

bool CommandRoom::product(int currentTime) {
	// cout.fill('0');
	// cout.width(3);
	cout << currentTime << " ";
	cout << roomName << " ";
	int mark = currentCur;
	while(totalLive < costNumber[currentCur]){
		currentCur++;
		currentCur = currentCur % soldekinds;
		if (currentCur === mark)
		{
			cout << "headquarter stops making warriors" << endl;
			return -1;
		}	
	}
	totalLive -= solers[currentCur].cost;
	
	cout << solers[currentCur].solderNames <<  
	
}

int main(int argc, char const *argv[])
{
	int totalLine;
	cin >> totalLine;
	while(totalLine-- > 0){
		int totalLive;
		cin >> totalLive;
		int iceman,lion,wolf,ninja,dragon;
		cin >> iceman,lion,wolf,ninja,dragon;

	}
	return 0;
}