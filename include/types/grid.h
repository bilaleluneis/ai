/**
 * @author Bilal El Uneis (bilaleluneis@gmail.com)
 * @since Jan 2020
 */

#ifndef AI_GRID_H
#define AI_GRID_H

#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct Dimensions final {
        size_t rows;
        size_t columns;
};

template<typename GridType, size_t rows, size_t columns>
class Grid {

    public:
        Grid() noexcept(rows > 0 && columns > 0); // could throw range_error
        ~Grid();
        [[nodiscard]] Dimensions dimensions() const;
        inline typename vector<GridType>::iterator begin() const;
        inline typename vector<GridType>::iterator end() const;
        GridType& operator[] (pair<size_t, size_t> index);
        const GridType& operator[] (pair<size_t, size_t> index) const;
        bool operator ==  (const Grid& another_grid) const;
        bool operator !=  (const Grid& another_grid) const;
        bool operator <<= (vector<GridType> to_check_against) const; //checks if every to_check_against is in Grid

    private:
        size_t _rows;
        size_t _columns;
        vector<GridType>* _grid;
};

#include <src/types/grid.cpp>
#endif
