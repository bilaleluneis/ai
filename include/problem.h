/**
 * @author Bilal El Uneis (bilaleluneis@gmail.com)
 * @since Jan 2020
 */

#ifndef AI_PROBLEM_H
#define AI_PROBLEM_H

#include <include/state.h>
#include <vector>

using namespace std;

template<typename StateType, typename ActionType, typename CostType>
struct Successor final {
        StateType state;
        ActionType action;
        CostType cost;
};

template<typename StateType>
struct StateTransition final {
        State<StateType> from;
        State<StateType> to;
};

template<typename StateType, typename ActionType, typename CostType>
class Problem {
    public:
        virtual const State<StateType>& get_start_state() const = 0;
        [[nodiscard]] virtual bool is_goal_state() const = 0;
        virtual const vector<Successor<StateType, ActionType, CostType>>& get_successors() const = 0;
        virtual const CostType& get_cost_of_action(vector<StateTransition<StateType>>) const = 0;
        virtual ~Problem() = default;
};

#endif
