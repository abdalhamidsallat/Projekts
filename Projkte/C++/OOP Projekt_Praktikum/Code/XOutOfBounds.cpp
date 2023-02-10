/*!\file XOutOfBounds.cpp
 * \brief
 *
 *  Created on: 07.05.2019
 *      Author: Abd Alhamid Sallat
 */
#include "XOutOfBounds.hpp"

XOutOfBounds::XOutOfBounds(const char * msg) :m_msg(msg) {

}

XOutOfBounds::~XOutOfBounds() throw () {

}

const char * XOutOfBounds::what() const throw () {
        return m_msg.c_str();
}


