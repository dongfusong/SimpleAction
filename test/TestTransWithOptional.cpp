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

#define __optional(...)
class TestTransactionWithOptional: public testing::Test {
public:
	void SetUp() {

	}
	void TearDown() {

	}
protected:
//	__transaction(
//					__async(Action1),
//					__optional(isAction2First,__sequential(__async(Action2), __async(Action3))),
//					__optinal(__not(isAction2First),__async(Action3))_
//			)trans;
};


TEST_F(TestTransactionWithOptional, )
{

}


