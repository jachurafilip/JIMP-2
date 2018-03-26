//
// Created by filip on 26.03.18.
//

#include "SimpleJson.h"

namespace nets
{

    JsonValue::JsonValue(const char *) {

    }

    JsonValue::JsonValue(int) {

    }

    JsonValue::JsonValue(bool) {

    }

    JsonValue::JsonValue(std::string) {

    }

    JsonValue::JsonValue(double) {

    }

    JsonValue::JsonValue(std::map<std::string, JsonValue>) {

    }

    JsonValue::JsonValue(std::vector<JsonValue>) {

    }

    JsonValue::~JsonValue() {

    }

    std::experimental::optional<JsonValue> JsonValue::ValueByName(const std::string &name) const {
        return std::experimental::optional<JsonValue>();
    }

    std::string JsonValue::ToString() const {
        return std::__cxx11::string();
    }
}