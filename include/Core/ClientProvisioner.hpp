#pragma once

#include <iostream>
#include <fstream>

#include "Utils/Logger.hpp"

class ClientProvisioner
{
public:
    ClientProvisioner();

    void provisionClient();
    void deprovisionClient();
    void showClientStatus();

    void generateCert();

private:
};