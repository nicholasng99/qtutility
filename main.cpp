#include <QApplication>

#include "data/job_queue/job_queue.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  JobQueue;
  return app.exec();
}