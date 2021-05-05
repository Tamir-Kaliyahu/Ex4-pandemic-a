#include "Player.hpp"


namespace pandemic{
    
    Player& Player::drive(City dest)
    {
        /*if(this->my_board.isNi(curr_city,dest))
        {
            curr_city=dest;
        }
        else
        {
            throw invalid_argument{"This destination is unreachable!"};
        }
        */
        return *this;
    }
    Player& Player::fly_direct(City dest)
    {
        return *this;
    }
    Player& Player::fly_charter(City dest)
    {
        return *this;
    }
    Player& Player::fly_shuttle(City dest)
    {
        return *this;
    }
    Player& Player::build()
    {
        return *this;
    }
    Player& Player::discover_cure(Color disease)
    {
        return *this;
    }
    Player& Player::treat(City c)
    {
        return *this;
    }
    Player& Player::take_card(City c)
    {
        return *this;
    }
    std::string Player::role()
    {
        return "";
    }
};