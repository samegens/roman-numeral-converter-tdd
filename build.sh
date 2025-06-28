#!/bin/bash

set -xeuo pipefail

conan build . -s build_type=Debug --build=missing

# Running the tests outside of the conan build system will show better output.
build/Debug/unit_tests
