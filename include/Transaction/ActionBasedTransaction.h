/*
 * Transaction.h
 *
 *  Created on: 2014Äê11ÔÂ7ÈÕ
 *      Author: Thoughtworks
 */

#ifndef ACTION_BASED_TRANSACTION_H
#define ACTION_BASED_TRANSACTION_H

#include "common/CommonDefine.h"
#include "common/Role.h"
#include "Transaction.h"

class SchedAction;
class ActionBasedTransaction : public Transaction{
public:
	Status start();
	Status handleEvent(const Event& event);
private:
	USE_ROLE(SchedAction);
};


#endif /* TRANSACTION_H_ */
