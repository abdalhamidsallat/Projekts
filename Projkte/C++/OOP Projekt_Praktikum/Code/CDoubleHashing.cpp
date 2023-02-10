/*!\file CArray.hpp
 * \brief
 *
 *  Created on: 10.05.2019
 *      Author: Abd Alhamid
 */

#include "CDoubleHashing.hpp"

CDoubleHashing CDoubleHashing::m_instance;

CDoubleHashing::CDoubleHashing() {
	// TODO Auto-generated constructor stub

}

CDoubleHashing::~CDoubleHashing() {
	// TODO Auto-generated destructor stub
}

CDoubleHashing& CDoubleHashing::getInstance() {

	return m_instance;
}

unsigned int CDoubleHashing::hash (unsigned int I, unsigned int J, unsigned int dict_size, unsigned int attempt) {

	unsigned long I_l = static_cast<unsigned long> (I);
	unsigned long J_l = static_cast<unsigned long> (J);
	unsigned long hash_value = (I_l + J_l)*(I_l + J_l + 1)/2 + J_l;

	unsigned int h1 = hash_value % dict_size;
//	unsigned int h1 = hash_value;
	unsigned int h2 = 1+(hash_value % (dict_size - 2));
	unsigned int result = (h1 + attempt*h2) % dict_size;

    return result;
}


















