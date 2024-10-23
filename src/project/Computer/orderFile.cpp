#include "orderFile.h"

void strFind(std::string &str, std::map<std::string, std::string> &m)
{
    int pos;
    std::string key;
    std::string value;
    pos = str.find(":");
    if(pos == -1) {
        return ;
    }
    key = str.substr(0, pos);
    value = str.substr(pos + 1, str.size() - pos - 1);

    m.insert(std::make_pair(key, value));
}

OrderFile::OrderFile()
{
    std::ifstream ifs;
    ifs.open(ORDER_FILE, std::ios::in);

    std::string date;
    std::string interval;
    std::string stuId;
    std::string stuName;
    std::string roomId;
    std::string status;

    this->m_Size = 0;  // 记录条数

    while (ifs >> date && ifs >> interval && ifs >> stuId \
            && ifs >> stuName && ifs >> roomId && ifs >> status) {

        std::map<std::string, std::string> m;

        strFind(date, m);
        strFind(interval, m);
        strFind(stuId, m);
        strFind(stuName, m);
        strFind(roomId, m);
        strFind(status, m);

    //  将小map容器放到大的 map 
        this->m_OrderData.insert(std::make_pair(this->m_Size, m));
        this->m_Size++;
    }
    ifs.close();
}

void OrderFile::updateOrder()
{
    if(this->m_Size == 0) {
        return ;
    }

//  将新的数据更新到文件中
    std::ofstream ofs(ORDER_FILE, std::ios::out | std::ios::trunc);
    for (size_t i = 0; i < this->m_Size; i++) {
        ofs << "date:" << this->m_OrderData[i]["date"] << " ";
        ofs << "interval:" << this->m_OrderData[i]["interval"] << " ";
        ofs << "stuId:" << this->m_OrderData[i]["stuId"] << " ";
        ofs << "stuName:" << this->m_OrderData[i]["stuName"] << " ";
        ofs << "roomId:" << this->m_OrderData[i]["roomId"] << " ";
        ofs << "status:" << this->m_OrderData[i]["status"] << std::endl;
    }
    ofs.close();
}