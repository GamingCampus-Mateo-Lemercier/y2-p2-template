#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <algorithm>



void Insert1M( std::vector<int>& vector )
{
    for ( int i = 0; i < 1000000; ++i )
        vector.push_back( i );
}

void Insert1M( std::list<int>& list )
{
    for ( int i = 0; i < 1000000; ++i )
        list.push_back( i );
}

void Insert1M( std::set<int>& set )
{
    for ( int i = 0; i < 1000000; ++i )
        set.insert( i );
}



int Find1M( const std::vector<int>& vector, const int element )
{
    const auto it = std::find( vector.begin(), vector.end(), element );
    return *it;
}

int Find1M( const std::list<int>& list, const int element )
{
    const auto it = std::find( list.begin(), list.end(), element );
    return *it;
}

int Find1M( const std::set<int>& set, const int element )
{
    const auto it = std::find( set.begin(), set.end(), element );
    return *it;
}



void Suppression1M( std::vector<int>& vector )
{
    for ( auto it = vector.begin(); it != vector.end(); ++it )
        vector.erase( it );
}

void Suppression1M( std::list<int>& list )
{
    for ( auto it = list.begin(); it != list.end(); ++it )
        list.erase( it );
}

void Suppression1M( std::set<int>& set )
{
    for ( auto it = set.begin(); it != set.end(); ++it )
        set.erase( it );
}



int main()
{
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::high_resolution_clock::now();
    std::vector<int> vector;
    Insert1M( vector );
    Find1M( vector, 500000 );
    Suppression1M( vector );
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << duration.count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::list<int> list;
    Insert1M( list );
    Find1M( list, 500000 );
    Suppression1M( list );
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << duration.count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::set<int> set;
    Insert1M( set );
    Find1M( set, 500000 );
    Suppression1M( set );
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << duration.count() << std::endl;

    return 0;
}