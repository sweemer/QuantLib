/*
 * Use header-only version of Boost Test in order to get manual registration working with dynamic linking as per https://stackoverflow.com/a/24447829
 * 
 * It is possible to use the header-only variant of the Unit Test Framework even if the test module has multiple translation units:
 *   one translation unit should define BOOST_TEST_MODULE and include <boost/test/included/unit_test.hpp>
 *   all the other translation units should include <boost/test/unit_test.hpp>
 * 
 * https://www.boost.org/doc/libs/1_77_0/libs/test/doc/html/boost_test/adv_scenarios/single_header_customizations/multiple_translation_units.html
 */
#include <boost/test/included/unit_test.hpp>
