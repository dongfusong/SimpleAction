#include "SchedAction/MultiPathSchedAction.h"

Status MulitplePathSchedAction::exec() {
	_chosedAction = findMatchedAction();
	if (NULL == _chosedAction) {
		return SUCCESS;
	}
	return _chosedAction->exec();
}

Status MulitplePathSchedAction::handleEvent(const Event& event) {
	if (NULL == _chosedAction) {
		return FATAL_ERR;
	}
	return _chosedAction->handleEvent(event);
}

SchedAction* MulitplePathSchedAction::findMatchedAction() {
	for (Paths::iterator iter = _paths.begin(); iter != _paths.end(); ++iter) {
		if ((*iter)->shouldExecute()) {
			return &((*iter)->getSchedAction());
		}
	}
	return NULL;
}

void MulitplePathSchedAction::pushBackPath(ActionPath* path) {
	_paths.push_back(path);
}
