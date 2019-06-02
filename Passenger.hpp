#ifndef PASSENGER_HPP_
#define PASSENGER_HPP_

#include "Observer.hpp"
#include <string>

/**
 * Passenger that implements the Observer/Subscriber interface
 */
class Passenger : public Observer {

public:

    Passenger(const std::string& iName):m_passnger_name(iName){
	}

    void updateStatus(const std::string& iMsg) override;

    const std::string& getPassengerName() override;

    ~Passenger() {}

private:

   std::string m_passnger_name;
};


#endif // PASSENGER_HPP_
