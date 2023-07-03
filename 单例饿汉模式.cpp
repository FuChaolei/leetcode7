#include <bits/stdc++.h>
using namespace std;
class Hungry
{
public:
	static Hungry *getInstance()
	{
		return hungry;
	}

private:
	Hungry() {}
	static Hungry *hungry;
};
Hungry *Hungry::hungry = new Hungry;
int main()
{
	Hungry *a = Hungry::getInstance();
	Hungry *b = Hungry::getInstance();
	if (a == b)
	{
		cout << "A" << endl;
	}
	return 0;
}
