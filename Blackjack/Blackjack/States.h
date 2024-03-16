#ifndef CS8_STATES_H
#define CS8_STATES_H

#include <map>
#include "StatesEnum.h"

class States {
private:
    std::map<StateEnum, bool> states;

public:
    States();
    void disableState(StateEnum state);
    void enableState(StateEnum state);
    void toggleState(StateEnum state);
    bool getState(StateEnum state) const;
};


#endif //CS8_STATES_H
