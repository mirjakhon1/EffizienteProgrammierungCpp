#include "iostream"
#include <vector>
#include "vec.h"
#include <random>
#include <algorithm>

using namespace std;
using namespace my;

template<typename T, int N>
void stable_partition_algo(vector<Vec<T, N>> &source_container);

template<typename T, int N>
void sort_algo(vector<Vec<T, N>> &source_container);

template<typename T, int N>
void transform_algo(std::vector<Vec<T, N>> &source_container);

template<typename T, int N>
Vec<T, N> findMedian(const vector<Vec<T, N>> &source_container);

template<typename T, int N>
void copy_if_algo(const vector<Vec<T, N>> &source_container);

template<typename T, int N>
void remove_if_erase_algo(vector<Vec<T, N>> &source_container);

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0, 100.0);

    vector<Vec<float, 4>> containers(10);
    
    for(auto &item : containers)
    {
        std::generate(item.begin(), item.end(), [&gen, &dis](){return dis(gen);});
    }
    vec_lengths(containers);
    
    // transform_algo<float, 4>(containers);

    // stable_partition_algo<float, 4>(containers);

    // sort_algo<float, 4>(containers);

    // auto med_vec = findMedian<float, 4>(containers);
    // cout << "Vector length of median element: " << med_vec.length() << endl;

    // copy_if_algo<float, 4>(containers);
    remove_if_erase_algo<float, 4>(containers);

    return 0;
}

// add 1.0 to each element
template<typename T, int N>
void transform_algo(std::vector<Vec<T, N>> &source_container)
{
    std::cout << "Transform algorithm: " << std::endl;
    for(auto &item : source_container)
    {
        std::transform(item.begin(), item.end(), item.begin(), [](T elem){return elem + 1.0;});
    }
    vec_lengths(source_container);
}


// sort Vectors: vector length < 90 go to the beginning
template<typename T, int N>
void stable_partition_algo(vector<Vec<T, N>> &source_container)
{
    std::cout << "Stable partition algorithm: " << std::endl;
    std::stable_partition(source_container.begin(), source_container.end(), [](Vec<T, N> elem){return elem.length() < 90.0;});
    vec_lengths(source_container);
}

// sort by vector length
template<typename T, int N>
void sort_algo(vector<Vec<T, N>> &source_container)
{
    std::cout << "Sorting algorithm: " << std::endl;
    std::sort(source_container.begin(), source_container.end(), 
        [](const Vec<T, N> &elem1, const Vec<T, N> &elem2){return elem1.length() < elem2.length();});
    vec_lengths(source_container);
}

// finds the median vector in a sorted container of vectors 
template<typename T, int N>
Vec<T, N> findMedian(const vector<Vec<T, N>> &source_container)
{
    size_t size = source_container.size();
    if(size % 2 == 0)
    {
        // even number of elements
        return source_container[(size / 2) - 1];
    }
    else{
        // odd number of elements
        return source_container[floor(size / 2)];
    }
}

// copy into new container if vector length < 80
// trick: std::back_inserter to allocate and assign to a new container
template<typename T, int N>
void copy_if_algo(const vector<Vec<T, N>> &source_container)
{
    std::cout << "Copy_if algorithm: " << std::endl;
    std::vector<Vec<T, N>> copied_cont;
    std::copy_if(source_container.begin(), source_container.end(), std::back_inserter(copied_cont), 
                [](const Vec<T, N> &elem){ return elem.length() < 80;});
    vec_lengths(copied_cont);
}

// remove_if vectors with length > 90
template<typename T, int N>
void remove_if_erase_algo(vector<Vec<T, N>> &source_container)
{
    vec_lengths(source_container);
    std::cout << "after remove:" << std::endl;

    auto new_end = std::remove_if(source_container.begin(), source_container.end(),
                [](const Vec<T, N> &elem){return (elem.length() > 90) && elem.length() < 120 ;});
    source_container.erase(new_end, source_container.end());
    vec_lengths(source_container);
}
