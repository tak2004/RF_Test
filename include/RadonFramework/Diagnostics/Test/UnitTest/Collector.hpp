#pragma once

namespace RadonFramework::Core::Types
{
class String;
}

namespace RadonFramework::Diagnostics::Test {
class TestResult;
}

namespace RadonFramework::Diagnostics::Test::UnitTest {

class Collector
{
public:
    virtual void CreateSuite(const Core::Types::String& Name)=0;
    virtual void ProcessResult(const Test::TestResult& Result)=0;
};

}

namespace RF_UnitTest = RadonFramework::Diagnostics::Test::UnitTest;