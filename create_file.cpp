#include <iostream>
#include <fstream>
#include <string>
#include <random>

struct Point {
    std::string deviceType;
    std::string brand;
    std::string connectionType;
    std::string frequencyRange;
    int connectionSpeed;
    int numPorts;
};

int main() {
    std::ofstream file("point.dat", std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Unable to create file" << std::endl;
        return 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> speedDistribution(50, 1000);
    std::uniform_int_distribution<int> portsDistribution(1, 8);

    for (int i = 0; i < 20; ++i) {
        Point point;
        point.deviceType = "WiFi Router";
        point.brand = "Brand" + std::to_string(i + 1);
        point.connectionType = "Wireless";
        point.frequencyRange = "2.4 GHz";
        point.connectionSpeed = speedDistribution(gen);
        point.numPorts = portsDistribution(gen);

        file.write(reinterpret_cast<char*>(&point), sizeof(Point));
    }

    file.close();

    std::cout << "File point.dat successfully created with 20 random records." << std::endl;

    return 0;
}

