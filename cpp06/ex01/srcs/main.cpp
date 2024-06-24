#include "../includes/Serializer.hpp"

class Serializer;

int	main(void)
{
    std::cout << std::endl;
    Data data = {27, "Dupont", "Monique"};

    uintptr_t serializedData = Serializer::serialize(&data);

    Data* deserializedData = Serializer::deserialize(serializedData);

    if (deserializedData == &data) {
        std::cout << _FOREST_GREEN"Success! The deserialized pointer matches the original pointer." << _END << std::endl;
        std::cout << "Data: " << deserializedData->name << " " << deserializedData->surname << ", " << deserializedData->age << std::endl;
    } else {
        std::cout << _RED"Error: The deserialized pointer does not match the original pointer." << _END << std::endl;
    }
}
