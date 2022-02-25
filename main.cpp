#include <iostream>
#include <iterator>
#include <vector>
#include <list>

size_t counting_vector_with_iterator(std::vector<int>& tvector);
size_t counting_list_with_iterator (std::list<std::vector<int>>& tlist);


int main()
{

    std::vector<int> test_vector {0, 1, 2, 3, 4 ,5};
    //std::vector<int>::iterator test_iterator = test_vector.begin();
    std::list<std::vector<int>> VectorList {{1,2,3},{4,5,6},{7,8,9,7}};
    
    std::cout <<"Counting elements in list of vectors "<< counting_list_with_iterator(VectorList) << std::endl;
    //std::cout <<"Count in vector "<< counting_vector_with_iterator(VectorList) << std::endl;

    return 0;
}

//not optimized. Used copying mechanism
size_t counting_list_with_iterator (std::list<std::vector<int>>& tlist)
{
    std::list<std::vector<int>>::iterator literator = tlist.begin();
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

