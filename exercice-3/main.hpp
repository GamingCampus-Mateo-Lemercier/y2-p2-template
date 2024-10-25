#pragma once
#include <vector>
#include <list>


// Question 1
template <typename T>
T& SmallestValue( const T array[], const int size )
{
    T& smallest = array[0];
    for ( int i = 1; i < size; ++i )
        if ( array[i] < smallest )
            smallest = array[i];
    return smallest;
}


// Question 2
template <typename T>
int AddElement( std::vector<T>& vector, T& element )
{
    vector.push_back( element );
    return  vector.size();
}


// Question 3
template <typename T>
T Sum( const std::list<T>& list )
{
    T sum = 0;
    for ( const T& element : list )
        sum += element;
    return sum;
}


// Question 4
template <typename T>
double Average( const T array[], const int size )
{
    T sum = 0;
    for ( int i = 0; i < size; i++ )
        sum += array[i];
    return static_cast<double>( sum ) / size;
}

template <>
double Average( const int array[], const int size )
{
    double sum = 0;
    for ( int i = 0; i < size; i++ )
        sum += array[i];
    return sum / size;
}