//#pragma once //library가 여러번 include되는것을 방지
////여러번 include될 경우 오류 발생(예: int a;가 여러번 선언됨)
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
////class는 선언부(.h)와 구현부(.cpp)로 나누어 관리 -> .h(메뉴판), .cpp(조리법)
////			-client에게 높은 가독성/사용 편리성 제공
//class Text
//{
//protected:
//	string text;
//public:
//	Text(string _t) : text(_t) {}
//	virtual string get() const = 0;
//	virtual void append(string _t) = 0;
//};
