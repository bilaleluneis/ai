/**
 * @author Bilal El Uneis (bilaleluneis@gmail.com)
 * @since Feb 2020
 */


template<typename GridType, size_t rows, size_t columns>
Grid<GridType, rows, columns>:: Grid() noexcept (rows > 0 && columns > 0) {
    if(rows <= 0 || columns <= 0){
        string error = "[row, col] = ["+
                        to_string(rows) +
                        ", "+
                        to_string(columns) +
                        "] is not a valid index on Grid!";
        throw range_error(error);
    }
    _rows = rows;
    _columns = columns;
    _grid =  new vector<GridType>( _rows * columns);
}

template<typename GridType, size_t rows, size_t columns>
Grid<GridType, rows, columns>:: ~Grid() {
    _rows = 0;
    _columns = 0;
    _grid->clear();
    delete _grid;
}

template<typename GridType, size_t rows, size_t columns>
Dimensions Grid<GridType, rows, columns>:: dimensions() const {
    Dimensions dim{};
    dim.rows = _rows;
    dim.columns = _columns;
    return dim;
}

template<typename GridType, size_t rows, size_t columns>
inline typename vector<GridType>::iterator Grid<GridType, rows, columns>:: begin() const {
    return _grid->begin();
}

template<typename GridType, size_t rows, size_t columns>
inline typename vector<GridType>::iterator Grid<GridType, rows, columns>:: end() const {
    return _grid->end();
}

template<typename GridType, size_t rows, size_t columns>
GridType& Grid<GridType, rows, columns>:: operator[] (pair<size_t, size_t> index) {
    return (*_grid)[index.first * index.second];
}

template<typename GridType, size_t rows, size_t columns>
const GridType& Grid<GridType, rows, columns>:: operator[] (pair<size_t, size_t> index) const {
    return (*_grid)[index.first * index.second];
}

template<typename GridType, size_t rows, size_t columns>
bool Grid<GridType, rows, columns>:: operator == (const Grid& another_grid) const {
    Dimensions gridDim = this->dimensions();
    Dimensions otherGridDim = another_grid.dimensions();
    // check if both grids have exact rows and columns size
    if(gridDim.rows != otherGridDim.rows || gridDim.columns != otherGridDim.columns)
        return false;
    // check each element in both grids match
    for(size_t row = 0; row < gridDim.rows; ++row) {
        for (size_t col = 0; col < gridDim.columns; ++col)
            if ((*this)[{row, col}] != another_grid[{row, col}])
                return false;
    }
    return true;
}

template<typename GridType, size_t rows, size_t columns>
bool Grid<GridType, rows, columns>:: operator != (const Grid& another_grid) const {
   return !(*this == another_grid);
}

template<typename GridType, size_t rows, size_t columns>
bool Grid<GridType, rows, columns>:: operator <<= (vector<GridType> to_check_against) const {
    for (auto& value_to_check_against : to_check_against) {
        bool found = false;
        for (auto& grid_element : *this){
            if(grid_element == value_to_check_against) {
                found = true;
                break;
            }
        }
        if(!found)
            return false;
    }
    return true; // we got here , then all element are found in Grid
}