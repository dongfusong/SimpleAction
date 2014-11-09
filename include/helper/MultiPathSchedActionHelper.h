/*
 * MulitPathHelper.h
 *
 *  Created on: 2014Äê11ÔÂ9ÈÕ
 *      Author: Thoughtworks
 */

#ifndef MULITPATHHELPER_H_
#define MULITPATHHELPER_H_
#include "SchedAction/MultiPathSchedAction.h"
#include "DummySchedAction.h"

template<typename CONDITION, typename ACTION>
class CASE__ : public ActionPath{
public:
	OVERRIDE bool shouldExecute(){
		return _condition();
	}
	OVERRIDE SchedAction& getSchedAction(){
		return _action;
	}
private:
	CONDITION _condition;
	ACTION _action;
};


template <typename ACTION_PATH1 = DummySchedAction, typename ACTION_PATH2 = DummySchedAction,
		typename ACTION_PATH3 = DummySchedAction>
class SWITCH__;


template <typename ACTION_PATH1>
class SWITCH__<ACTION_PATH1, DummySchedAction, DummySchedAction> : public MulitplePathSchedAction{
public:
	SWITCH__(){
		pushBackPath(&path1);
	}
private:
	ACTION_PATH1 path1;
};

template <typename ACTION_PATH1, typename ACTION_PATH2>
class SWITCH__<ACTION_PATH1, ACTION_PATH2, DummySchedAction> : public MulitplePathSchedAction{
public:
	SWITCH__(){
		pushBackPath(&path1);
		pushBackPath(&path2);
	}
private:
	ACTION_PATH1 path1;
	ACTION_PATH2 path2;
};

template <typename ACTION_PATH1, typename ACTION_PATH2, typename ACTION_PATH3>
class SWITCH__ : public MulitplePathSchedAction{
public:
	SWITCH__(){
		pushBackPath(&path1);
		pushBackPath(&path2);
		pushBackPath(&path3);
	}
private:
	ACTION_PATH1 path1;
	ACTION_PATH2 path2;
	ACTION_PATH3 path3;
};

#endif /* MULITPATHHELPER_H_ */
