#include "SchedAction/SchedActionAdpter.h"

Status SchedActionAdapter::exec() {
	return ROLE(Action).exec();
}

Status SchedActionAdapter::handleEvent(const Event& event) {
	return ROLE(Action).handleEvent(event);
}
