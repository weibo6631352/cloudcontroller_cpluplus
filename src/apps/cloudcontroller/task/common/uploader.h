#ifndef CLOUD_CONTROLLER_TASK_UPGRADEMGR_COMMON_UPLOADER_H
#define CLOUD_CONTROLLER_TASK_UPGRADEMGR_COMMON_UPLOADER_H

#include "cclib/shell/task_meta.h"
#include "corelib/network/rpc/invoke_meta.h"
#include "cclib/shell/abstract_net_task.h"

namespace cloudcontroller{
namespace task{
namespace common{

using cclib::shell::AbstractNetTask;
using cclib::shell::AbstractTaskContainer;
using cclib::shell::TaskMeta;
using sn::corelib::network::ApiInvokeRequest;
using sn::corelib::network::ApiInvokeResponse;

class Uploader : public AbstractNetTask
{
   Q_OBJECT
protected:
   friend void init_upload_handler(const ApiInvokeResponse &response, void* args);
public:
   Uploader(AbstractTaskContainer *taskContainer, const TaskMeta &meta);
   Uploader& setFilename(const QString &filename);
   Uploader& setBaseDir(const QString &baseDir);
public:
   virtual void run();
   virtual ~Uploader();
protected:
   void clearContext();
   void startUploadProcess();
protected:
   void emitUploadErrorSignal(int errorCode, const QString errorString);
   void emitBeginUploadSignal();
signals:
   void prepareSignal();
   void beginUploadSignal();
   void uploadSuccessSignal();
   void uploadProgressSignal(int uploaded, int total);
   void uploadErrorSignal(int errorCode, const QString &errorString);
protected:
   QString m_filename;
   QString m_baseDir;
   int m_uploaded;
   int m_totalToBeUpload;
};

}//common
}//task
}//cloudcontroller

#endif // CLOUD_CONTROLLER_TASK_UPGRADEMGR_COMMON_UPLOADER_H
