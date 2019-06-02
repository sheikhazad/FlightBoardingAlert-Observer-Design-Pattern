#ifndef OBSERVER_DP_SUBJECT_HPP_
#define OBSERVER_DP_SUBJECT_HPP_

#include "Observer.hpp"
#include <memory>

//Subject/Publisher Interface for Observer DP
class Subject
{

public:

    /**
     * Register an Observer
     * @param Observer - the Observer object to be registered
     */
    virtual void registerObserver(Observer* Observer) = 0;

    /**
     * De-register (remove) an Observer
     * @param Observer - the Observer object to be unregistered
     */
    virtual void deregisterObserver(Observer* Observer) = 0;

    //Notify all the registered Observers when status is changed
    virtual void notifyObservers() = 0;

    //Interface should always declare destructor to be virtual
    virtual ~Subject(){}

};

#endif // OBSERVER_DP_SUBJECT_HPP_
