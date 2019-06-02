#ifndef OBSERVER_DP_OBSERVER_HPP_
#define OBSERVER_DP_OBSERVER_HPP_

#include <string>

//Observer/Subscriber Interface for Observer DP
class Observer
{

public:

    /**
     * Update Boarding status change to the Observer
     * @sMsg - Alert message
     */
    virtual void updateStatus(const std::string& iMsg) = 0;

    virtual const std::string& getPassengerName() = 0;

    virtual ~Observer(){}

};

#endif // OBSERVER_DP_OBSERVER_HPP_
