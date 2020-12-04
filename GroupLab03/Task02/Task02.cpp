#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Ship
{
protected:
    string Name;
    string Date;

public:
    Ship()
    {
        Name = "Jack";
        Date = "1/24/2020";
    }
    void set_Name(string x) {Name=x;}
    void set_Date(string x) {Date=x;}
    virtual void print()
    {
        cout << "Name: " << Name << "\nDate: " << Date << endl;
    }
};
class CruiseShip : public Ship
{
    int Max_Passengers;

public:
    CruiseShip() {int x=rand()%10;set_Max_Passengers(x); };
    void set_Max_Passengers(int x) {Max_Passengers=x;}
    void print()
    {
        cout << "Name: " << Name << "\nMax Passengers: " << Max_Passengers << endl;
    }
};
class CargoShip : public Ship
{
    int Cargo_Capacity;

public:
    CargoShip() {int x=rand()%100;set_Cargo_Capacity(x);}
    void set_Cargo_Capacity(int x) {Cargo_Capacity=x;}
    void print()
    {
        cout << "Name: " << Name << "\nCargo Capacity: " << Cargo_Capacity << endl;
    }
};
int main()
{
    srand(time(NULL));
    Ship **x = new Ship*[10];
    int randnum=rand()%10;
    for(int i=0;i<10;i++){
        if(randnum<3)    x[i]=new CargoShip;
        else if(randnum <6) x[i] = new CruiseShip;
        else x[i]=new Ship;
        randnum=rand()%10;
    }
    for(int i=0;i<10;i++){  x[i]->print(); cout<<endl;}
    x[0]->set_Name("Jackal");
    x[0]->print();
    //x[0]->set_Cargo_Capacity(5);
}