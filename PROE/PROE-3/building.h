#ifndef BUILDING_H
#define BUILDING_H
#include<string>
using namespace std;
enum BuldingType{
    detached,
    terraced,
    block,
    skyscraper
};

class Building
{
private:

    string owner_name;
    string type;
    int price;
    string picture_path;

public:
    Building(string _type = "DOM", int _price=0, string _owner_name="Jan Kowalski", string _path="");
    string return_type();
    int return_price();
    string return_owner_name();
    string return_picture_path();

};

#endif // BUILDING_H
