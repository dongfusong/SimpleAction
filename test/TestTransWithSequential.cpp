/*
 * TestTransaction.cpp
 *
 *  Created on: 2014Äê11ÔÂ7ÈÕ
 *      Author: Thoughtworks
 */
#include <gtest/gtest.h>
#include "Transaction/TransactionDSL.h"
#include "SimpleAction.h"

DEF_ASYNC_ACTION(Action1, EV_EVENT_1);
DEF_ASYNC_ACTION(Action2, EV_EVENT_2);
DEF_ASYNC_ACTION(Action3, EV_EVENT_3);

DEF_SYNC_ACTION(Action4, EV_EVENT_4);
DEF_SYNC_ACTION(Action5, EV_EVENT_5);

class TestTransaction: public testing::Test {
public:
	void SetUp() {
	}
	void TearDown() {

	}
protected:
	__transaction(
		__sequential(
			__async(Action1),
			__async(Action2),
			__sequential( __async(Action3),
						  __async(Action2),
						  __async(Action1))
			)
	)sequetialTrans;


	__transaction(
				__sequential(
						__async(Action1),__async(Action1),__async(Action1),
						__async(Action1),__async(Action1),__async(Action1),
						__async(Action1),__async(Action1),__async(Action1),
						__async(Action1),__async(Action1),__async(Action1),
						__async(Action1),__async(Action1),__async(Action1)
				)
			)maxActionsTrans;

	__transaction(
				__sequential(
					__sync(Action4),__sync(Action4),__sync(Action4)
				)
			)allSyncTrans;
};

TEST_F(TestTransaction, return_unkown_when_error_event)
{
	EXPECT_EQ(CONTINUE, sequetialTrans.start());
	EXPECT_EQ(UNKNOWN_EVENT, sequetialTrans.handleEvent(EV_EVENT_2));
}

TEST_F(TestTransaction, return_unkown_when_error_event_before_start)
{
	EXPECT_EQ(UNKNOWN_EVENT, sequetialTrans.handleEvent(EV_EVENT_2));
}

TEST_F(TestTransaction, can_schedule_nested_sequetial_actions)
{
	EXPECT_EQ(CONTINUE, sequetialTrans.start());
	EXPECT_EQ(CONTINUE, sequetialTrans.handleEvent(EV_EVENT_1));
	EXPECT_EQ(CONTINUE, sequetialTrans.handleEvent(EV_EVENT_2));
	EXPECT_EQ(CONTINUE, sequetialTrans.handleEvent(EV_EVENT_3));
	EXPECT_EQ(CONTINUE, sequetialTrans.handleEvent(EV_EVENT_2));
	EXPECT_EQ(SUCCESS, sequetialTrans.handleEvent(EV_EVENT_1));
	EXPECT_EQ(UNKNOWN_EVENT, sequetialTrans.handleEvent(EV_EVENT_2));
}

TEST_F(TestTransaction, sequetials_can_holds_max_15_acitons){
	EXPECT_EQ(CONTINUE, maxActionsTrans.start());
	int actionNum = 0;
	while(1){
		Status status = maxActionsTrans.handleEvent(EV_EVENT_1);
		actionNum++;
		if (CONTINUE != status){
			break;
		}
	}
	EXPECT_EQ(15, actionNum);
}

TEST_F(TestTransaction, start_with_all_sync_actions_and_success){
	EXPECT_EQ(SUCCESS, allSyncTrans.start());
}


