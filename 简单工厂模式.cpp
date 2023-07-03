#include <bits/stdc++.h>
using namespace std;
class Abstractfruit
{
public:
    virtual void ShowName() = 0;
};
class Apple : public Abstractfruit
{
public:
    virtual void ShowName()
    {
        cout << "i`m apple" << endl;
    }
};
class Banana : public Abstractfruit
{
public:
    virtual void ShowName()
    {
        cout << "i`m banana" << endl;
    }
};
class Factory
{
public:
    static Abstractfruit *Createfruit(string s)
    {
        if (s == "apple")
        {
            return new Apple;
        }
        else if (s == "banana")
        {
            return new Banana;
        }
        return nullptr;
    }
};
int main()
{
    Factory *factory = new Factory;
    Abstractfruit *fruit = factory->Createfruit("apple");
    fruit->ShowName();
    delete fruit;
    delete factory;
    fruit = nullptr;
    factory = nullptr;
    return 0;
}
