#include <iostream>
#include <fstream>
#include <string>

struct Point {
    std::string deviceType;
    std::string brand;
    std::string connectionType;
    std::string frequencyRange;
    int connectionSpeed;
    int numPorts;
};

int main() {
    std::ifstream file("point.dat", std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    Point point;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&point), sizeof(Point))) {
        if (point.connectionSpeed >= 300) {
            found = true;
            std::cout << "Device Type: " << point.deviceType << std::endl;
            std::cout << "Brand: " << point.brand << std::endl;
            std::cout << "Connection Type: " << point.connectionType << std::endl;
            std::cout << "Frequency Range: " << point.frequencyRange << std::endl;
            std::cout << "Connection Speed: " << point.connectionSpeed << " Mb/s" << std::endl;
            std::cout << "Number of Ports: " << point.numPorts << std::endl;
            std::cout << std::endl;
        }
    }

    file.close();

    if (!found) {
        std::cout << "No access points with a wireless connection speed of at least 300 Mb/s found." << std::endl;
    }

    return 0;
}
