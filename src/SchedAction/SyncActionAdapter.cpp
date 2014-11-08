#include "SchedAction/SyncActionAdapter.h"

Status SyncActionAdapter::exec() {
	return ROLE(SyncAction).exec();
}

Status SyncActionAdapter::handleEvent(const Event& event) {
	return UNKNOWN_EVENT;
}
