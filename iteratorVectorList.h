#include <vector>
#include <list>

template<class T>
class VectorList
{
private:
    using VectT  = std::vector<T>;
    using ListT = std::list<VectT>;

public:
    using value_type = T;

    VectorList() = default;
    VectorList(VectorList const &) = default;
    VectorList(VectorList &&) = default;

    VectorList & operator=(VectorList &&)     = default;
    VectorList & operator=(VectorList const &) = default;

    // метод, который будет использоваться для заполнения VectorList
    // гарантирует, что в списке не будет пустых массивов
    template<class It>
    void append(It p, It q); // определена снаружи
/*  {
        if (p != q)
            data_.push_back(VectT(p,q));
    } 
*/

    bool empty() const { return size() == 0; } 

    // определите метод size
    //метод size должен вычислять количество всех элементов типа T во ВСЕХ векторах!!
    size_t size() const 
    {
    
    }

    // определите const_iterator
    ... const_iterator ... 

    // определите методы begin / end
    const_iterator begin() const { return ... ; }
    const_iterator end()   const { return ... ; }

    // определите const_reverse_iterator
    ... const_reverse_iterator ...

    // определите методы rbegin / rend
    const_reverse_iterator rbegin() const { return ... ;   }
    const_reverse_iterator rend()   const { return ... ; }

private:
    ListT data_;
};