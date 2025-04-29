#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {
	
template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(vector<T>& v)
{
    const unsigned int n = v.size();

    for(unsigned int i = 0; i < n - 1; i++)
    {
        for(unsigned int j = i + 1; j < n; j++)
        {
            if(v[j] < v[i])
            {
	            T tmp = v[j];
	            v[j] = v[i];
	            v[i] = tmp;
            };
        }
    }
}

template<Sortable T>
void Heapify(vector<T>& v, unsigned int n, unsigned int i)
{
	unsigned int larg = i;
	unsigned int vSx = 2 * i + 1;
	unsigned int vDx = 2 * i + 2;
	
	if(vSx < n && v[vSx] > v[larg])
	{
		larg = vSx;
	}
	
	if(vDx < n && v[vDx] > v[larg])
	{
		larg = vDx;
	}
	
	if(larg != i)
	{
		T tmp = v[i];
		v[i] = v[larg];
		v[larg] = tmp;
		
		Heapify(v, n, larg);
	}

}

template<Sortable T>
void HeapSort(vector<T>& v)
{

    const unsigned int n = v.size();

    for(int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(v, n, i);
    }
    
    for(int i = n - 1; i > 0; i--)
    {
	    T tmp = v[0];
        v[0] = v[i];
        v[i] = tmp;
        
        Heapify(v, i, 0);
    }

}

}


