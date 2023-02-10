/*!\file CArray.hpp
 * \brief
 *
 *  Created on: 08.05.2019
 *      Author: Abd Alhamid
 */

#include "CKnot.hpp"

CKnot::CKnot() : m_parent(-2) {  // m_parent(0)
	// TODO Auto-generated constructor stub

}

CKnot::~CKnot() {
	// TODO Auto-generated destructor stub
}

int CKnot::getParent() const{
	return m_parent;
}

void CKnot::setParent(int parent){
	m_parent = parent;
}









