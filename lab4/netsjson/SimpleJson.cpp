//
// Created by filip on 26.03.18.
//

#include "SimpleJson.h"

using std::string;
using std::map;
using std::vector;
using std::experimental::optional;
namespace nets
{

    JsonValue::JsonValue(const char * text)
    {
        integer_ = nullptr;
        double_ = nullptr;
        boolean_ = nullptr;
        string_ = new string;
        *string_ = text;
        map_ = nullptr;
        vector_ = nullptr;

    }

    JsonValue::JsonValue(int text)
    {
        integer_ = new int;
        *integer_ = text;
        double_ = nullptr;
        boolean_ = nullptr;
        string_ = nullptr;
        map_ = nullptr;
        vector_ = nullptr;
    }

    JsonValue::JsonValue(bool text)
    {
        integer_ = nullptr;
        double_ = nullptr;
        boolean_ = new bool;
        *boolean_=text;
        string_ = nullptr;
        map_ = nullptr;
        vector_ = nullptr;
    }

    JsonValue::JsonValue(string text)
    {
        integer_ = nullptr;
        double_ = nullptr;
        boolean_ = nullptr;
        string_ = new string;
        *string_ = text;
        map_ = nullptr;
        vector_ = nullptr;
    }

    JsonValue::JsonValue(double text)
    {
        integer_ = nullptr;
        double_ = new double;
        *double_=text;
        boolean_ = nullptr;
        string_ = nullptr;
        map_ = nullptr;
        vector_ = nullptr;
    }

    JsonValue::JsonValue(const map<string, JsonValue> &text)
    {
        integer_ = nullptr;
        double_ = nullptr;
        boolean_ = nullptr;
        string_ = nullptr;
        map_ = new map<string,JsonValue>;
        *map_ = text;
        vector_ = nullptr;
    }

    JsonValue::JsonValue(const vector<JsonValue> &text)
    {
        integer_ = nullptr;
        double_ = nullptr;
        boolean_ = nullptr;
        string_ = nullptr;
        map_ = nullptr;
        vector_ = new vector<JsonValue>;
        *vector_ = text;

    }
    JsonValue::~JsonValue()
    {
            if(integer_ != nullptr){
                integer_= nullptr;
                delete(integer_);
            }
            if(double_ != nullptr) {
                double_ = nullptr;
                delete(double_);
            }
            if(boolean_!= nullptr) {
                boolean_= nullptr;
                delete(boolean_);
            }
            if(string_ != nullptr) {
                string_ = nullptr;
                delete(string_);
            }
            if(map_ != nullptr) {
                map_ = nullptr;
                delete(map_);
            }
            if(vector_ != nullptr) {
                vector_ = nullptr;
                delete(vector_);
            }

    }


    optional<JsonValue> JsonValue::ValueByName(const string &name) const
    {
        for (auto &v: *map_)
        {
            if(!(v.first.compare(name)))
            {
                return std::experimental::make_optional(v.second);
            }
        }
        return {};
    }

    string JsonValue::ToString() const
    {
        std::stringstream stream;
        string output ="";

        if(integer_!= nullptr)
        {
            stream<<*integer_;
            stream>>output;
            return output;
        }
        if(double_!= nullptr)
        {
            stream<<*double_;
            stream>>output;
            return output;
        }
        if(boolean_!= nullptr)
        {
            if(*boolean_) return "true";
            return "false";
        }
        if(vector_ != nullptr){
            output += '[';
            for(auto n  : *vector_ ){
                output+=n.ToString();
                output+=", ";
            }
            output.erase(output.length() - 2, 2);
            output += ']';
            return output;
        }

        if(map_ != nullptr){
            output += '{';
            for( auto &n : *map_){
                JsonValue tmp(n.first);
                output += tmp.ToString();
                output += ": ";
                output += n.second.ToString();
                output += ", ";
            }
            output.erase(output.length()-2,2);
            output += '}';
            return output;
        }
        if(string_ != nullptr){
            std::string copy = *string_;
            output += '\"';
            for(int i = 0 ; i < copy.length() ; i++){
                if(copy[i] == '\\' || copy[i] == '\"'){
                    output += '\\';
                }
                output += copy[i];
            }

            output += '\"';
            return output;
        }

        return "";



    }


}