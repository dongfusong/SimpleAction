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
	OVERRIDE Status exec(){
		_chosedAction = findMatchedAction();
		if (NULL == _chosedAction){
			return SUCCESS;
		}
		return _chosedAction->exec();
	}

	OVERRIDE Status handleEvent(const Event& event){
		if (NULL == _chosedAction){
			return FATAL_ERR;
		}
		return _chosedAction->handleEvent(event);
	}

	void pushBackPath(ActionPath* path){
		_paths.push_back(path);
	}
private:
	SchedAction* findMatchedAction(){
		for (Paths::iterator iter = _paths.begin(); iter != _paths.end(); ++iter){
			if ((*iter)->shouldExecute()){
				return &((*iter)->getSchedAction());
			}
		}
		return NULL;
	}
private:
	typedef std::list<ActionPath*> Paths;
	Paths _paths;
	SchedAction* _chosedAction;
};

#endif /* MULTIPATHSCHEDACTION_H_ */
