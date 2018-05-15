
// Created by jachfili on 09.05.18.
//

#include <functional>
#include "Serialization.h"

namespace academia
{

    std::string TypeToString(const Room::Type &typ)
    {
        switch(typ)
        {
            case Room::Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Room::Type::LECTURE_HALL:
                return  "LECTURE_HALL";
            case Room::Type::CLASSROOM:
                return "CLASSROOM";
        }

    }

    Room::Room (int id, std::string number, Room::Type typ) : id_{id},number_{number},typ_{typ} {}

    void Room::Serialize (Serializer *serializer) const
    {
        serializer -> Header("room");
        serializer -> IntegerField("id",id_);
        serializer -> StringField("name",number_);
        serializer ->StringField("type",TypeToString(typ_));
        serializer -> Footer("room");

    }
    void Room::Serialize (Serializer *serializer)
    {
        serializer -> Header("room");
        serializer -> IntegerField("id",id_);
        serializer -> StringField("name",number_);
        serializer ->StringField("type",TypeToString(typ_));
        serializer -> Footer("room");

    }

    int Room::Id() const {
        return id_;
    }

    Serializer::Serializer (std::ostream *out) {
        out_ = out;

    }

    Building::Building (int id, std::string name, std::initializer_list<const Room> rooms) :id_{id},name_{name}
    {
        for(auto &v: rooms)
        {
            rooms_.emplace_back(v);
        }

    }

    void Building::Serialize(Serializer *serializer) const
    {
        serializer -> Header("building");
        serializer -> IntegerField("id",id_);
        serializer -> StringField("name",name_);
        serializer -> ArrayField("rooms",Wrap());
        serializer -> Footer("building");
    }
    void Building::Serialize(Serializer *serializer)
    {
        serializer -> Header("building");
        serializer -> IntegerField("id",id_);
        serializer -> StringField("name",name_);
        serializer -> ArrayField("rooms",Wrap());
        serializer -> Footer("building");
    }

    std::vector<std::reference_wrapper<const Serializable>> Building::Wrap() const {
        std::vector<std::reference_wrapper<const Serializable>> output;
        for (auto &v: rooms_)
        {
            output.emplace_back(std::cref(v));
        }
        return output;
    }

    int Building::Id() const {
        return id_;
    }

    XmlSerializer::XmlSerializer(std::ostream *out) : Serializer(out) {}

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *(out_)<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *(out_)<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *(out_)<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        *(out_)<<"<"<<field_name<<">"<<value<<"<\\"<<field_name<<">";

    }

    void XmlSerializer::SerializableField(const std::string &field_name, const Serializable &value) {
        value.Serialize(this);
    }

    void XmlSerializer::ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value)
    {
        *(out_)<<"<"<<field_name<<">";
        for(auto v: value)
        {
            SerializableField(field_name,v.get());
        }

        *(out_)<<"<\\"<<field_name<<">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *(out_)<<"<"<<object_name<<">";

    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *(out_)<<"<\\"<<object_name<<">";
    }

    JsonSerializer::JsonSerializer(std::ostream *out) : Serializer(out) {}

    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        isFirst();
        *out_<<"\""<<field_name<<"\": "<<value;

    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {
        isFirst();
        *out_<<"\""<<field_name<<"\": "<<value;

    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        isFirst();
        *out_<<"\""<<field_name<<"\": \""<<value<<"\"";

    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
        isFirst();
        *(out_)<<"\""<<field_name<<"\": \"";
        if (value)
            *out_<<"true";
        else
            *out_<<"false";
        *(out_)<<"\"";


    }

    void JsonSerializer::SerializableField(const std::string &field_name, const Serializable &value)
    {
        isFirst();
        *out_<<"\""<<field_name<<"\": \"";
        value.Serialize(this);

    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const Serializable>> &value)
    {
        isFirst();
        *(out_)<<"\""<<field_name<<"\": [";
        for(int i = 0; i<value.size();i++)
        {
            first_ = true;
            if(i==0)
            {

                value[0].get().Serialize(this);
            }
            else {
                *out_<<", ";
                value[i].get().Serialize(this);
            }
        }

        *(out_)<<"]";

    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_<<"{";

    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_<<"}";
    }

    void JsonSerializer::isFirst()
    {
        if(first_)
        {
            first_= false;
        } else
        {
            *out_<<", ";
        }
    }

    BuildingRepository::BuildingRepository(std::initializer_list<Building> buildings)
    {
        for(auto &v: buildings)
        {
            buildings_.emplace_back(v);
        }

    }

    void BuildingRepository::Add(const Building &new_building)
    {

        buildings_.emplace_back(new_building);

    }

    void BuildingRepository::StoreAll(Serializer *serializer)
    {
        serializer->Header("building_repository");
        serializer -> ArrayField("buildings",Wrap2());
        serializer -> Footer("building repository");
    }

    std::vector<std::reference_wrapper<const Serializable>> BuildingRepository::Wrap2() const {
        std::vector<std::reference_wrapper<const Serializable>> output;
        for (auto &v: buildings_)
        {
            output.emplace_back(std::cref(v));
        }
        return output;
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int id) const {
        for (auto v: buildings_)
        {
            if(v.Id()==id)
            {
                return v;
            }
        }
    }
}
