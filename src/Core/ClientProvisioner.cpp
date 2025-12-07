#include "Core/ClientProvisioner.hpp"

ClientProvisioner::ClientProvisioner()
{
}

void ClientProvisioner::provisionClient()
{
    std::string clientName;

    Logger::Write("Enter client name: ");
    std::cin >> clientName;

    int isAuthEnabled;
    Logger::Write("Authentication is enabled? Y:N");
    std::cin >> isAuthEnabled;

    std::string username;
    std::string password;

    if (isAuthEnabled)
    {
        Logger::Write("Authentication is enabled? Y:N");
        std::cout << "Enter your client username: ";
        std::cin >> username;

        Logger::Write("Enter " + username + "'s password: ");
        std::cin >> password;
    }
}

void ClientProvisioner::deprovisionClient()
{
}

void ClientProvisioner::showClientStatus()
{
}

void ClientProvisioner::generateCert()
{
    int clientId;

    std::cout << "Enter ID that u want which client cert: ";

    std::ofstream cert;

    cert.open("", std::ios_base::app);
}
