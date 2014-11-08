/*
 * SequentialSchedActionHelper.h
 *
 *  Created on: 2014Äê11ÔÂ8ÈÕ
 *      Author: Thoughtworks
 */

#ifndef SEQUENTIALSCHEDACTIONHELPER_H_
#define SEQUENTIALSCHEDACTIONHELPER_H_

#include "SchedAction/SequentialSchedAction.h"
#include "Common/RepeatMacros.h"
#include <iostream>
using namespace std;

////////////////////////////////////
#define TYPENAME_ACTION(n) typename ACTION##n = DummySchedAction
#define END_TYPENAME_ACTION(n) ,TYPENAME_ACTION(n)
#define DEFAULT_TEMPLATES(n) SIMPLE_REPEAT(TYPENAME_ACTION, END_TYPENAME_ACTION, n)

////////////////////////////////////
#define ACTION(n) ACTION##n
#define END_ACTION(n) ,ACTION##n
#define ACTIONS(n) SIMPLE_REPEAT(ACTION, END_ACTION, n)

////////////////////////////////////
#define PUSHBACKACTION(n) pushBackAction(&action##n);
#define PUSHBACKACTIONS(n) SIMPLE_REPEAT(PUSHBACKACTION, PUSHBACKACTION, n)

////////////////////////////////////
#define ACTION_DECL(n) 	ACTION##n action##n;
#define ACTION_DECLS(n) SIMPLE_REPEAT(ACTION_DECL, ACTION_DECL, n)

////////////////////////////////////
#define DECL_TEMPLATE(n) typename ACTION##n
#define END_DECL_TEMPLATE(n) ,DECL_TEMPLATE(n)
#define DECL_TEMPLATES(n) SIMPLE_REPEAT(DECL_TEMPLATE, END_DECL_TEMPLATE, n)


class DummySchedAction {};

#define ACTION_PARTS(n) SIMPLE_REPEAT(ACTION, END_ACTION, n)
#define DUMMY(n) DummySchedAction
#define END_DUMMY(n) ,DummySchedAction
#define DUMMY_PARTS(n) SIMPLE_REPEAT(DUMMY, END_DUMMY, n)
#define PARTIAL_TEMPLATES(n, macroA, macroB) PARTIAL_TEMPLATES_##n(macroA, macroB)


#define DEF_PARTIAL_TEMPLATES(n)\
template <DECL_TEMPLATES(n)>\
class SEQUENTIAL__ <PARTIAL_TEMPLATES_##n(ACTION_PARTS, DUMMY_PARTS)>\
: public SequentialSchedAction{\
public:\
	SEQUENTIAL__(){\
		PUSHBACKACTIONS(n)\
	}\
private:\
	ACTION_DECLS(n)\
};\

#define DEF_GENERIC_SEQUENTIAL_TEMPLATES(n)\
template <DECL_TEMPLATES(n)>\
class SEQUENTIAL__ : public SequentialSchedAction{\
public:\
	SEQUENTIAL__(){\
		PUSHBACKACTIONS(n)\
	}\
private:\
	ACTION_DECLS(n)\
};


template <DEFAULT_TEMPLATES(15)>
class SEQUENTIAL__;

DEF_PARTIAL_TEMPLATES(1)
DEF_PARTIAL_TEMPLATES(2)
DEF_PARTIAL_TEMPLATES(3)
DEF_PARTIAL_TEMPLATES(4)
DEF_PARTIAL_TEMPLATES(5)
DEF_PARTIAL_TEMPLATES(6)
DEF_PARTIAL_TEMPLATES(7)
DEF_PARTIAL_TEMPLATES(8)
DEF_PARTIAL_TEMPLATES(9)
DEF_PARTIAL_TEMPLATES(10)
DEF_PARTIAL_TEMPLATES(11)
DEF_PARTIAL_TEMPLATES(12)
DEF_PARTIAL_TEMPLATES(13)
DEF_PARTIAL_TEMPLATES(14)

DEF_GENERIC_SEQUENTIAL_TEMPLATES(15)



#endif /* SEQUENTIALSCHEDACTIONHELPER_H_ */
