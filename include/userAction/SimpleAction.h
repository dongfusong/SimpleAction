/*
 * UserAction.h
 *
 *  Created on: 2014Äê11ÔÂ7ÈÕ
 *      Author: Thoughtworks
 */

#ifndef USERACTION_H_
#define USERACTION_H_
#include "Action/Event.h"
#include "Action/Action.h"
#include "Action/SyncAction.h"

#define EV_EVENT_1 1
#define EV_EVENT_2 2
#define EV_EVENT_3 3


class SimpleAction : public Action{
public:
	void wait_on(EventId id){
		eventId = id;
	}
	Status handleEvent(const Event& event){
		if (event.getEventId() == eventId){
			return SUCCESS;
		}
		return UNKNOWN_EVENT;
	}
private:
	EventId eventId;
};


#define DEF_ACTION(name, eventId)\
class name : public SimpleAction\
{\
public:\
	Status exec(){\
		wait_on(eventId);\
		return CONTINUE;\
	}\
}


#endif /* USERACTION_H_ */
