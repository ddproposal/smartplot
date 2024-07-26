#include "filedevice.h"

FileDevice::FileDevice()
{

}

std::vector<std::vector<double>> FileDevice::readSection(const std::string& filename, const std::string& sectionName) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return {};
    }

    std::vector<std::vector<double>> data;
    std::string line;
    bool reading = false;

    while (std::getline(file, line)) {
        if (line.find(sectionName) != std::string::npos) {
            reading = true;
            continue;
        }

        if (reading && !line.empty() && line != sectionName) {
            std::istringstream iss(line);
            std::vector<double> row;
            std::string value;

            while (iss >> value) {
                double val =std::stod(value);
                row.push_back(val);
            }
            data.push_back(row);
        }
    }

    file.close();
    return data;
}


struct DataLabel
{
    std::string name;
    std::string type;
    std::string makeLabel() {
        return name+"_"+type;
    }
};



bool FileDevice::readPlotData(const std::string& optDataFile,
                  const std::string& smDataFile,
                  std::map<std::string, std::vector<std::vector<double>>>& optValues,
                  std::map<std::string, std::vector<std::vector<double>>>& smValues,
                  std::map<std::string, std::vector<std::vector<double>>>& velValues,
                  std::map<std::string, std::vector<std::vector<double>>>& accValues,
                  Dof_exDof& dof_exdof)
{
    //std::vector<double> robotlimit={1.754,2.2689,3.4907,3.8397,2.0944,4.4633};

    ifstream odf(optDataFile);
    ifstream sdf(smDataFile);

    std::string line;
    if ((!odf.is_open()) ||(!sdf.is_open()) ) {
        std::cout << "Error opening files" << std::endl;
        return false;
    }
    int dof, extDOF;
    string label;
    vector<vector<double>> temp;
    int n = 0;
    while (getline(odf, line)) {
        // Check if line is a description line
        if ((line.find("SCAN") != std::string::npos) ||
            (line.find("WELD") != std::string::npos)) {
            DataLabel dl;
            std::istringstream iss(line);
            string oxx;
            bool flag=false;int cnt=0;
            while (std::getline(iss,oxx,' ')) {
                //cout<<oxx<<endl;
                if(oxx.empty()) continue;
                if(!(oxx.find("SCAN")!=string::npos || oxx.find("WELD")!=string::npos) && flag==false)
                {
                  dl.name += oxx;

                }else{
                    flag=true;
                    switch (cnt++) {
                        case 0 : dl.type=oxx;break;
                        case 1 : dof=stoi(oxx);break;
                        case 2: extDOF=stoi(oxx);break;
                    }
                }

            }

            //iss >> dl.name >> dl.type >> dof >> extDOF;
            dof_exdof.RoBdof = dof-extDOF-3;
            dof_exdof.exDof = extDOF;

            if ( n > 0 ) optValues[label] = temp;
            // Read the actual data lines based on the count
            label = dl.makeLabel();
            temp.clear();
            temp.resize(dof);
            n++;
        }
        else {
            std::istringstream dataStream(line);
            double num;
            int i = 0;
            while (dataStream >> num) {
                temp[i].push_back(num);
                i++;
            }
        }
    }
    optValues[label] = temp;
    odf.close();
    n = 0;
    temp.clear();
    vector<vector<double>> tempv, tempa;
    while (getline(sdf, line)) {
        // Check if line is a description line
        if ((line.find("SCAN") != std::string::npos) ||
            (line.find("WELD") != std::string::npos)) {
            DataLabel dl;
            std::istringstream iss(line);

            string oxx;
            bool flag=false;int cnt=0;
            while (std::getline(iss,oxx,' ')) {
                //cout<<oxx<<endl;
                if(oxx.empty()) continue;
                if(!(oxx.find("SCAN")!=string::npos || oxx.find("WELD")!=string::npos) && flag==false)
                {
                  dl.name += oxx;

                }else{
                    flag=true;
                    switch (cnt++) {
                        case 0 : dl.type=oxx;break;
                        case 1 : dof=stoi(oxx);break;
                        case 2: extDOF=stoi(oxx);break;
                    }
                }

            }
            dof_exdof.RoBdof = dof-extDOF-3;
            dof_exdof.exDof = extDOF;
            //iss >> dl.name >> dl.type >> dof >> extDOF;
            if ( n > 0 ) {
                smValues[label] = temp;
                velValues[label] = tempv;
                accValues[label] = tempa;
            }

            label = dl.makeLabel();
            temp.clear();
            temp.resize(dof);
            tempv.clear();
            tempv.resize(dof);
            tempa.clear();
            tempa.resize(dof);
            n++;
        }
        else {
            std::istringstream dataStream(line);
            double num;
            int i = 0;
            while (dataStream >> num) {
                if ( i < dof ) {
                    temp[i].push_back(num);
                    i++;
                }
                else if ( i < 2*dof) {
                    tempv[i-dof].push_back(num);
                    i++;
                }
                else if ( i < 3*dof) {
                    tempa[i-2*dof].push_back(num);
                    i++;
                }
            }
        }
    }
    smValues[label] = temp;
    velValues[label] = tempv;
    accValues[label] = tempa;
    return true;

}
