#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Girl;

class Boy {
public:
	Boy() { cout << "Boy 构造函数" << endl; }
	~Boy() { cout << "~Boy 析构函数" << endl; }

	void setGirlFriend(shared_ptr<Girl> _girlFriend) {
		this->girlFriend = _girlFriend;
	}
private:
	shared_ptr<Girl> girlFriend;
};

class Girl {
public:
	Girl() { cout << "Girl 构造函数" << endl; }
	~Girl() { cout << "~Girl 析构函数" << endl; }

	void setBoyFriend(shared_ptr<Boy> _boyFriend) {
		this->boyFriend = _boyFriend;
	}
private:
	shared_ptr<Boy> boyFriend;
};

void useTrap() {
	shared_ptr<Boy> spBoy(new Boy());
	shared_ptr<Girl> spGirl(new Girl());

	// 陷阱用法
	//spBoy->setGirlFriend(spGirl);  //spGirl used_count++ = 2
	spGirl->setBoyFriend(spBoy);   //spBoy  used_count++ = 2
	// 此时boy和girl的引用计数都是2
}

int main(void) {
	useTrap();
	return 0;
}
