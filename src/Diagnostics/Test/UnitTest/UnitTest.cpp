#include "RadonFramework/Diagnostics/Test/UnitTest/UnitTest.hpp"
#include "RadonFramework/Diagnostics/Test/UnitTest/TestSuite.hpp"
#include "RadonFramework/Diagnostics/Test/UnitTest/Collector.hpp"
#include "RadonFramework/Diagnostics/Test/TestResult.hpp"
#include "RadonFramework/Threading/ThreadPool.hpp"
#include "RadonFramework/Core/Pattern/Singleton.hpp"

namespace RadonFramework::Diagnostics::Test::UnitTest
{
UnitTest::UnitTest() : m_TestProbes(1) {}

void UnitTest::AddCollector(Collector& ACollector)
{
  Collector* collector = &ACollector;
  m_Collector.AddLast(collector);
}

void UnitTest::RegisterTestSuite(TestSuite* ATestSuite)
{
  m_TestSuites.AddLast(ATestSuite);
}

void UnitTest::Run()
{
  for(RF_Type::UInt32 i = 0; i < m_TestSuites.Count(); ++i)
  {
    if(!m_IgnoreSuite.Find(m_TestSuites[i]->Name()))
      RunSuiteAt(i);
  }
}

void UnitTest::RunSuiteWithName(const RF_Type::String& Suitename)
{
  if(!m_IgnoreSuite.Find(Suitename))
  {
    for(RF_Type::UInt32 i = 0; i < m_TestSuites.Count(); ++i)
    {
      if(m_TestSuites[i]->Name() == Suitename)
      {
        RunSuiteAt(i);
        break;
      }
    }
  }
}

void UnitTest::RunSuiteAt(RF_Type::Size Index)
{
  m_TestSuites[Index]->SetUp();
  for(RF_Type::Size i = 0; i < m_Collector.Count(); ++i)
  {
    m_Collector[i]->CreateSuite(m_TestSuites[Index]->Name());
  }
  // Wait till all Appender wrote the initial headline.
  RF_Pattern::Singleton<RF_Thread::ThreadPool>::GetInstance()
      .WaitTillDoneWithInactiveQueue();
  // Start multi threaded test.
  m_TestSuites[Index]->SetTestProbes(m_TestProbes);
  m_TestSuites[Index]->Run();

  RF_Collect::List<RF_Mem::AutoPointer<RF_Test::TestResult>>& results =
      m_TestSuites[Index]->GetResults();
  for(RF_Type::Size i = 0; i < results.Count(); ++i)
  {
    for(RF_Type::Size l = 0; l < m_Collector.Count(); ++l)
    {
      m_Collector[l]->ProcessResult(*results[i]);
    }
  }
  // Wait till all logging stuff of the tests are done.
  RF_Pattern::Singleton<RF_Thread::ThreadPool>::GetInstance()
      .WaitTillDoneWithInactiveQueue();
}

void UnitTest::SetSequentialTestExecution(RF_Type::Size Probes)
{
  m_TestProbes = Probes;
}

void UnitTest::IgnoreSuite(const RF_Type::String& Suitename)
{
  m_IgnoreSuite.AddLast(Suitename);
}

TestSuite* UnitTest::GetSuite(const RF_Type::String& Suitename)
{
  TestSuite* result = 0;
  for(RF_Type::Size i = 0; i < m_TestSuites.Count(); ++i)
  {
    if(m_TestSuites[i]->Name() == Suitename)
    {
      result = m_TestSuites[i];
      break;
    }
  }
  return result;
}

}  // namespace RadonFramework::Diagnostics::Test::UnitTest