/**
 * @author Bilal El Uneis (bilaleluneis@gmail.com)
 * @since Feb 2020
 */

template<typename StateType>
StateType State<StateType>::value() const {
    return _state_data;
}
