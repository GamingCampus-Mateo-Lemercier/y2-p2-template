#pragma once


template <typename T>
double calculStatistique( const T array[], const int size )
{
    T sum = 0;
    for ( int i = 0; i < size; ++i )
        sum += array[i];
    return static_cast<double>( sum ) / size;
}

template <>
double calculStatistique( const float array[], const int size )
{
    float sum = 0;
    for ( int i = 0; i < size; ++i )
        sum += array[i];
    const float average = sum / size;

    sum = 0;
    for ( int i = 0; i < size; ++i )
        sum += ( array[i] - average ) * ( array[i] - average );
    return static_cast<double>( sum ) / size;
}