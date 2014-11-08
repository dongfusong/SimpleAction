/*
 * SyncActionAdapter.h
 *
 *  Created on: 2014Äê11ÔÂ9ÈÕ
 *      Author: Thoughtworks
 */

#ifndef SYNCACTIONADAPTER_H_
#define SYNCACTIONADAPTER_H_
#include "SchedAction/SchedAction.h"
#include "Action/Action.h"

class SyncActionAdapter : public SchedAction
{
public:
	virtual Status exec();
	virtual Status handleEvent(const Event& event);
private:
	USE_ROLE(SyncAction);
};
#endif /* SYNCACTIONADAPTER_H_ */
