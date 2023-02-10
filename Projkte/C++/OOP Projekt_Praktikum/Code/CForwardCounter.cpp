/*!\file CArray.hpp
 * \brief
 *
 *  Created on: 07.05.2019
 *      Author: Abd Alhamid
 */
/*
#include "CForwardCounter.hpp"

CForwardCounter::CForwardCounter() : CCounter() {
	// TODO Auto-generated constructor stub

}

CForwardCounter::~CForwardCounter() {
	// TODO Auto-generated destructor stub
}

void count () {
	this->CCounter::count();
}*/
#include "CForwardCounter.hpp"

CForwardCounter::CForwardCounter() : CCounter()
{
}

CForwardCounter::~CForwardCounter() {
	// TODO Auto-generated destructor stub
}

void CForwardCounter::count()
{
	this->CCounter::count();
	/* int a = getValue();
	 * setValue(a + 1);
	 */
}











