#pragma once

#include <iostream>
#include <chrono>
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
											std::cout << "*** End of test : " << #testname << " in " << elapsed.count() << " seconds." << std::endl; \
											std::cout << "**********************" << std::endl << std::endl

#define TEST_RESULT(testname, result)		std::cout << #testname << " : " << (bool)result; \
											std::cout << std::endl
	/* Entities */
//bool BurstTest_EntityTest_Emplacing();
//bool BurstTest_EntityTest_Removing();

	/* Components */
bool BurstTest_ComponentTest_Emplacing();
bool BurstTest_ComponentTest_Removing();

	/* Complete */
bool BurstTest_CompleteTest_NormalRegistery();
bool BurstTest_CompleteTest_TemplatedRegistery();