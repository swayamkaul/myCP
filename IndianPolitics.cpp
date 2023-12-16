// C++ program to demonstrate implementation
// of Inheritance

#include <bits/stdc++.h>
using namespace std;
class Consituency{
    public:
    string name;
    int area;
};
//Base class
class MPS
{
	public:
    string vehicle;
    string winnig_constituency;
    int spending_limit;

    MPS(){
        spending_limit=50000;
    }
};

// Sub class inheriting from Base Class(Parent)
class Ministers : public MPS
{
    private:
    string car;
    string driverCar;
	public:
	
    Ministers(){
        spending_limit=70000;
    }
};

class PM : public Ministers
{
	public:
	string aircraft;
    string driverAircraft;
    string car[5];
    string driverCar;

    void giveArrestPermission(Ministers m){

    }
    void giveArrestPermission(MPS m){
        
    }

    PM(){
        spending_limit=170000;
    }
};

class Commissioner{
    public:
    bool TakePermission(Ministers m,PM p){
        return true;
    }
    void Arrest(Ministers m,PM p){
        if(TakePermission(m,p)){
            //Arrest
        }
    }

};
//main function
int main()
{
	

		
		return 0;
}
