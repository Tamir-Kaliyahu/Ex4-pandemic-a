#pragma once
#include "City.hpp"
#include "Board.hpp"

namespace pandemic{
    
    class Player{
        protected:
            std::string Player_role;
            Board& my_board;
            City curr_city;
            map<enum City, int> cards;
        
        public:
            Player(Board& BoardA ,City c, std::string role): my_board(BoardA), curr_city(c), Player_role(role){}
            virtual Player& drive(City dest);
            virtual Player& fly_direct(City dest);
            virtual Player& fly_charter(City dest);
            virtual Player& fly_shuttle(City dest);
            virtual Player& build();
            virtual Player& discover_cure(Color disease);
            static std::string role();
            virtual Player& treat(City c);
            virtual Player& take_card(City c);

           
    };
}
