/**
 * @file example_test.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief test stack interface
 * @version 0.1
 * @date 2024-04-11
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <criterion/criterion.h>

int add(int a, int b){
	return a+b;
}

Test(sample, test) {
    cr_assert_eq(4, add(2,2));
}
