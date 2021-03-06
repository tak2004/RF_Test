#pragma once

#include <RadonFramework/Collections/List.hpp>
#include <RadonFramework/Core/Pattern/Delegate.hpp>
#include <RadonFramework/Core/Types/String.hpp>
#include <RadonFramework/Memory/AutoPointer.hpp>

namespace RadonFramework::Diagnostics::Test
{
class TestResult;
}

namespace RadonFramework::Diagnostics::Test::UnitTest
{
class TestSuite
{
public:
  using TestMethod = Delegate<RF_Type::Bool()>;

  TestSuite(const RF_Type::String& Name);
  const RF_Type::String& Name() const;
  void SetTestProbes(const RF_Type::Size Probes);
  void AddTest(TestMethod Test,
               const RF_Type::String& Testname,
               const RF_Type::String& Description);
  virtual void SetUp();
  virtual void TearDown();
  void IgnoreTest(const RF_Type::String& Testname);
  void Run();
  RF_Collect::List<RF_Mem::AutoPointer<Test::TestResult>>& GetResults();

protected:
  struct Callback
  {
    RF_Type::String Name;
    RF_Type::String Description;
    TestMethod Method;
  };
  RF_Collect::List<Callback> m_TestMethods;
  RF_Type::String m_Name;
  RF_Collect::List<RF_Type::String> m_IgnoreTest;
  RF_Collect::List<RF_Mem::AutoPointer<Test::TestResult>> m_TestResults;
  RF_Type::Size m_TestProbes;

  RF_Mem::AutoPointer<Test::TestResult>
  ProcessTest(const RF_Type::UInt32 Number);
};

}  // namespace RadonFramework::Diagnostics::Test::UnitTest

namespace RF_UnitTest = RadonFramework::Diagnostics::Test::UnitTest;