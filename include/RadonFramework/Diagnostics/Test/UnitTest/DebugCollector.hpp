#pragma once

#include <RadonFramework/Core/Types/String.hpp>
#include <RadonFramework/Diagnostics/Test/UnitTest/Collector.hpp>

namespace RadonFramework::Diagnostics::Test::UnitTest
{
class DebugCollector : public Collector
{
public:
  void CreateSuite(const RF_Type::String& Name) final;
  void ProcessResult(const Test::TestResult& Result) final;

protected:
  RF_Type::String m_CurrentSuite;
};

}  // namespace RadonFramework::Diagnostics::Test::UnitTest

namespace RF_UnitTest = RadonFramework::Diagnostics::Test::UnitTest;