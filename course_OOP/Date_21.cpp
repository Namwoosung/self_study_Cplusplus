#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
 예외처리 try(예외가 발생할 수 있는 코드)
         catch(예외가 발생한 경우 수행 코드)
int main()
{
   vector<int> v{ 1, 2, 3, 4 };
   try
   { //   cout << v[100] <<endl; // assertion fail 이건 try, catch 써도 안됨
      cout << v.at(100) << endl; // abort() hasbeen called
   }
   catch (exception & e)
   {
      cout << e.what() << endl; // what(): 어떤 오류인지를 문자열로 출력
   }

   cout << "Exit program" << endl;

   return 0;
}
*/

//
//class FileNotFound :
//   public exception // 예외처리 class는 exception 상속 필수
//{
//private:
//   string message;
//public:
//   FileNotFound(string _filename) : message("File " + _filename + " not found") {}
//   virtual const char* what() const throw() // 예외처리 class 상속 시, override 대신 throw()
//         //type에 대한 const   what()에 대한 const
//   {
//      return message.c_str(); // c_str(): string -> const char*
//   }
//};
//
//vector<int> load_vector(string filename)
//{
//   vector<int> v;
//   ifstream fin(filename);
//   if (!fin)
//   {
//      throw FileNotFound(filename); // throw: 가장 가까운 catch로, catck 안에서 throw 한번 더 가능
//   }
//   else
//   {
//       //파일로부터 element 읽어서 v에 저장
//   }
//}
//
//int main()
//{
//   try
//   {
//      vector<int> v = load_vector("vector.txt");
//   }
//   catch (FileNotFound & e) // FileNotFound -> exception 사용해도 상관 X(부모 클래스 객체 -> 동적바인딩)
//   {
//      cout << e.what() << endl;
//   }
//
//   return 0;
//}
