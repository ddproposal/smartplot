#ifndef FILEDEVICE_H
#define FILEDEVICE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Dof_exDof
{
    int RoBdof;
    int exDof;
};

class FileDevice
{
public:
    FileDevice();
    std::vector<std::vector<double>> readSection(const std::string& filename, const std::string& sectionName);
    bool readPlotData(const std::string& optDataFile,
                      const std::string& smDataFile,
                      std::map<std::string, std::vector<std::vector<double>>>& optValues,
                      std::map<std::string, std::vector<std::vector<double>>>& smValues,
                      std::map<std::string, std::vector<std::vector<double>>>& velValues,
                      std::map<std::string, std::vector<std::vector<double>>>& accValues,
                      Dof_exDof& dof_exdof);
};

#endif // FILEDEVICE_H
