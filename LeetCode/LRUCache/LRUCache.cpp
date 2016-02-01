#include <iostream>
#include <set>
#include <map>

using namespace std;


map<int, int> tmpmap;
std::set<int> recentvec;
int mapsize;
void LRUCache(int capacity) {
    mapsize = capacity;
    recentvec = std::set<int>(capacity, 0);
}

int get(int key) {
    if (recentvec[key%mapsize] == 0)
    {
        return -1;
    }
    recentvec[key%mapsize]++;
    return tmpmap[key];
}

void set(int key, int value) {
    if (tmpmap.size() < mapsize)
    {
        tmpmap[key] = value;
        recentvec[key%mapsize]++;
    }
    else
    {

    }
}

int main()
{

    return 0;
}