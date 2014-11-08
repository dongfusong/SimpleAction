/*
 * ActionStatus.h
 *
 *  Created on: 2014年11月8日
 *      Author: Thoughtworks
 */

#ifndef ACTIONSTATUS_H_
#define ACTIONSTATUS_H_
#include "Common/CommonDefine.h"

class ActionStatus {
public:
	ActionStatus():status(SUCCESS){
	}

	ActionStatus(const Status status):status(status)
	{
	}

	bool isDone()const{
		return status == SUCCESS;
	}

	ActionStatus& operator=(const ActionStatus& rhs){
		status = rhs.status;
		return *this;
	}

	//ActionStatus向Status类型转换使用
	operator Status()const{
		return status;
	}
private:
	Status status;
};





#endif /* ACTIONSTATUS_H_ */
