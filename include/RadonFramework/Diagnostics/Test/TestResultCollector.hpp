#pragma once

#include <RadonFramework/Collections/List.hpp>
#include <RadonFramework/Core/Types/Float32.hpp>
#include <RadonFramework/Diagnostics/Test/UnitTest/Collector.hpp>
#include <RadonFramework/Diagnostics/Test/TestResult.hpp>

namespace RadonFramework::Diagnostics::Test
{
struct SuiteResult
{
  RF_Collect::List<RF_Test::TestResult> TestResults;
  RF_Type::String SuiteName;
  RF_Type::Float32 TotalTime;
  RF_Type::UInt32 TestsWithError;
  RF_Type::UInt32 TestsWithFailure;
};

class TestResultCollector : public RF_UnitTest::Collector
{
public:
  TestResultCollector();
  void CreateSuite(const RF_Type::String& Name) final;
  void ProcessResult(const RF_Test::TestResult& Result) final;
  RF_Type::Bool WasSuccessful();
  const RF_Collect::List<SuiteResult>& TestResults() const;

protected:
  RF_Collect::List<SuiteResult> m_TestResults;
  RF_Type::Bool m_Successful;
};

}  // namespace RadonFramework::Diagnostics::Test

namespace RF_Test = RadonFramework::Diagnostics::Test;