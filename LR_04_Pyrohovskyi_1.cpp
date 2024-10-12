#include <iostream>
using namespace std;

class B1 {
protected:
    string Name;
    int Number;
public:
    B1()
    {
        cout << "B1 empty constructor\n";
    }
    B1(string name, int number)
    {
        Name = name;
        Number = number;
        cout << "B1 constructor\n";
    }
    const void B1Show()
    {
        cout << Name << " number " << Number << " is object of class B1, has no parents.\n";
    }
    virtual ~B1()
    {
        cout << "B1 Destructor\n\n";
    }
};

class D1 : public B1 {
protected:
    double Salary;
public:
    D1(string name, int number, double salary) : B1(name, number)
    {
        Salary = salary;
        cout << "D1 constructor\n";
    }
    const void D1Show()
    {
        cout << Name << " number " << Number << " has salary " << Salary << " and is object of class D1, which is inherited from B1.\n";
    }
    string GetName() const {
        return Name;
    }
    int GetNumber() const {
        return Number;
    }
    ~D1()
    {
        cout << "D1 Destructor\n\n";
    }
};

class D2 : private B1 {
protected:
    double Pension;
public:
    D2(string name, int number, double pension) : B1(name, number)
    {
        Pension = pension;
        cout << "D2 constructor\n";
    }
    const void D2Show()
    {
        cout << Name << " number " << Number << " has pension " << Pension << " and is object of class D2, which is inherited from B1.\n";
    }
    ~D2()
    {
        cout << "D2 Destructor\n\n";
    }
};

class B2 {
protected:
    double Scholarship;
public:
    B2(double scholarship)
    {
        Scholarship = scholarship;
        cout << "B2 constructor\n";
    }
    const void B2Show()
    {
        cout << "Student has scholarship " << Scholarship << " and is object of class B2, has no parents.\n";
    }
    ~B2()
    {
        cout << "B2 Destructor\n\n";
    }
};

class D4 : public D1, public D2, public B2 {
protected:
    double Tax;
public:
    D4(string name, int number, double salary, double pension, double scholarship, double tax)
        : D1(name, number, salary), D2(name, number, pension), B2(scholarship)
    {
        Tax = tax;
        cout << "D4 constructor\n";
    }
    const void D4Show()
    {
        cout << GetName() << " number " << GetNumber() << " has salary " << Salary << ", pension " << Pension
            << ", scholarship " << Scholarship << " , paying tax " << Tax << " and is object of class D2, which is inherited from D1, D2, B2.\n";
    }
    ~D4()
    {
        cout << "D4 Destructor\n";
    }
};

int main() 
{
    string name = "Andrii"; int number = 69; double salary = 52690, pension=2280, scolarship=1488, tax=666;
    B1 objB1(name, number);
    cout << endl;
    B2 objB2(scolarship);
    cout << endl;
    D1 objD1(name, number, salary);
    cout << endl;
    D2 objD2(name, number, pension);
    cout << endl;
    D4 objD4(name, number, salary, pension, scolarship, tax);
    cout << endl;
    objB1.B1Show();
    objB2.B2Show();
    objD1.D1Show();
    objD2.D2Show();
    objD4.D4Show();
    return 0;
}
