rcf_generate(executable RF_TEST_SMOKETEST SmokeTest "Tests/" "tests/SmokeTest.cpp")
    rcf_dependencies(RadonFramework RadonFrameworkTest)
rcf_endgenerate()