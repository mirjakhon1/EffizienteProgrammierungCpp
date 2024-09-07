#ifndef VEC_H
#define VEC_H

#include <array>
#include <cstddef>
#include <cassert>
#include <concepts>

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
        
        // Friend function for dot product
        template<typename>
        friend T dot(const Vec& v1, const Vec& v2);

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
        for(int i = 0; i < N; i++)
        {
            if(data[i] != other.data[i])
            {
                return false;
            }
        }
        return true;
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
        for(int i = 0; i < N; i++)
        {
            data[i] += other.data[i];
        }
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
        for(int i = 0; i < N; i++)
        {
            result[i] = -data[i];
        }
        return result; 
    }

    // Dot product 
    template<typename T, int N>
    requires std::floating_point<T> || std::integral<T>
    float dot(const Vec<T, N>& a, const Vec<T, N>& b) {
        T result = 0;
        for(int i = 0; i < N; i++)
        {
            result += (a[i] * b[i]);
        }
        return result;
    }

}



#endif
