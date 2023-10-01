#include <iomanip>
#include <iostream>
#include <algorithm>

#include "lru.hpp"

bool LruCache::Remove(std::string key)
{
    cache.remove(key);
    return false;
}

bool LruCache::Add(std::string key)
{
    //check if key exists in cache
    // if so, bring it to the front of the list
    auto it = std::find(cache.begin(), cache.end(), key);    
    if (it != cache.end())
    {
        cache.remove(key);
        cache.push_front(key);
        return true;
    }

    //check if cache is full
    if (cache.size() == max_cache_size)
    {
        cache.pop_back();
    }
    cache.push_front(key);
    return true;
}

void LruCache::Print()
{
    std::cout << std::endl
              << "Begin cache print" << std::endl;
    std::cout << "Cache size: " << cache.size() << std::endl;
    for (auto it = cache.begin(); it != cache.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    std::cout << std::endl
              << "End cache print" << std::endl
              << std::endl;
}

LruCache::LruCache(int cache_size)
{
    max_cache_size = cache_size;
}

LruCache::~LruCache()
{
    cache.clear();
}
