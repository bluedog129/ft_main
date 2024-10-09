#include "Serializer.hpp"

int main() {
    Data dataObj;
    dataObj.num = 42;
    dataObj.decimal = 42.42;
    dataObj.text = "Hello world!";

    uintptr_t serializedData = Serializer::serialize(&dataObj);
    Data *deserializedData = Serializer::deserialize(serializedData);

    std::cout << "Original Pointer: " << &dataObj << std::endl;
    std::cout << "Serialized Pointer: " << serializedData << std::endl;
    std::cout << "Deserialized Pointer: " << deserializedData << std::endl;

    if (&dataObj == deserializedData)
        std::cout << "Success: Original and Deserialized pointers are the same" << std::endl;
    else
        std::cout << "Error: Pointers do not match!" << std::endl;

    return 0;
}