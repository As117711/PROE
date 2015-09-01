#include "building.h"

Building::Building(string _type, int _price, string _owner_name, string _path)
{
    type=_type;
    price=_price;
    owner_name=_owner_name;
    picture_path = _path;

}

string Building::return_type(){
    return type;
}

int Building::return_price(){
    return price;
}

string Building::return_owner_name(){
    return owner_name;
}

string Building::return_picture_path(){
    return picture_path;
}

