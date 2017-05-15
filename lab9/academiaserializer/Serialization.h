//
// Created by DELL on 04.05.2017.
//
#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H


#include<iostream>
#include<string>
#include <vector>
#include <initializer_list>
#include <sstream>
#include <functional>
#include <experimental/optional>
#include <memory>

namespace academia {
    class Serializable;
    class Serializer {
    public:
        Serializer();
        Serializer(std::ostream *);
        virtual ~Serializer();
        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;
    protected:
        std::ostream *out_;
    };

    class Serializable{
    public:
        virtual void Serialize(Serializer*) const=0;
};

    class JsonSerializer:public Serializer{
    public:
        JsonSerializer();
        virtual ~JsonSerializer();
        JsonSerializer(std::ostream *out):Serializer(out){}
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;

    };

    class XmlSerializer:public Serializer{
    public:
        XmlSerializer();
        virtual ~XmlSerializer();
        XmlSerializer(std::ostream *out):Serializer(out){}
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    };
    class Room:public Serializable {
    public:
        Room();

        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };

        void Serialize(Serializer *) const override;

        std::string TypeToString(Type type) const;

        Room(int id, std::string number, Type classroom) : id_(id), number_(number), classroom_(classroom) {};

        ~Room();

    private:
        int id_;
        std::string number_;
        Type classroom_;
    };

    class Building:public Serializable{
    public:
        Building();
        virtual ~Building();
        Building(int id, std::string number, std::initializer_list<Room> room):
                id_(id), number_(number), room_(room){} ;
        void Serialize(Serializer*) const override;
        int Id() const;
    private:
        int id_;
        std::string number_;
        std::vector<Room> room_;
    };



    class BuildingRepository{
    public:
        BuildingRepository();
        BuildingRepository(const std::initializer_list<Building> &building_list):building_list_(building_list){};
        ~BuildingRepository();
        void StoreAll(Serializer *serializer) const;
        std::experimental::optional<Building> operator[](int id) const;
        void Add(const Building &building);
    private:
        std::vector<Building> building_list_;
    };
}

#endif //JIMP_EXERCISES_SERIALIZATION_H