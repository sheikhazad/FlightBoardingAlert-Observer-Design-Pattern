#include "Passenger.hpp"
#include <iostream>

void Passenger::updateStatus(const std::string& iMsg) {
    // print the boarding update message
    std::cout << iMsg << std::endl;
}

const std::string&  Passenger::getPassengerName(){
	return m_passnger_name;
}

