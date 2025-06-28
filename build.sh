#!/bin/bash

set -xeuo pipefail

conan build .

# Running the tests outside of the conan build system will show better output.
build/Release/unit_tests
