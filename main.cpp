/// App using the Arugments class
#include <iostream>

#include "Arguments.h"


int main( int argc, char* argv[] )
{
    using namespace std;

    try
    {
        Arguments args(argc, argv);
		Arguments args2(args);
		Arguments args3(args);
		args3 = args2;

		cout << args.count() << endl;

        for ( int i = 0; i < args.count(); ++i )
        {
            cout << args[i] << endl;
        }
		
		//print the copy constructor 
		cout << "copy constructor" << endl;
		cout << args2.count() << endl;
        for ( int i = 0; i < args2.count(); ++i )
        {
            cout << args2[i] << endl;
        }
		
		//print the object using = operator
		cout << "copy constructor using operator =" << endl;
		cout << args3.count() << endl;
        for ( int i = 0; i < args3.count(); ++i )
        {
            cout << args3[i] << endl;
        }
    }
    /// This will catch throws from the try block with an integer param
    catch (int e)
    {
        cerr << "Construction error occured..." << endl;
    }
	
    /// This will catch throws from the try block with a size_t param
    catch (size_t e)
    {
        cerr << "Out of range error occured ..." << endl;
    }

    cout << "Ending application... " << endl;
    return 0;
}
