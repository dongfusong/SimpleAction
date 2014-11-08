/*
 * SequentialSchedActionHelper.h
 *
 *  Created on: 2014Äê11ÔÂ8ÈÕ
 *      Author: Thoughtworks
 */

#ifndef SEQUENTIALSCHEDACTIONHELPER_H_
#define SEQUENTIALSCHEDACTIONHELPER_H_

#include "SchedAction/SequentialSchedAction.h"
#include <iostream>
using namespace std;

//#define REPEAT_TYPE_NAEM(1) typename ACTION1

class DumySchedAction : public SchedAction{
public:
	Status exec(){
			return 4;
	}
	Status handleEvent(const Event& event){
		return 4;
	}
};



template <typename ACTION1 = DumySchedAction, typename ACTION2 = DumySchedAction
		, typename ACTION3 = DumySchedAction>
class SEQUENTIAL__;


template <typename ACTION1>
class SEQUENTIAL__<ACTION1, DumySchedAction, DumySchedAction>
: public SequentialSchedAction{
public:
	SEQUENTIAL__(){
		pushBackAction(&action1);
	}
private:
	ACTION1 action1;
};

template <typename ACTION1, typename ACTION2>
class SEQUENTIAL__<ACTION1, ACTION2, DumySchedAction>
: public SequentialSchedAction{
public:
	SEQUENTIAL__(){
		pushBackAction(&action1);
		pushBackAction(&action2);
	}
private:
	ACTION1 action1;
	ACTION2 action2;
};


template <typename ACTION1, typename ACTION2, typename ACTION3>
class SEQUENTIAL__ : public SequentialSchedAction{
public:
	SEQUENTIAL__(){
		pushBackAction(&action1);
		pushBackAction(&action2);
		pushBackAction(&action3);
	}
private:
	ACTION1 action1;
	ACTION2 action2;
	ACTION3 action3;
};


#if 1



#endif
#endif /* SEQUENTIALSCHEDACTIONHELPER_H_ */
