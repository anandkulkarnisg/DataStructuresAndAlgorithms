#!/bin/bash
# First run the unit tests.
$PWD/BoostUnitTests.out
# Run the regression tests.
$PWD/BoostPerfTests.out --log_level=all
