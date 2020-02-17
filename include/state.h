/**
 * @author Bilal El Uneis (bilaleluneis@gmail.com)
 * @since Jan 2020
 */

#ifndef AI_STATE_H
#define AI_STATE_H

#include <boost/scoped_ptr.hpp>
using namespace boost;

template<typename StateType>
class State final {
    private:
        StateType _state_data;

    public:
        explicit State(StateType state_data) : _state_data{state_data} {}
        ~State() = default;
        StateType value() const;
};

#include <src/state.cpp>
#endif
