#pragma once
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdbool.h>
#include "Color.hpp"
#include "City.hpp"

using namespace std;

namespace pandemic{

    class Board{
        
        protected:
            std::map<City, std::set<City>> Ni_Cities;
            map<enum Color, bool> Cured_Des;          // found cure per color
            std::map<City, bool> research_station; 
            std::map<City, int> SicknessL;
            map<City, Color> CityColors; 
        public:
            Board()
            {
                initBoard("cities_map.txt");
            }
            ~Board(){};
            
            void initBoard (const std::string &filename);
            int& operator[] (City CityA); 
            friend std::ostream& operator<<(std::ostream& os, const Board& BoardA);
            bool is_clean();
            void remove_cures();

            bool isNi(City c,City c2);
            Color CityColor(City c);
            static City ConvtoE(const std::string &str);
            static std::string Convtostr(City C);
            static std::string ConvColor(Color C);
            bool is_research(City c);
            
            
    };
}
