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

    // метод, который будет использоваться для заполнения VectorList
    // гарантирует, что в списке не будет пустых массивов
    
    template<class It>
    void append(It p, It q); // определена снаружи

    /*void append(std::vector<T> p)
    {
        data_.push_back(p);
    } */
 

    bool empty() const { return size() == 0; } 

    // определите метод size
    size_t size() const 
    {
        size_t counter = 0;
        const_iterator it = this->begin();
        const_iterator it2 = this->end();
        for (;it!= it2; ++it)
        {
            counter++;
        }
        return counter+1;
    }

    /* функция для вывода на экран всех чисел*/
    friend std::ostream &operator<<(std::ostream &os, VectorList const &m) { 
        const_iterator it = m.begin();
        for (; it != m.end(); ++it)
        {
             os << *it;
             os << " ";

        }
        return os;
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
            return (itlt != other.itlt || itv != other.itv);
           
        }
        bool operator==(const_iterator const& other) const
        {   
            return  (p == other.p && itlt == other.itlt && itv == other.itv);
        } //need for BOOST_FOREACH

        T const operator*() const
        {
            return *itv;
        }
        const_iterator& operator++()
        {
            if(++itv != (*itlt).end())
            {
               
            }
            else if (++itlt != p->data_.end() )
            {
                itv = (*itlt).begin();
            }
            return *this;
        }


        private:
        const_iterator(T*p):p(p)
        {
           
        }

        const_iterator(const VectorList* special, int i)
        {
            if ( i == 1)
            {  
                p = special;
                itlt = special->data_.begin();
                itv = (special->data_.front()).begin();
            }
            else 
            {
                p = special;
                itlt = --(special->data_.end());
                itv = --((special->data_.back()).end());
            }

        }

        typename ListT::const_iterator itlt;
        typename VectT::const_iterator itv;
        VectorList const *p;
    
    };

    // определите методы begin / end
    const_iterator begin() const { return const_iterator(this,1); }
    const_iterator end()   const { return const_iterator(this,2) ; }

    // определите const_reverse_iterator
   // class const_reverse_iterator ...
    class const_reverse_iterator:std::iterator<std::bidirectional_iterator_tag,
                                                     T, 
                                                     size_t,
                                                     T*, 
                                                     T&> 
    {   
        
        
        friend class VectorList;
        public:
        const_reverse_iterator() = default;
        const_reverse_iterator(const const_reverse_iterator& other): p(other.p)
        {}
        bool operator!=(const_reverse_iterator const& other) const
        {
            return (itlt != other.itlt || itv != other.itv || p != other.p);
           
        }
        bool operator==(const_reverse_iterator const& other) const
        {   
            return (p == other.p && itlt == other.itlt && itv == other.itv );
        } //need for BOOST_FOREACH

        VectorList const operator*() const
        {
            return *p;
        }
        const_reverse_iterator& operator++()
        {
            if(++itv != (*itlt).rend())
            {
               
            }
            else if (++itlt != p->data_.rend() )
            {
                itv = (*itlt).rbegin();
            }
            return *this;
        }


        private:


        const_reverse_iterator(const VectorList* special, int i)
        {
            if ( i == 1)
            {  
                p = special;
                itlt = special->data_.rbegin();
                itv = (special->data_.back()).rbegin();
            }
            else 
            {
                p = special;
                itlt = --(special->data_.rend());
                itv = --((special->data_.back()).rend());
            }

        }

        typename ListT::const_reverse_iterator itlt;
        typename VectT::const_reverse_iterator itv;
        VectorList const *p;
    
    };


    // определите методы rbegin / rend
   // const_reverse_iterator rbegin() const { return ... ;   }
   // const_reverse_iterator rend()   const { return ... ; }*/
    const_reverse_iterator rbegin() const { return const_reverse_iterator(this, 1); }
    const_reverse_iterator rend()   const { return const_reverse_iterator(this, 2) ; }

    private:
    ListT data_;
};