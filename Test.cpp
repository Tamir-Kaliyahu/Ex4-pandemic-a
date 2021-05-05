#include "doctest.h"
#include <iostream>

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
using namespace std;


TEST_CASE("Test Board & OperationExpert basics"){
    Board board;
    OperationsExpert player {board, City::Bangkok};

    CHECK(board.is_clean());
    
    board[City::Bangkok] = 3;

    CHECK_FALSE(board.is_clean());

    CHECK_THROWS(player.drive(City::Tokyo));
    CHECK_NOTHROW(player.drive(City::Chennai));
    CHECK_FALSE(board.is_research(City::Chennai));
    CHECK_NOTHROW(player.build());
    CHECK(board.is_research(City::Chennai));
    CHECK_NOTHROW(player.drive(City::Kolkata));
    CHECK_NOTHROW(player.build());
    

}
TEST_CASE("Test Dispatcher"){
    Board board;
    Dispatcher player2 {board, City::Lima};
    CHECK_NOTHROW(player2.take_card(City::Lima));
    CHECK_THROWS(player2.fly_direct(City::Seoul));
    CHECK_NOTHROW(player2.build()); // now dispatcher can fly directly.
    CHECK_NOTHROW(player2.fly_direct(City::Paris));
}
    //player.take_card(City::Bogota).take_card(City::BuenosAires).take_card(City::Miami).take_card(City::MexicoCity);

TEST_CASE("Test Scientist, Researcher, GeneSplicer"){
    Board board;
    Scientist player3(board, City::Washington, 3);
    Researcher player4(board, City::Washington);
    GeneSplicer player7(board, City::Washington);

    player3.take_card(City::Madrid);
    player3.take_card(City::Montreal);
    CHECK_THROWS(player3.discover_cure(Color::Blue));
    player3.take_card(City::NewYork);
    CHECK_NOTHROW(player3.discover_cure(Color::Blue));
    player3.take_card(City::Chicago).take_card(City::Washington).take_card(City::Atlanta);
    CHECK_NOTHROW(player3.discover_cure(Color::Blue));

    player4.take_card(City::Bogota).take_card(City::BuenosAires).take_card(City::Miami).take_card(City::MexicoCity).take_card(City::LosAngeles);
    CHECK_NOTHROW(player4.discover_cure(Color::Yellow));

    player7.take_card(City::Washington);
    CHECK_NOTHROW(player7.build());
    player7.take_card(City::Karachi);
    player7.take_card(City::Paris);
    player7.take_card(City::Lagos);
    player7.take_card(City::Lima);
    player7.take_card(City::HongKong);
    CHECK_NOTHROW(player7.discover_cure(Color::Yellow));
    CHECK_THROWS(player7.discover_cure(Color::Blue));
 
}

 TEST_CASE("Test Medic 'Virologist, FieldDoctor"){

 Board board;
 	Medic player5(board, City::Washington);
    Virologist player6(board, City::Algiers);
    FieldDoctor player8(board, City::Washington);

    board[City::Montreal] = 5;
    board[City::Washington] = 2;
    board[City::Lima] = 4;
    board[City::NewYork] =3;
    board[City::Kinshasa]=2;

    CHECK_THROWS(player5.treat(City::Montreal));
    CHECK_NOTHROW(player5.treat(City::Washington));
    CHECK_EQ(board[City::Washington], 0);

    player5.take_card(City::Bogota).take_card(City::BuenosAires).take_card(City::Miami).take_card(City::MexicoCity).take_card(City::SaoPaulo);
    player5.discover_cure(Color::Yellow);

    player5.take_card(City::Miami);
    player5.build();
    CHECK_NOTHROW(player5.drive(City::Miami));
    CHECK_EQ(board[City::Lima], 0);

   
    player6.take_card(City::Washington);
    player6.take_card(City::Lima);
    CHECK_NOTHROW(player6.treat(City::Washington));
    CHECK_NOTHROW(player6.treat(City::Lima));
    CHECK_THROWS(player6.treat(City::Kinshasa));


    CHECK_NOTHROW(player8.treat(City::Montreal));
    CHECK_NOTHROW(player8.treat(City::NewYork));
    CHECK_EQ(board[City::Montreal], 4);
    CHECK_EQ(board[City::NewYork], 2);
    CHECK_NOTHROW(player8.drive(City::Miami));
    CHECK_THROWS(player8.treat(City::NewYork));

}
