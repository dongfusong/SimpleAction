/*
 * SequentialSchedActionHelper.h
 *
 *  Created on: 2014Äê11ÔÂ8ÈÕ
 *      Author: Thoughtworks
 */

#ifndef SEQUENTIALSCHEDACTIONHELPER_H_
#define SEQUENTIALSCHEDACTIONHELPER_H_

#include "SchedAction/SequentialSchedAction.h"

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

#endif /* SEQUENTIALSCHEDACTIONHELPER_H_ */
