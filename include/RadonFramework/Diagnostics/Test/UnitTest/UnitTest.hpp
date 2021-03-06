#pragma once

#include <RadonFramework/Collections/List.hpp>
#include <RadonFramework/Core/Types/Size.hpp>
#include <RadonFramework/Core/Types/String.hpp>

namespace RadonFramework::Diagnostics::Test::UnitTest
{
class TestSuite;
class Collector;

class UnitTest
{
public:
  UnitTest();
  void AddCollector(Collector& ACollector);
  void RegisterTestSuite(TestSuite* ATestSuite);
  void Run();
  void RunSuiteWithName(const RF_Type::String& Suitename);
  void SetSequentialTestExecution(RF_Type::Size Probes);
  void IgnoreSuite(const RF_Type::String& Suitename);
  TestSuite* GetSuite(const RF_Type::String& Suitename);

private:
  RF_Collect::List<RF_Type::String> m_IgnoreSuite;
  RF_Collect::List<TestSuite*> m_TestSuites;
  RF_Collect::List<Collector*> m_Collector;
  RF_Type::Size m_TestProbes;

  void RunSuiteAt(const RF_Type::Size Index);
};

}  // namespace RadonFramework::Diagnostics::Test::UnitTest

namespace RF_UnitTest = RadonFramework::Diagnostics::Test::UnitTest;