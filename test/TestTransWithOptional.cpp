/*
 * TestTransactionWithOptional.cpp
 *
 *  Created on: 2014Äê11ÔÂ8ÈÕ
 *      Author: Thoughtworks
 */

#include <gtest/gtest.h>
#include "SimpleAction.h"
#include "Transaction/TransactionDSL.h"


DEF_ASYNC_ACTION(Action1, EV_EVENT_1);
DEF_ASYNC_ACTION(Action2, EV_EVENT_2);
DEF_ASYNC_ACTION(Action3, EV_EVENT_3);

class isAction2First{
public:
	bool operator()(){
		return true;
	}
};

class isAction3First{
public:
	bool operator()(){
		return true;
	}
};


class TestTransactionWithOptional: public testing::Test {
public:
	void SetUp() {

	}
	void TearDown() {

	}
protected:
	__transaction(
			__sequential(
					__async(Action1),
					__optional(isAction2First,__sequential(__async(Action2), __async(Action3))),
					__optional(__not(isAction2First),__async(Action3))
				)
			)optionTrans;

	__transaction(
			__sequential(
					__switch(
							__case(isAction2First,  __async(Action2)),
							__otherwise(__async(Action1))
							)
				)
			)otherwiseTrans;

	__transaction(
			__sequential(
					__switch(
							__case(isAction2First,  __async(Action2)),
							__case(isAction2First,  __async(Action3)),
							__otherwise(__async(Action1))
							)
				)
			)switchTrans;
};


TEST_F(TestTransactionWithOptional, can_chose_optional_action)
{
	EXPECT_EQ(CONTINUE, optionTrans.start());
	EXPECT_EQ(CONTINUE, optionTrans.handleEvent(Event(EV_EVENT_1)));
	EXPECT_EQ(CONTINUE, optionTrans.handleEvent(Event(EV_EVENT_2)));
	EXPECT_EQ(SUCCESS, optionTrans.handleEvent(Event(EV_EVENT_3)));
}

TEST_F(TestTransactionWithOptional, otherwise_should_execute_if_non_match){
	EXPECT_EQ(CONTINUE, otherwiseTrans.start());
	EXPECT_EQ(UNKNOWN_EVENT, otherwiseTrans.handleEvent(Event(EV_EVENT_1)));
	EXPECT_EQ(SUCCESS, otherwiseTrans.handleEvent(Event(EV_EVENT_2)));
}

TEST_F(TestTransactionWithOptional, only_one_match_for_switch){
	EXPECT_EQ(CONTINUE, switchTrans.start());
	EXPECT_EQ(SUCCESS, switchTrans.handleEvent(Event(EV_EVENT_2)));
}



