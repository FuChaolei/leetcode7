#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
using namespace std;
mutex mu;
queue<int> q;
void func(int n)
{
    mu.lock();
    if (!q.empty())
    {
        cout << q.front() << " " << n << endl;
        q.pop();
    }
    mu.unlock();
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        q.emplace(i);
    }
    for (int i = 0; i < 5; i++)
    {
        thread t(func, i);
        t.join();
    }
    return 0;
}
