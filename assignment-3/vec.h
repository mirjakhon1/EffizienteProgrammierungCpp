#ifndef VEC_H
#define VEC_H

#include "iostream"
#include <array>
#include <cstddef>
#include <cassert>
#include <concepts>
#include <numeric>
#include <cmath>

namespace my {

    // alternatively "IntOrFloat" in place of typename
    template<typename T, int N>
    requires std::floating_point<T> || std::integral<T>
    class Vec{
        
    public:
        // Contructors
        template<typename ... Args>
        Vec(const T& first, const Args& ... rest);
        Vec();

        // Operators
        T &operator[](int index);
        T operator[](int index) const;
        bool operator==(const Vec& other) const;
        bool operator!=(const Vec& other) const;
        Vec& operator+=(const Vec &other);
        Vec operator+(const Vec &other) const;
        Vec operator-() const;
        T* begin() { return data.begin();}
        T* end() { return data.end();}
        
        T length() const;
        

        // Friend function for dot product
        template<typename>
        friend T dot(const Vec& v1, const Vec& v2);

        template<typename U, int M>
        friend void vec_lengths(const std::vector<Vec<U, M>> &vec_list);

    private:
        std::array<T, N> data;
    };


    // Constructor definitions
    template<typename T, int N>
    requires std::floating_point<T> || std::integral<T>
    template<typename ...Args>
    Vec<T, N>::Vec(const T& first, const Args& ... rest)
    : data{{first, T(rest)...}}
    {
        static_assert(N == 1 + sizeof...(Args), "Wrong number of args!");
    }

    template<typename T, int N>
    requires std::floating_point<T> || std::integral<T>
    Vec<T, N>::Vec() {
        data.fill(0.0);
    }


    // Subscript operator
    template<typename T, int N>
    requires std::floating_point<T> || std::integral<T>
    T& Vec<T, N>::operator[](int index) {
        return data[index];
    }

    // Subscript operator for const
    template<typename T, int N>
    requires std::floating_point<T> || std::integral<T>
    T Vec<T, N>::operator[](int index) const {
        return data[index];
    }

    // Equality operator
    template<typename T, int N>
    requires std::floating_point<T> || std::integral<T>
    bool Vec<T, N>::operator==(const Vec& other) const {
        return std::equal(data.begin(), data.end(), other.data.begin());
    }

    // Inequality operator
    template<typename T, int N>
    requires std::floating_point<T> || std::integral<T>
    bool Vec<T, N>::operator!=(const Vec& other) const {
        return !(*this == other);
    }

    // += operator
    template<typename T, int N>
    requires std::floating_point<T> || std::integral<T>
    Vec<T, N>& Vec<T, N>::operator+=(const Vec &other) {
        std::transform(data.begin(), data.end(), other.data.begin(), data.begin(), [](T a, T b){ return a+b;});
        return *this;
    }

    // Add operator
    template<typename T, int N>
    requires std::floating_point<T> || std::integral<T>
    Vec<T, N> Vec<T, N>::operator+(const Vec &other) const {
        Vec tmpVec = *this;
        tmpVec += other;
        return tmpVec;
    }

    // Unary minus operator
    template<typename T, int N>
    requires std::floating_point<T> || std::integral<T>
    Vec<T, N> Vec<T, N>::operator-() const {
        Vec<T, N> result;
        std::transform(data.begin(), data.end(), result.data.begin(), [](T a){ return -a;});
        return result; 
    }

    // vector length calc
    template<typename T, int N>
    requires std::floating_point<T> || std::integral<T>
    T Vec<T, N>::length() const
    {
        T sum = std::accumulate(data.begin(), data.end(), T(0), 
                                [](T acc, T elem){ return acc + elem*elem;});
        return sqrt(sum);
    }

    // calc length of container of vectors
    template<typename T, int N>
    void vec_lengths(const std::vector<Vec<T, N>> &vec_list)
    {
        for(auto &container : vec_list)
        {
            std::cout << "Vector: ";
            std::for_each(container.data.begin(), container.data.end(), [](const T &elem){ std::cout << elem << " ";});
            std::cout << "Length: " << container.length() << std::endl;  // Access length() which must be const
        }
    }

    // Dot product 
    template<typename T, int N>
    requires std::floating_point<T> || std::integral<T>
    T dot(const Vec<T, N>& a, const Vec<T, N>& b) {
        T result = 0;
        for(int i = 0; i < N; i++)
        {
            result += (a[i] * b[i]);
        }
        return result;
    }

}



#endif
