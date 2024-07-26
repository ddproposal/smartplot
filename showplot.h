#ifndef SHOWPLOT_H
#define SHOWPLOT_H

#include <iostream>
#include <vector>
#include <map>

#include "filedevice.h"


#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;


typedef std::map<std::string, std::vector<std::vector<double>>> map_inf;

class Showplot
{
public:
    Showplot(map_inf opt ,
             map_inf sm  ,
             map_inf vel ,
             map_inf acc ,
             Dof_exDof df);
    //速度圖
    void ShowRobotvelplot();
    void ShowAxisvelplot();
    //加速度圖
    void ShowAxisaccplot();
    void ShowRobotaccplot();

    //具體數據
    void Show_optsm_plot(const std::map<std::string, std::vector<std::vector<double>>>& opt, bool showRobot);

private:
    map_inf m_opt;
    map_inf m_sm;
    map_inf m_vel;
    map_inf m_acc;
    Dof_exDof m_df;

};

#endif // SHOWPLOT_H
