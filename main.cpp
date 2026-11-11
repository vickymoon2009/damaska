#include <iostream>
#include <string>
using namespace std;

class Animal 
{
protected:
    string species;  
    double weight;  
    string color;   
    string food;    
public:
    Animal() 
    {
        species = "Unknown";
        weight = 0.0;
        color = "Unknown";
        food = "Unknown";
    }

    Animal(string sp, double wg, string col, string fd)
    {
        species = sp;
        weight = wg;
        color = col;
        food = fd;
    }

    void Init()
    {
        cout << "Введите вид: ";
        cin >> species;
        cout << "Введите вес: ";
        cin >> weight;
        cout << "Введите цвет: ";
        cin >> color;
        cout << "Введите еду: ";
        cin >> food;
    }

    virtual void Print()
    {
        cout << "Species: " << species << endl;
        cout << "Weight: " << weight << endl;
        cout << "Color: " << color << endl;
        cout << "Food: " << food << endl;
    }

    virtual ~Animal() {}
};

class Parrot : public Animal 
{
    string name;
    bool talking;   // True - yes, False - NO
    double wingspan;
public:
    Parrot() : Animal() 
    {
        name = "No name";
        talking = false;
        wingspan = 0.0;
    }

    Parrot(string sp, double wg, string col, string fd, string nm, bool talk, double wing) 
        : Animal(sp, wg, col, fd)
    {
        name = nm;
        talking = talk;
        wingspan = wing;
    }

    void Init()
    {
        Animal::Init(); 

        cout << "Введите кличку: ";
        cin >> name;
        cout << "Умеет говорить? (1 - да, 0 - нет): ";
        cin >> talking;
        cout << "Размах крыльев (см): ";
        cin >> wingspan;
    }

    void Print() override
    {
        Animal::Print(); 
        cout << "Name: " << name << endl;
        cout << "Talking: " << (talking ? "Yes" : "No") << endl;
        cout << "Wingspan: " << wingspan << " cm" << endl << endl;
    }
};

int main()
{
    Parrot myParrot;
    
    cout << "Введите данные попугая:\n";
    myParrot.Init(); 

    cout << "\nРезультат:\n";
    myParrot.Print(); 

    return 0;
}
