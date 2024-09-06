//通用数组类
#pragma

#include <iostream>

using namespace std;

template<class T>
class Myarray {
public:

    //尾插法
    void Push_Back(const T &val)
    {
        //判断容量是否等于大小
        if(this->m_Capacity == this->size) {
            cout << "数组已满" << endl;
            return;
        }
        this->pAddress[this->size] = val;  //在数组末尾插入数据
        this->size++;  //更新数组大小
    }

    //尾删法
    void Pop_Back()
    {
        //让用户访问不到最后一个元素
        if(this->size == 0) {
            cout << "数组中已经没有数据了" << endl;
            return;
        }
        this->size--;
    }

    //通过下标的方式访问数组（重载 "[]"）
    T& operator[](int index)
    {
        return this->pAddress[index];
    }

    //返回数组的容量
    int get_Capacity()
    {
        return this->m_Capacity;
    }

    //返回数组的大小
    int get_size()
    {
        return this->size;
    }

//拷贝构造函数
    Myarray(const Myarray &arr)
    {
        this->m_Capacity = arr.m_Capacity;
        this->size = arr.size;
        //this->pAddress = arr.pAddress;  //浅拷贝
        this->pAddress = new T[arr.m_Capacity];  //需要重新开辟空间，即深拷贝

        //arr 中可能已经有数据了，还需要将数据拷贝过来
        for (int i = 0; i < arr.size; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

// operator=  重载 "=" 运算符，防止浅拷贝问题
    Myarray& operator=(const Myarray &arr)
    {
        //先判断原来堆区是否有数据，如果有需要先释放
        if(this->pAddress != NULL) {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->size = 0;
        }
        //深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->size = arr.size;
        this->pAddress =  new T[arr.m_Capacity];
        for (int i = 0; i < arr.size; i++) {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }

//有参构造
    Myarray(int capacity)
    {
        this->m_Capacity = capacity;
        this->size = 0;
        this->pAddress = new T[this->m_Capacity];
    }

    ~Myarray()
    {
        if(this->pAddress != NULL) {
            delete [] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T *pAddress;     //指针指向堆区开辟的真实数组
    int m_Capacity;  //数组容量
    int size;        //数组元素个数
};