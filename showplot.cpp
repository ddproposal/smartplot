#include "showplot.h"



Showplot::Showplot(map_inf opt, map_inf sm, map_inf vel, map_inf acc, Dof_exDof df):m_opt(opt),m_sm(sm),m_vel(vel),m_acc(acc),m_df(df)
{

}

void Showplot::ShowRobotvelplot()
{
    plt::figure();
    int scan_cnt=0,weld_cnt=0;
    for(const auto& pair : m_vel)
    {
        int j=1;
        //新建一個窗口
        if(scan_cnt==1 && weld_cnt == 1)
        {
            scan_cnt=0,weld_cnt=0;
            plt::figure();
        }
        //分两列，左侧扫描右侧焊接
        if(pair.first.find("SCAN") != string::npos)
        {
            plt::subplot2grid(1,2,scan_cnt++,0);
            plt::title(pair.first + " Vel");
            for(unsigned long i = m_df.exDof ; i < pair.second.size() ; i++)
            {

                plt::named_plot("J"+std::to_string(j++),pair.second.at(i));
            }
            plt::grid(true);
        }else if(pair.first.find("WELD") != string::npos){

            plt::subplot2grid(1,2,weld_cnt++,1);
            plt::title(pair.first + " Vel");

            for(unsigned long i = m_df.exDof ; i < pair.second.size() ; i++)
            {
                plt::named_plot("J"+std::to_string(j++),pair.second.at(i));
            }
            plt::grid(true);
        }
        //显示图例
        plt::legend();

    }

}

void Showplot::ShowAxisvelplot()
{
    plt::figure();
    vector<std::string> extname = {"Vx","Vy","Vz"}; //顯示圖例外部軸名稱


    int scan_cnt=0,weld_cnt=0;
    for(const auto& pair : m_vel)
    {
        if(scan_cnt ==1 && weld_cnt ==1)
        {
            scan_cnt=0,weld_cnt=0;
            plt::figure();
        }
        //分两列，左侧扫描右侧焊接
        if(pair.first.find("SCAN") != string::npos)
        {
            plt::subplot2grid(1,2,scan_cnt++,0);
            plt::title(pair.first + " Vel");
            for(int i = 0 ; i < m_df.exDof ; i++)
            {

                plt::named_plot(extname[i],pair.second.at(i));
            }
            plt::grid(true);
        }else if(pair.first.find("WELD") != string::npos){

            plt::subplot2grid(1,2,weld_cnt++,1);
            plt::title(pair.first + " Vel");

            for(int i = 0 ; i < m_df.exDof ; i++)
            {
                plt::named_plot(extname[i],pair.second.at(i));
            }
            plt::grid(true);
        }
        //显示图例
        plt::legend();
    }

}

void Showplot::ShowAxisaccplot()
{
    plt::figure();
    vector<std::string> extname = {"Ax","Ay","Az"}; //顯示圖例外部軸名稱


    int scan_cnt=0,weld_cnt=0;
    for(const auto& pair : m_acc)
    {
        if(scan_cnt ==1 && weld_cnt ==1)
        {
            scan_cnt=0,weld_cnt=0;
            plt::figure();
        }
        //分两列，左侧扫描右侧焊接
        if(pair.first.find("SCAN") != string::npos)
        {
            plt::subplot2grid(1,2,scan_cnt++,0);
            plt::title(pair.first  + " ACC");
            for(int i = 0 ; i < m_df.exDof ; i++)
            {

                plt::named_plot(extname[i],pair.second.at(i));
            }
            plt::grid(true);
        }else if(pair.first.find("WELD") != string::npos){

            plt::subplot2grid(1,2,weld_cnt++,1);
            plt::title(pair.first  + " ACC");

            for(int i = 0 ; i < m_df.exDof ; i++)
            {
                plt::named_plot(extname[i],pair.second.at(i));
            }
            plt::grid(true);
        }
        //显示图例
        plt::legend();
    }
}

void Showplot::ShowRobotaccplot()
{
    plt::figure();

    int scan_cnt=0,weld_cnt=0;
    for(const auto& pair : m_acc)
    {
        int j=1;
        //分两列，左侧扫描右侧焊接
        if(pair.first.find("SCAN") != string::npos)
        {
            if(scan_cnt ==1 && weld_cnt ==1)
            {
                scan_cnt=0,weld_cnt=0;
                plt::figure();
            }
            plt::subplot2grid(1,2,scan_cnt++,0);
            plt::title(pair.first + " ACC");
            for(unsigned long i = m_df.exDof ; i < pair.second.size() ; i++)
            {

                plt::named_plot("J"+std::to_string(j++),pair.second.at(i));
            }
            plt::grid(true);
        }else if(pair.first.find("WELD") != string::npos){

            plt::subplot2grid(1,2,weld_cnt++,1);
            plt::title(pair.first + " ACC");

            for(unsigned long i = m_df.exDof ; i < pair.second.size() ; i++)
            {
                plt::named_plot("J"+std::to_string(j++),pair.second.at(i));
            }
            plt::grid(true);
        }
        //显示图例
        plt::legend();
    }

}

void Showplot::Show_optsm_plot(const std::map<std::string, std::vector<std::vector<double>>>& opt, bool showRobot)
{
    vector<std::string> extname = {"X","Y","Z"};
    for(const auto& pair : opt)
    {
        int cnt = 0 ;
        std::cout << "Name: " << pair.first << std::endl;
        plt::figure();
        //打印标题
        plt::title(pair.first+ " Data Plot");

        if(showRobot==true)
        {
            cnt = m_df.exDof;
            //绘画机器人plot
            for(int i= 0 ; i< m_df.RoBdof ; i++)
            {
                plt::named_plot("Rob"+std::to_string(i+1),pair.second[cnt++],"--");
            }

        }else{
            //绘画外部轴plot
            for(int i= 0 ; i< m_df.exDof ; i++)
            {
                plt::named_plot(extname[i],pair.second[cnt++]);
            }
        }

        plt::grid(true);

        //显示图例
        plt::legend();

    }
}
