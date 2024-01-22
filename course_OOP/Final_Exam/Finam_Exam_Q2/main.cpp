#include "CApplicationType.h"

using namespace std;

int main()
{
	ApplicationType<int> app;

	try
	{
		app.run();
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}