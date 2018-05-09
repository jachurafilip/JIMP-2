
// Created by jachfili on 09.05.18.
//

#include "Serialization.h"

namespace academia
{

    std::string TypeToString(const Room::Type &typ)
    {
        switch(typ)
        {
            case Room::Type::COMPUTER_LAB:
                return "computer lab";
            case Room::Type::LECTURE_HALL:
                return  "other lab";
            case Room::Type::CLASSROOM:
                return "other lab2";
        }

    }

    Room::Room (int id, std::string number, Room::Type typ)
    {
        id_ = id;
        number_ = number;
        typ_ = typ;

    }

    void Room::Serialize (Serializer *serializer)
    {
        serializer -> Header("<room>");
        serializer -> IntegerField("id",id_);
        serializer -> StringField("number",number_);
        serializer ->StringField("type",TypeToString(typ_));
        serializer -> Footer("</room>");


    }

    Serializer::Serializer (std::ostream *out) {

    }

    Building::Building (int id, std::string name, const Room &room) :id_{id},name_{name},room_{room}
    {

    }
}
