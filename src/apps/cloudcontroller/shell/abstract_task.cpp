#include "abstract_task.h"
#include "io/terminal.h"

namespace cloudcontroller{
namespace shell{

using sn::corelib::Terminal;

AbstractTask::AbstractTask(AbstractTaskContainer& taskContainer, const TaskMeta& meta)
   : m_taskContainer(taskContainer),
     m_invokeMeta(meta)
{
}

void AbstractTask::printConsoleMsg(const char *str, sn::corelib::TerminalColor color, bool underline, bool blink) const
{
   Terminal::writeText(str, color, underline, blink);
}

AbstractTask::~AbstractTask()
{}

}//shell
}//cloudcontroller