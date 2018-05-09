//
// Created by jachfili on 09.05.18.
//
#include <iostream>
#include <vector>
#include <string>
#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

namespace academia {

    class Serializable;
    class Serializer {
    public:
        Serializer(std::ostream *out);
        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;

        std::ostream *out;

    };

    class XmlSerializer: public Serializer
    {
        XmlSerializer(std::ostream *out);
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value)override;
        void StringField(const std::string &field_name, const std::string &value)override;
        void BooleanField(const std::string &field_name, bool value)override;
        void SerializableField(const std::string &field_name, const Serializable &value)override;
        void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value)override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name)override;
    };

    class Serializable{
        virtual void Serialize(Serializer* serializer)=0;
    };

    class Room: public Serializable
    {
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room(int id, std::string number, Type typ);
        void Serialize(Serializer* serializer) override;

    private:
        int id_;
        std::string number_;
        Type typ_;

    };

    class Building: public Serializable
    {
    public:
        Building(int id, std::string name, const Room &room);
        void Serialize(Serializer* serializer) override;

    private:
        int id_;
        std::string name_;
        Room room_;

    };




}

#endif //JIMP_EXERCISES_SERIALIZATION_H
