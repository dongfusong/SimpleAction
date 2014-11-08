/*
 * SchedAction.h
 *
 *  Created on: 2014Äê11ÔÂ7ÈÕ
 *      Author: Thoughtworks
 */

#ifndef SCHEDACTION_H_
#define SCHEDACTION_H_
#include "common/role.h"
#include "common/CommonDefine.h"

class Event;
DEF_ROLE(SchedAction)
{
public:
	ABSTRACT(Status exec());
	ABSTRACT(Status handleEvent(const Event&));
};

#endif /* SCHEDACTION_H_ */
