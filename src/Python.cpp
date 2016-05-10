/*
 * Python.cpp
 *
 *  Created on: 10 May 2016
 *      Author: Jordan Barraclough
 */

#include "Python.h"

usng namespace boost::python;

Python::Python() {

}

Python::~Python() {
}

BOOST_PYTHON_MODULE(glex){

	class_<GameWorld>("GameWorld").def("bindingtest",&GameWorld::bindingtest)

}
