#include <RadonFramework/Radon.hpp>

int main(int argc, char** argv)
{
  RadonFramework::Radon framework;

  RF_Thread::ThreadPool::Global().DisableAndWaitTillDone();
  return 0;
}