#if !(defined(__LRU_HPP__))
#define __LRU_HPP__

#include <list>
#include <string>

class LruCache
{
protected:
    int max_cache_size;
    std::list<std::string> cache;
    bool Remove(std::string key);

public:
    bool Add(std::string key);
    void Print();
    LruCache(int cache_size);
    ~LruCache();
};

#endif //__LRU_HPP__