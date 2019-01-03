#pragma once

#include <RadonFramework/Diagnostics/Test/UnitTest/Collector.hpp>

namespace RadonFramework::Diagnostics::Test::UnitTest
{
class BriefProgressCollector : public Collector
{
public:
  void CreateSuite(const Core::Types::String& Name) override;
  void ProcessResult(const Test::TestResult& Result) override;
};

}  // namespace RadonFramework::Diagnostics::Test::UnitTest

namespace RF_UnitTest = RadonFramework::Diagnostics::Test::UnitTest;