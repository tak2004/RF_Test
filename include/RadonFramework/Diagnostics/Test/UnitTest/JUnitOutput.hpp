#pragma once

namespace RadonFramework::IO
{
class Uri;
}

namespace RadonFramework::Diagnostics::Test
{
class TestResultCollector;
}

namespace RadonFramework::Diagnostics::Test::UnitTest
{

class JUnitOutput
{
public:
  void WriteToFile(const IO::Uri& URI, const TestResultCollector& Results);
};

}  // namespace RadonFramework::Diagnostics::Test::UnitTest

namespace RF_UnitTest = RadonFramework::Diagnostics::Test::UnitTest;
