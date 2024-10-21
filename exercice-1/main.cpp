#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vector)
{
    os << '[';
    for ( const int i: vector )
        os << ' ' << i;
    os << " ]";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::list<int>& list)
{
    os << '[';
    for ( const int i: list )
        os << ' ' << i;
    os << " ]";
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::set<int>& set)
{
    os << '[';
    for ( const int i: set )
        os << ' ' << i;
    os << " ]";
    return os;
}


void VectorTest()
{
    std::cout << "Test Vector :" << std::endl;
    std::vector<int> numbers {5, 2, 9, 1, 5, 6};
    std::cout << numbers << std::endl;
    numbers.push_back(0);
    std::cout << numbers << std::endl;
    numbers.erase(numbers.begin());
    std::cout << numbers << std::endl;
    sort( numbers.begin(), numbers.end() );
    std::cout << numbers << std::endl;
}


void ListTest()
{
    std::cout << "Test List :" << std::endl;
    std::list<int> numbers {5, 2, 9, 1, 5, 6};
    std::cout << numbers << std::endl;
    numbers.push_back(0);
    std::cout << numbers << std::endl;
    numbers.erase(numbers.begin());
    std::cout << numbers << std::endl;
    // sort( numbers.begin(), numbers.end() );
    // std::cout << numbers << std::endl;
}


void SetTest()
{
    std::cout << "Test Set :" << std::endl;
    std::set<int> numbers {5, 2, 9, 1, 5, 6};
    std::cout << numbers << std::endl;
    numbers.insert(0);
    std::cout << numbers << std::endl;
    numbers.erase(numbers.begin());
    std::cout << numbers << std::endl;
}


int main()
{
    VectorTest();
    ListTest();
    SetTest();
    return 0;
}