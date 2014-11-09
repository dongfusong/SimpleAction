/*
 * MultiPathSchedAction.h
 *
 *  Created on: 2014Äê11ÔÂ9ÈÕ
 *      Author: Thoughtworks
 */

#ifndef MULTIPATHSCHEDACTION_H_
#define MULTIPATHSCHEDACTION_H_
#include <list>
#include "SchedAction/SchedAction.h"
using namespace std;

DEF_ROLE(ActionPath)
{
public:
	ABSTRACT(bool shouldExecute());
	ABSTRACT(SchedAction& getSchedAction());
};

class MulitplePathSchedAction : public SchedAction
{
public:
	OVERRIDE Status exec();
	OVERRIDE Status handleEvent(const Event& event);
	void pushBackPath(ActionPath* path);
private:
	SchedAction* findMatchedAction();
private:
	typedef std::list<ActionPath*> Paths;
	Paths _paths;
	SchedAction* _chosedAction;
};



#endif /* MULTIPATHSCHEDACTION_H_ */
