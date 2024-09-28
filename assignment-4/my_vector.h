#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include "iostream"


namespace my
{
    template<typename ValueT>
    class my_vector
    {
    public:
        // default constructor
        my_vector()
        : data_(nullptr), capacity_(0), size_(0)
        {   
        };

        // constructor size
        my_vector(const size_t size)
        : data_(nullptr), capacity_(size), size_(0)
        {
            if(size > 0)
            {
                this->data_ = new ValueT[size];
            }
        }

        // constructor size + value
        my_vector(const size_t size, const ValueT val)
        : data_(nullptr), capacity_(size), size_(size)
        {
            if(size > 0)
            {
                this->data_ = new ValueT[size];
                for (int i = 0; i < size; i++)
                {
                    this->data_[i] = val;
                }
            }
        }

        // Delete copy constructor and copy assignment operator
        my_vector(my_vector<ValueT> const &) = delete;
        my_vector<ValueT>& operator=(my_vector<ValueT> const &) = delete;

        ~my_vector()
        {
            if(data_ != nullptr)
            {
                delete[] data_;
            }
        };

        ValueT& operator[](const int index) const
        {   
            return data_[index];   
        }
        
        // ValueT operator[](const int index) const
        // {   
        //     return data_[index];   
        // }

        // is vector empty?
        bool empty() const
        {
            if(data_ == nullptr) return true;
            else return false;
        }

        // size of the vector
        size_t size() const
        {
            return this->size_;
        }

        size_t capacity() const
        {
            return this->capacity_;
        }

        // clear array
        void clear()
        {
            if(data_ != nullptr)
            {
                delete[] data_;
                data_ = nullptr;
                capacity_ = 0;
            }
        }

        void push_back(const ValueT& element)
        {
            if(this->size_ == this->capacity_)
            {
                this->capacity_ *= 2;
                ValueT *new_data = new ValueT[this->capacity_];
                // copy old data to new array
                for(int i = 0; i < this->size_; i++)
                {
                    new_data[i] = this->data_[i];
                }
                // add the new element 
                new_data[this->size_] = element;

                delete[] this->data_;

                // copy pointer of new array
                this->data_ = new_data;
            }else{
                // simply add the element if enough space
                data_[this->size_] = element;
            }
            
            this->size_++;
        } // push_back() end 

        // remove last element
        void pop_back()
        {
            if(this->size_ > 0) this->size_--;
        }

        ValueT at(const int index) const
        {
            if(index >= this->size_)
            {
                throw std::out_of_range("Index out of range!");
            }else{
                return this->data_[index];
            }
        }

        void print() const
        {
            for (int i = 0; i < this->size_; ++i)
            {
                std::cout << data_[i] << " || ";
            }
            std::cout << std::endl;
        }


    private:
        ValueT *data_;
        size_t capacity_;
        size_t size_;
    }; // class my_vector
} // namespace my

#endif

