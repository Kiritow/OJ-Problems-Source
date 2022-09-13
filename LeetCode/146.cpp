#include <cstdlib>
#include <cstring>
#include <unordered_map>
// DON'T USE STL LIST!! IT IS VERY SLOW!!!
struct MyList
{
    int key, val;
    MyList* pre;
    MyList* next;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        maxsz = capacity;
        sz = 0;
        head = NULL;
        end = NULL;
    }

    int get(int key) {
        std::unordered_map<int, MyList*>::iterator iter = xp.find(key);
        if (iter != xp.end())
        {
            MyList* tnode = iter->second;
            if (tnode != head)
            {
                tnode->pre->next = tnode->next;
                if (tnode->next)
                {
                    tnode->next->pre = tnode->pre;
                }
                else
                {
                    end = tnode->pre;
                }
                tnode->next = head;
                tnode->pre = NULL;
                head->pre = tnode;
                head = tnode;
            }
            
            return head->val;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value) {
        if (get(key) != -1)
        {
            head->val = value;
        }
        else
        {
            MyList* xnode = (MyList*)malloc(sizeof(MyList));
            xp.insert(std::make_pair(key, xnode));
            xnode->key = key;
            xnode->val = value;
            xnode->pre = NULL;
            xnode->next = head;
            if(head) head->pre = xnode;
            head = xnode;
            if (end == NULL) end = head;

            if (maxsz - sz)
            {
                sz++;
            }
            else
            {
                // keep sz 
                xp.erase(end->key);
                end = end->pre;
                free(end->next);
                end->next = NULL;
            }
        }
    }
private:
    int maxsz;
    int sz;
    
    std::unordered_map<int, MyList*> xp;
    MyList* head;
    MyList* end;
};
