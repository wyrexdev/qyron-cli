#include "Core/ClientProvisioner.hpp"

ClientProvisioner::ClientProvisioner() {
    scylla = new Scylla("", {
        username: "",
        password: ""
    });

    scylla->Connect();
}

void ClientProvisioner::provisionClient() {
    std::string clientName;

    std::cout << "Enter your client name: ";
    std::cin >> clientName;

    int isAuthEnabled;
    std::cout << "Authentication is enabled? 0: Disabled, 1: Enabled";
    std::cin >> isAuthEnabled;

    std::string username;
    std::string password;

    if(isAuthEnabled) {
        std::cout << "Enter your client username: ";
        std::cin >> username;

        std::cout << "Enter " << username << "'s password: ";
        std::cin >> password;
    }
}

void ClientProvisioner::deprovisionClient() {

}

void ClientProvisioner::showClientStatus() {

}

void ClientProvisioner::generateCert() {
    int clientId;

    std::cout << "Enter ID that u want which client cert: ";

    std::ofstream cert;

    cert.open("", std::ios_base::app);
}
