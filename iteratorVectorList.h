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
    size_t size() const 
    {
        return 0;
    }

    // определите const_iterator 
    //создаем класс внутри класса. Класс итератор будем наследовать от стандартного класса итераторов в std;
    //элементарным элементом на который будет указывать класс будет являться элемент вектор T.
    class const_iterator :std::iterator<std::bidirectional_iterator_tag,
                                                     T, 
                                                     size_t,
                                                     T*, 
                                                     T&> 
    {   
        
        
        friend class VectorList;
        public:
        const_iterator() = default;
        const_iterator(const const_iterator& other): p(other.p)
        {}
        bool operator!=(const_iterator const& other) const
        {
            return p != other.p;
        }
        bool operator==(const_iterator const& other) const
        {   
            return p == other.p;
        } //need for BOOST_FOREACH

        T operator*() const
        {
            return *p;
        }
        const_iterator& operator++()
        {
            ++p;
            return *this;
        }
        private:
        const_iterator(T*p):p(p)
        {
           
        }
        const_iterator(ListT* data):p(p)
        {
           
        }

        T* p;
        std::vector<T>* vect;
        std::list<std::vector<T>>* listvect;
        

    
    };

    // определите методы begin / end
    const_iterator begin() const { return const_iterator(&(this->data_)); }
   // const_iterator end()   const { return ... ; }

    // определите const_reverse_iterator
   // class const_reverse_iterator ...

    // определите методы rbegin / rend
   // const_reverse_iterator rbegin() const { return ... ;   }
   // const_reverse_iterator rend()   const { return ... ; }*/

    private:
    ListT data_;
};