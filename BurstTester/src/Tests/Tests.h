#pragma once

#include <iostream>
#include <chrono>
#include <assert.h>
#include "Burst.h"

	/* Macros */
#define START_TEST(testname)				std::cout << "************************" << std::endl; \
											std::cout << "*** Beginning test : " << #testname << std::endl; \
											std::cout << "************************" << std::endl; \
											auto start = std::chrono::high_resolution_clock::now(); \
											bool success = true

#define END_TEST(testname)					auto end = std::chrono::high_resolution_clock::now(); \
											auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>( end - start ); \
											std::cout << "**********************" << std::endl; \
											std::cout << "*** End of test : " << #testname << " in " << elapsed.count() << " seconds : " << success << std::endl; \
											std::cout << "**********************" << std::endl << std::endl; \
											return success

#define ASSERT(condition)					if ( condition ) std::cout << #condition << " (" << __FILE__ << " line " << __LINE__ << ") is true." << std::endl; \
											else { \
												std::cout << #condition << " (" << __FILE__ << " line " << __LINE__ << ") is false." << std::endl; \
												success = false; \
											}

bool Emplace_View();
bool Emplace_Remove_View();

bool Perfos_AddComponent();