#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
 ����ó�� try(���ܰ� �߻��� �� �ִ� �ڵ�)
         catch(���ܰ� �߻��� ��� ���� �ڵ�)
int main()
{
   vector<int> v{ 1, 2, 3, 4 };
   try
   { //   cout << v[100] <<endl; // assertion fail �̰� try, catch �ᵵ �ȵ�
      cout << v.at(100) << endl; // abort() hasbeen called
   }
   catch (exception & e)
   {
      cout << e.what() << endl; // what(): � ���������� ���ڿ��� ���
   }

   cout << "Exit program" << endl;

   return 0;
}
*/

//
//class FileNotFound :
//   public exception // ����ó�� class�� exception ��� �ʼ�
//{
//private:
//   string message;
//public:
//   FileNotFound(string _filename) : message("File " + _filename + " not found") {}
//   virtual const char* what() const throw() // ����ó�� class ��� ��, override ��� throw()
//         //type�� ���� const   what()�� ���� const
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
//      throw FileNotFound(filename); // throw: ���� ����� catch��, catck �ȿ��� throw �ѹ� �� ����
//   }
//   else
//   {
//       //���Ϸκ��� element �о v�� ����
//   }
//}
//
//int main()
//{
//   try
//   {
//      vector<int> v = load_vector("vector.txt");
//   }
//   catch (FileNotFound & e) // FileNotFound -> exception ����ص� ��� X(�θ� Ŭ���� ��ü -> �������ε�)
//   {
//      cout << e.what() << endl;
//   }
//
//   return 0;
//}
