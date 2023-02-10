/*!\file CArray.hpp
 * \brief
 *
 *      Author: Abd Alhamid
 */

#pragma once
#include "XOutOfBounds.hpp"
#include <iostream>

template <typename T, unsigned int N> class CArray { // generische Programmierung

public:
	CArray();
	~CArray();
	T& operator[](unsigned int index); //kopierkontructur wenn mv sind zeiger oder etwas speziell
private:
	T* m_entries;

};

template <typename T, unsigned int N> CArray<T, N>::CArray(): m_entries(new T[N]) {

}

template <typename T, unsigned int N> CArray<T, N>::~CArray() {
	if(m_entries != NULL) {
	delete [] m_entries;
	m_entries = 0;
	}
}

template <typename T, unsigned int N> T& CArray<T, N>::operator[] (unsigned int index){

	if(index >= N){
        //std::cout<< "ja";
		throw XOutOfBounds("Index zu gross");

	}

	return m_entries[index];
}












