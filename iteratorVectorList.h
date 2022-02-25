#include <vector>
#include <list>
#include <iterator>

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

    void append(std::vector<T>& vect)
    {
        data_.push_back(vect);
    }
    // метод, который будет использоваться для заполнения VectorList
    // гарантирует, что в списке не будет пустых массивов
  // template<class It>
 //   void append(It p, It q); определена снаружи
/*  {
        if (p != q)
            data_.push_back(VectT(p,q));
    } 
*/

    bool empty() const { return size() == 0; } 

    // определите метод size
 


    class const_iterator: std::iterator<std::bidirectional_iterator_tag,
                                                     T, 
                                                     size_t,
                                                     T*, 
                                                     T&>
    {

     
        public:
            //Constructor
            const_iterator()
            {

            }


            const_iterator begin() const { return 0;}
            const_iterator end() const {return 0; }
            
            private:
           // ListT::iterator lit;
            typename VectT::iterator vit;
            typename ListT::iterator lit;
            ListT* data_;

    };

       //метод size должен вычислять количество всех элементов типа T во ВСЕХ векторах!!
    size_t size() const 
    {
        size_t counter = 0;

        /*for (;it != this.end(); ++it)
        {++counter;}
    */
        return counter;
    }
   // определите const_iterator

     /*class const_iterator::std::iterator<std::bidirectional_iterator_tag>
    {
        public:
        const_iterator() = default;
    };
    */
/*
    // определите методы begin / end
    const_iterator begin() const { return ... ; }
    const_iterator end()   const { return ... ; }

    // определите const_reverse_iterator
    ... const_reverse_iterator ...

    // определите методы rbegin / rend
    const_reverse_iterator rbegin() const { return ... ;   }
    const_reverse_iterator rend()   const { return ... ; }
*/  void show_list_of_vectors ()
    {

    
    }
private:
    ListT data_;
};