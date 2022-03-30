#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include "iteratorVectorList.h"

size_t counting_vector_with_iterator(std::vector<int>& tvector);
size_t counting_list_with_iterator (const std::list<std::vector<int>>& tlist);
void show_vector(std::vector<int>& vect);

int main()
{
    VectorList<int> vl;
    VectorList<int>* vlp = &vl;
    std::vector<int> vect {1,2,4};
    vl.append(vect);
    std::vector<int> vect2 {5,6,7};
    vl.append(vect2);
    show_vector(vect);
    show_vector(vect2);

    VectorList<int>::const_iterator ITER = vl.begin();
    VectorList<int> vl2;
    //vl2 = ITER;
    size_t counter = vl.size();   
    std::cout << counter << std::endl; 
    return 0;
}

//not optimized. Used copying mechanism
size_t counting_list_with_iterator (const std::list<std::vector<int>>& tlist)
{
    std::list<std::vector<int>>::const_iterator literator = tlist.begin();
    size_t counter = 0;
    std::vector<int> vec = tlist.front();
    std::vector<int>::iterator viterator = vec.begin();
    //std::vector<int>::iterator viterator = tlist.front();

    for (;literator != tlist.end(); ++literator)
    {      
        vec = *(literator);
        viterator = vec.begin();
       
        for(;viterator != vec.end(); ++viterator)
        {
            ++counter;
        }
    }
    
    return counter;
}

//not used. test purpose
size_t counting_vector_with_iterator(std::vector<int>& tvector)
{
    std::vector<int>::iterator titerator = tvector.begin();
    size_t counter = 0;

    for (;titerator != tvector.end(); ++titerator)
    {
        ++counter;
    }

    return counter;
}

void show_vector(std::vector<int>& vect)
{
    std::vector<int>::iterator vecit = vect.begin();
    for (; vecit != vect.end(); ++vecit)
    {
        std::cout << *vecit << std::endl;
    }
}



