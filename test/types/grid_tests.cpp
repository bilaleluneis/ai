/**
 * @author Bilal El Uneis (bilaleluneis@gmail.com)
 * @since Jan 2020
 */

#include <include/types/grid.h>
#include <boost/test/unit_test.hpp>
#include <boost/scoped_ptr.hpp>
#include <utility>

using namespace boost;
using namespace std;

struct GridFixture {
    explicit GridFixture(bool throwException = false):  gridOne{new Grid<int, 10 ,10>},
                                                        gridTwo{new Grid<int, 10, 10>},
                                                        gridThree{new Grid<int, 5, 5>} {
        if(throwException)
            gridFour.reset(new Grid<int, 0, 0>);
    }

    ~GridFixture() {
        gridOne.reset();
        gridTwo.reset();
        gridThree.reset();
        gridFour.reset();
    }

    scoped_ptr<Grid<int, 10, 10>> gridOne;
    scoped_ptr<Grid<int, 10, 10>> gridTwo;
    scoped_ptr<Grid<int, 5, 5>> gridThree;
    scoped_ptr<Grid<int, 0, 0>> gridFour;
};

BOOST_FIXTURE_TEST_SUITE(gridTests, GridFixture)

BOOST_AUTO_TEST_CASE( invalidInstanceCreationTest ){
    BOOST_CHECK_THROW(GridFixture(true), range_error);
}

BOOST_AUTO_TEST_CASE( validInstanceCreationTest ){
    BOOST_CHECK(gridOne.get() != nullptr);
    pair<size_t, size_t> index = {0, 0};
    BOOST_CHECK_EQUAL((*gridOne)[index], 0);
}

BOOST_AUTO_TEST_CASE( indexOperatorTest ){
    pair<size_t, size_t> index = pair{0, 0};
    BOOST_CHECK_EQUAL((*gridOne)[index], 0);
    (*gridOne)[index] = 1;
    BOOST_CHECK_EQUAL((*gridOne)[index], 1);
}

BOOST_AUTO_TEST_CASE(equalOperatorTest) {
   BOOST_CHECK(*gridOne == *gridTwo);
   (*gridTwo)[{0,0}] = 1;
   BOOST_CHECK(*gridOne != *gridTwo);
}

BOOST_AUTO_TEST_CASE(allElementsInOperatorTest) {
    auto& grid = *gridThree;
    grid[{0,0}] = 1;
    grid[{2, 1}] = 2;
    grid[{4, 4}] = 7;
    vector<int> elements_to_find = {1, 2, 7};
    BOOST_CHECK(grid <<= elements_to_find);
}

BOOST_AUTO_TEST_CASE(someElementsInOperatorTest) {
    auto& grid = *gridThree;
    grid[{0,0}] = 1;
    grid[{2, 1}] = 2;
    grid[{4, 4}] = 7;
    vector<int> elements_to_find = {1, 2, 5};
    BOOST_CHECK(!(grid <<= elements_to_find));
}

BOOST_AUTO_TEST_SUITE_END()