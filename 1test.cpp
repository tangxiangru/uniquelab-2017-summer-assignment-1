
#include <backlinked_priority_queque.cpp>
#include <algorithm>
using namespace std;

backlinked_priority_queue::backlinked_priority_queue(pq_order_t order = pq_max)
{
    pq_order = order;
}

backlinked_priority_queue::~backlinked_priority_queue()
{
    
}

bool backlinked_priority_queue::compare_record(pq_index_t id1, pq_index_t id2)
{
    if (pq_order == pq_max)
        return records[id1].key >= records[id2].key;
    else
        return records[id1].key < records[id2].key;
}

void backlinked_priority_queue::swap_record(pq_index_t id1, pq_index_t id2)
{
    pq_record tmp = records[id1];
    
    //update the backlink
    records[id1] = records[id2];
    *(records[id1].index_backlink) = id1;
    
    //update the backlink
    records[id2] = tmp;
    *(records[id2].index_backlink) = id2;
}

void backlinked_priority_queue::fix_up(pq_index_t index)
{
    pq_index_t parent = (index-1) / 2;
    if (index != 0 && compare_record(index, parent))
    {
        swap_record(index, parent);
        fix_up(parent);
    }
}

void backlinked_priority_queue::fix_down(pq_index_t index)
{
    //Compare the root with its children; if they are on the correct order, stop;
    //otherwise, swap the root with one of its child, and return to the previous step.
    pq_index_t left = 2*index+1;
    pq_index_t right = 2*index+2;
    pq_index_t largest = index;
    if (left<records.size() && compare_record(left, index)) 		largest = left;
    if (right<records.size() && compare_record(right, index)) 		largest = right;
    
    if (largest != index)
    {
        swap_record(index, largest);
        fix_down(largest);
    }
}

bool backlinked_priority_queue::empty()
{
    return records.empty();
}

size_t backlinked_priority_queue::size()
{
    return records.size();
}

pq_record backlinked_priority_queue::top_rec()
{
    if (empty())
        return pq_record(0, NULL, NULL);
    else
        return records[0];
}

pq_data_t backlinked_priority_queue::top()
{
    if (empty())
        return NULL;
    else
        return records[0].data;
}

void backlinked_priority_queue::push_rec(pq_record &rec)
{
    size_t id = records.size();
    records.push_back(rec);
    *(records[id].index_backlink) = id;
    fix_up(id);
}

void backlinked_priority_queue::push(pq_key_t key, pq_data_t data, pq_index_t *id_backlink)
{
    pq_record new_rec(key, data, id_backlink);
    push_rec(new_rec);
}

pq_record backlinked_priority_queue::pop_rec()
{
    if (empty())
        return pq_record(0, NULL, NULL);
    else
    {
        pq_record tmp = records[0];
        
        //delete the top element
        //index=-1 means that this element is not in the priority queue
        *(records[0].index_backlink) = -1;
        
        //Replace the root of the heap with the last element on the last level.
        records[0] = records[records.size()-1];
        *(records[0].index_backlink) = 0;
        
        //reduce the records vector by 1
        records.pop_back();
        
        //fix down
        fix_down(0);
        
        return tmp;
    }
}

pq_data_t backlinked_priority_queue::pop()
{
    pq_record tmp = pop_rec();
    return tmp.data;
}


pq_record backlinked_priority_queue::erase_rec(int index)
{
    if (empty())
        return pq_record(0, NULL, NULL);
    else
    {
        pq_record tmp = records[index];
        
        //delete the specified element
        //index=-1 means that this element is not in the priority queue
        *(records[index].index_backlink) = -1;
        
        //Fill the hole with the last element on the last level.
        records[index] = records[records.size()-1];
        *(records[index].index_backlink) = index;
        
        //reduce the records vector by 1
        records.pop_back();
        
        //fix down and up
        fix_down(index);
        fix_up(index);
        
        return tmp;
    }
}

pq_data_t backlinked_priority_queue::erase(int index)
{
    pq_record tmp = erase_rec(index);
    return tmp.data;
}
