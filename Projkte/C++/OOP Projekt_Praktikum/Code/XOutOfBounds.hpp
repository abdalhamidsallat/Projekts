/*!\file XOutOfBounds.hpp
 * \brief
 *
 *  Created on: 07.05.2019
 *      Author: omar1
 */
#include <exception>
#include <string>

#ifndef XOUTOFBOUNDS_HPP_
#define XOUTOFBOUNDS_HPP_

class XOutOfBounds : public std::exception {

public:
	XOutOfBounds(const char * msg);
	virtual ~XOutOfBounds() throw();
	const char * what() const throw();
private:
	std:: string m_msg;

};



#endif /* XOUTOFBOUNDS_HPP_ */
