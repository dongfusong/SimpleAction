/*
 * SyncAction.h
 *
 *  Created on: 2014Äê11ÔÂ7ÈÕ
 *      Author: Thoughtworks
 */

#ifndef SYNCACTION_H_
#define SYNCACTION_H_
#include "Event.h"
#include "Common/CommonDefine.h"
#include "Common/Role.h"

DEF_ROLE(SyncAction)
{
public:
	ABSTRACT(Status exec());
};

#endif /* SYNCACTION_H_ */
