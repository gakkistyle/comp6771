// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include <string>

#include <catch2/catch.hpp>

TEST_CASE("Hello, C++!") {
	auto const hello = std::string("Hello, C++!");

	CHECK(hello == "Hello, C++!");
}
