#ifndef BOARDING_STATUS_HPP_
#define BOARDING_STATUS_HPP_

#include "Subject.hpp"
#include <vector>
#include <memory>

/**
 * A concrete implementation of the Observer DP Subject/Publisher interface
 * BoardingStatus is final - No class will be derived from BoardingStatus
 */
class BoardingStatus final : public Subject
{

public:

    BoardingStatus():m_isBoardingOpen(false)
    {
       //To avoid reallocation and faster processing
       //A flight can expect maximum of 300 passengers
       m_passengers.reserve(300);
    }
    void registerObserver(Observer* Observer) override;

    void deregisterObserver(Observer* Observer) override;

    void notifyObservers() override;

    ~BoardingStatus() {}

    /**
     * Set the new state of Flight Boarding Status
     */
    void setBoardingStatus(const bool& isBoardingOpen);

private:
        // Boarding status observing passengers
        std::vector<Observer*> m_passengers;
        bool m_isBoardingOpen;

};


#endif // BOARDING_STATUS_HPP_
