#include <iostream>
#include <vector>
#include <string>


#include "lru.hpp"

int main(void)
{

    const int max_cache_size = 5;

    std::cout << max_cache_size << std::endl;

    LruCache lru_cache(max_cache_size);

    std::vector<std::string> elements = {"Allan", "Brian", "Charlie", "Deborah", "Eli", "Frank", "Deborah"};

    lru_cache.Print();

    for (auto it = elements.begin(); it != elements.end(); ++it)
    {
        lru_cache.Add(*it);
        lru_cache.Print();
    }

    return 0;
}
