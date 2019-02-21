#include "src/object/base_object.h"

BaseObject::BaseObject(QObject* parent) : QObject(parent)
{
    setThreadState(ThreadState::finished);
}
