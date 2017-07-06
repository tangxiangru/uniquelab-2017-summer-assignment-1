#include <backlinked_priority_queque.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<pq_key_t, pq_index_t> data_t;

void main()
{
    vector<data_t> vec;
    vec.push_back(make_pair(45, -10));
    vec.push_back(make_pair(1, -10));
    vec.push_back(make_pair(34, -10));
    vec.push_back(make_pair(26, -10));
    vec.push_back(make_pair(11, -10));
    vec.push_back(make_pair(20, -10));
    vec.push_back(make_pair(7, -10));
    vec.push_back(make_pair(5, -10));
    
    
    backlinked_priority_queue pq(pq_min);
    for (int i=0;i<vec.size();i++)
    {
        pq.push(vec[i].first, (void*)(&vec[i]), &vec[i].second);
    }
    
    data_t* a = (data_t*)pq.top();
    cout << "pq.top() is " << a->first << "; index = " << a->second << endl;
    data_t* b = (data_t*)pq.pop();
    cout << "pq.pop() is " << b->first << "; index = " << b->second << endl;
    data_t* c = (data_t*)pq.erase(vec[3].second);
    cout << "pq.erase(vec[3].second) is " << c->first << "; index = " << c->second << endl;
}
