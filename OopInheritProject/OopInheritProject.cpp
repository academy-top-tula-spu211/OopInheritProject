#include <iostream>

class Base
{
protected:
    int value;
public:
    Base() : value{ 0 }
    {
        std::cout << "Base construct\n";
    }

    Base(int value) : value{ value }
    {
        std::cout << "Base construct\n";
    }

    ~Base()
    {
        std::cout << "Base destruct\n";
    }

    int& Value() { return value; }

    virtual void Print()
    {
        std::cout << "Value = " << value << "\n";
    }
};

class Derived : public Base
{
    int count;
public:
    Derived() : Base(0), count{ 0 }
    {
        std::cout << "Derived construct\n";
    }
    Derived(int value, int count) : Base(value), count{ count }
    {
        std::cout << "Derived construct\n";
    }


    int& Count() { return count; }

    void Print() override
    {
        //std::cout << "Value = " << value << "\n";
        Base::Print();
        std::cout << "Count = " << count << "\n";
    }

    ~Derived()
    {
        std::cout << "Derived destruct\n";
    }
};

void InheriteExample()
{
    Base* base = new Base(50);

    Derived* derived = new Derived();
    derived->Value() = 100;
    derived->Count() = 200;
    //derived.Print();

    /*Base* basePtr = base;
    basePtr->Print();

    basePtr = derived;
    basePtr->Print();*/

    Base* bases[4];
    bases[0] = base;
    bases[1] = derived;
    bases[2] = new Derived(1, 2);
    bases[3] = new Base(300);

    for (int i = 0; i < 4; i++)
        bases[i]->Print();



    /*delete derived;
    delete base;*/
}

class A
{
public:
    virtual void Method() { std::cout << "class A\n"; }
};

class B : public A
{
public:
    void Method() override { std::cout << "class B\n"; }
};

class C : public B
{
public:
    void Method() override { std::cout << "class C\n"; }
};

class D : public C
{
public:
    
};

class E : public D
{
public:
    void Method() override { std::cout << "class E\n"; }
};



int main()
{
    A* obj = new E();
    obj->Method();
}
