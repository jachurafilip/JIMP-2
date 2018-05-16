//
// Created by jachfili on 09.05.18.
//
#include <iostream>
#include <vector>
#include <string>
#include <experimental/optional>

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

namespace academia {

    class Serializable;
    class Serializer {
    public:
        explicit Serializer(std::ostream *out);
        virtual ~Serializer() = default;
        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;

    protected:
        std::ostream *out_;

    };

    class XmlSerializer: public Serializer
    {
    public:
        explicit XmlSerializer(std::ostream *out);
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value)override;
        void StringField(const std::string &field_name, const std::string &value)override;
        void BooleanField(const std::string &field_name, bool value)override;
        void SerializableField(const std::string &field_name, const Serializable &value)override;
        void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value)override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name)override;
    };

    class JsonSerializer: public Serializer
    {
    public:
        explicit JsonSerializer(std::ostream *out);
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value)override;
        void StringField(const std::string &field_name, const std::string &value)override;
        void BooleanField(const std::string &field_name, bool value)override;
        void SerializableField(const std::string &field_name, const Serializable &value)override;
        void ArrayField(const std::string &field_name, const std::vector<std::reference_wrapper<const Serializable>> &value)override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name)override;
        void isFirst();

    protected:
        bool first_ = true;
    };

    class Serializable{
    public:
        virtual ~Serializable()= default;
        virtual void Serialize(Serializer* serializer)const=0;
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
        ~Room() override = default;
        void Serialize(Serializer* serializer)const override;
        void Serialize(Serializer* serializer) override;
        int Id()const;


    private:
        int id_;
        std::string number_;
        Type typ_;

    };

    class Building: public Serializable
    {
    public:
        Building(int id, std::string name, const std::initializer_list<const Room> rooms);
        void Serialize(Serializer* serializer)const override;
        void Serialize(Serializer* serializer) override;
        std::vector<std::reference_wrapper<const Serializable>> Wrap() const;
        int Id()const;

        ~Building() override = default;

    private:
        int id_;
        std::string name_;
        std::vector<Room> rooms_;

    };

    class BuildingRepository{
    public:
        BuildingRepository(std::initializer_list<Building> buildings);
        void Add(const Building &new_building);
        void StoreAll(Serializer *serializer);
        std::vector<std::reference_wrapper<const Serializable>> Wrap2() const;
        std::experimental::optional<Building> operator[](int id) const;

    private:
        std::vector<Building> buildings_;

    };




}

#endif //JIMP_EXERCISES_SERIALIZATION_H
