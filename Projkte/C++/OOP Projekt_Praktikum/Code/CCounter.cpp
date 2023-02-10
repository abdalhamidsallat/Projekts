/*!\file CArray.hpp
 * \brief
 *
 *  Created on: 07.05.2019
 *      Author: Abd Alhamid
 */

#include "CCounter.hpp"

CCounter::CCounter() : m_value(0) {
}

CCounter::~CCounter() {
}

int CCounter::getValue() const {
	return m_value;
}

void CCounter::setValue(int value) {
	m_value = value;
}

void CCounter::count() {
	m_value +=1;
}

bool CCounter::operator<(const CCounter& other) const {
	return m_value < other.m_value;
}

bool CCounter::operator>(const CCounter& other) const {
	return m_value > other.m_value;
}
