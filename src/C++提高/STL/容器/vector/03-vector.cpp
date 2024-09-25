/*
  Vector容器嵌套容器
  vector 类似于数组，而在 vector 中嵌套一个 vector 则相当于一个二维数组
*/

#include<iostream>
#include<vector>

void test01()
{
//容器嵌套容器
    std::vector<std::vector<int>>v;

    std::vector<int>v1;
    std::vector<int>v2;
    std::vector<int>v3;

//向小容器中添加数据
	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
	}

//将小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

//通过大容器遍历所有数据
    for (std::vector<std::vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
        for (std::vector<int>::iterator ite = (*it).begin(); ite != (*it).end(); ite++) {
            std::cout << *ite << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    test01();
    return 0;
}