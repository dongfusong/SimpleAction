/*
 * Common.h
 *
 *  Created on: 2014Äê11ÔÂ7ÈÕ
 *      Author: Thoughtworks
 */

#ifndef COMMON_H_
#define COMMON_H_
#include "Role.h"

#define ABSTRACT(...) virtual __VA_ARGS__ = 0
#define OVERRIDE virtual
typedef int Status;


#define ROLE(name) get##name()
#define USE_ROLE(name) virtual name& get##name() = 0;

#define SUCCESS 1
#define CONTINUE 0
#define UNKNOWN_EVENT 2
#define FATAL_ERR 3

#define DEF_ROLE(role) class role : public Role<role>

#endif /* COMMON_H_ */
