/*!\file CArray.hpp
 * \brief
 *
 *  Created on: 10.05.2019
 *      Author: Abd Alhamid
 */

#pragma once

/*!
 *
 */
class CDoubleHashing {
public:
	virtual ~CDoubleHashing();
	static CDoubleHashing& getInstance();
	unsigned int hash (unsigned int I, unsigned int J, unsigned int dict_size, unsigned int attempt);

private:
	CDoubleHashing ();
	CDoubleHashing (CDoubleHashing& other);
	CDoubleHashing operator=(CDoubleHashing& other);
	static CDoubleHashing m_instance;

};
 /* CDOUBLEHASHING_HPP_ */
