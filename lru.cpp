#include <iomanip>
#include <iostream>
#include <algorithm>

#include "lru.hpp"

/**
 * Removes the specified key from the LRU cache.
 *
 * @param key the key to be removed from the cache
 *
 * @return false if the key was not found in the cache
 *
 * @throws None
 */
bool LruCache::Remove(std::string key)
{
    cache.remove(key);
    return false;
}

/**
 * Adds a key to the LRU cache.
 *
 * @param key the key to be added to the cache
 *
 * @return true if the key was successfully added, false otherwise
 *
 * @throws None
 */
bool LruCache::Add(std::string key)
{
    // check if key exists in cache
    //  if so, bring it to the front of the list
    auto it = std::find(cache.begin(), cache.end(), key);
    if (it != cache.end())
    {
        cache.remove(key);
        cache.push_front(key);
        return true;
    }

    // check if cache is full
    if (cache.size() == max_cache_size)
    {
        cache.pop_back();
    }
    cache.push_front(key);
    return true;
}

/**
 * Prints the contents of the LRU cache.
 *
 * @throws None
 */
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

/**
 * Constructor for the LRU cache. Sets the maximum cache size.
 *
 * @throws None
 */
LruCache::LruCache(int cache_size)
{
    max_cache_size = cache_size;
}

/**
 * Destructor for the LRU cache.
 *
 * @throws None
 */
LruCache::~LruCache()
{
    cache.clear();
}
