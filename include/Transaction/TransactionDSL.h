/*
 * TransactionDSL.h
 *
 *  Created on: 2014年11月8日
 *      Author: Thoughtworks
 */

#ifndef TRANSACTIONDSL_H_
#define TRANSACTIONDSL_H_

#include "helper/SequentialSchedActionHelper.h"
#include "helper/TransactionHelper.h"
#include "helper/AsyncHelper.h"
#include "helper/SyncHelper.h"
#include "helper/NotHelper.h"
#include "helper/multiPathHelper.h"

class whatever
{
public:
	bool operator()(){return true;}
};

#define __async(...) ASYNC__<__VA_ARGS__>

#define __sync(...) SYNC__<__VA_ARGS__>

#define __sequential(...) SEQUENTIAL__<__VA_ARGS__ >

#define __switch(...) SWITCH__<__VA_ARGS__>

#define __case(...) CASE__<__VA_ARGS__>

#define __otherwise(...) __case(whatever, __VA_ARGS__)//语法糖

#define __optional(...) __switch(__case(__VA_ARGS__))//语法糖

#define __transaction(...)  TRANSACTION__<__VA_ARGS__ >

#define __not(condition) NOT__<condition>

#endif /* TRANSACTIONDSL_H_ */
