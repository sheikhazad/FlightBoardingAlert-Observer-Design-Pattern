
#include "Observer.hpp"
#include "BoardingStatus.hpp"
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

string sBoardingAlertMsg = ", \n\nBoarding is open, pls come to boarding area immediately. \n\nRegards, \nAA Airlines\n\n";

//Register the passenger in the observer list
void BoardingStatus::registerObserver(Observer *iPassenger) {
    m_passengers.emplace_back(iPassenger);
}

void BoardingStatus::deregisterObserver(Observer *iPassenger) {
    auto iterator = std::find(m_passengers.begin(), m_passengers.end(), iPassenger);
    //De-register/Remove the observer
    if (iterator != m_passengers.end()) {
        m_passengers.erase(iterator);
    }
}

// Notify all passengers who are Observing Boarding status update
void BoardingStatus::notifyObservers()
{
    for (Observer *aPassenger : m_passengers)
	{
        string sAlertMessage =  "Dear " + aPassenger->getPassengerName() + sBoardingAlertMsg;
        aPassenger->updateStatus(sAlertMessage);
    }
}

//Open/Close Boarding Gate
void BoardingStatus::setBoardingStatus(const bool& isBoardingOpen){

    m_isBoardingOpen = isBoardingOpen;
    //Alert passengers if boarding is open only
    if(m_isBoardingOpen)
    {
        notifyObservers();
    }
}
