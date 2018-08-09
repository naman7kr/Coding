#include <iostream>
#include <queue>
using namespace std;
 

 
int main()
{
    priority_queue<int,vector<int>, greater<int> > pq;
 
    pq.push(3);
    pq.push(5);
    pq.push(1);
    pq.push(8);
    while ( !pq.empty() )
    {
        cout << pq.top() << endl;
        pq.pop();
    }
    cin.get();
}