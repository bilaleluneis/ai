/**
 * @author Bilal El Uneis (bilaleluneis@gmail.com)
 * @since Jan 2020
 */

#include <include/state.h>
#include <boost/test/unit_test.hpp>
#include <boost/scoped_ptr.hpp>

using namespace boost;

struct StateFixture {
        StateFixture(): state {new State<char> {'A'}} {}
        ~StateFixture() { state.reset(); }
        scoped_ptr<State<char>> state;
};

BOOST_FIXTURE_TEST_SUITE(stateTests, StateFixture)

BOOST_AUTO_TEST_CASE( charStateInitTest ){
    BOOST_CHECK_EQUAL(state->value(), 'A');
}

BOOST_AUTO_TEST_SUITE_END()


