#include "conversion.hpp"

int	main(void) {
	Data		data;
	uintptr_t	u;
	Data*		des_data;

	data.name = "Nobody Owens";
	data.age = 13;
	data.height = 1.81f;
	
	std::cout << "START" << std::endl;
	std::cout << data.name << ", " << data.age << " years old, "
			  << data.height << " m high." << std::endl
			  << "Address: " << &data << std::endl;
	
	u = serialize(&data);
	std::cout << std::endl << "SERIALIZED" << std::endl;
	std::cout << u << std::endl << "Address: " << &u << std::endl;

	des_data = deserialize(u);
	std::cout << std::endl << "DESERIALIZED" << std::endl;
	std::cout << des_data->name << ", " << des_data->age << " years old, "
			  << des_data->height << " m high." << std::endl
			  << "Address: " << des_data << std::endl;

	return (0);
}
