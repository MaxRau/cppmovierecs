#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
//Creates a vector of vectors of strings
vector <vector <string> > data;
ifstream infile( "films" );

main() {

  while (infile)
  {
    string s;
    if (!getline( infile, s )) break;

    istringstream ss( s );
    vector <string> record;

    while (ss)
    {
      string s;
      if (!getline( ss, s, '\t' )) break;
      record.push_back( s );
    }

    data.push_back( record );
  }
  if (!infile.eof())
  {
    cerr << "Unexpected End of File.\n";
  }
  //Test By retrieving first row
  //for( int row = 0; row < 5; row++)
  //  for(int column = 0; column < 5;column++)
      vector<string> currentRow = data[0];
      for(int x = 0; x < currentRow.size();x++)
        cout << currentRow[x] << " ";
}
