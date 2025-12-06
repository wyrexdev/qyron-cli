#pragma once

#include <iostream>
#include <fstream>

#include "Cassandra/Scylla.hpp"

class ClientProvisioner
{
public:
    ClientProvisioner();

    void provisionClient();
    void deprovisionClient();
    void showClientStatus();

    void generateCert();

private:
    Scylla *scylla;
};