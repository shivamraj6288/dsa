#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi
using namespace std;

int main ()
{
  // std::string str_dec = "2001, A Space Odyssey";
  // std::string str_hex = "40c3";
  // std::string str_bin = "11";
  // std::string str_auto = "0x7f";

  // std::string::size_type sz;   // alias of size_t

  // int i_dec = std::stoi (str_dec,&sz);
  // int i_hex = std::stoi (str_hex,nullptr,16);
  // int i_bin = std::stoi (str_bin,0,2);
  // int i_auto = std::stoi (str_auto,nullptr,0);

  // std::cout << str_dec << ": " << i_dec << " and [" << str_dec.substr(sz) << "]\n";
  // std::cout << str_hex << ": " << i_hex << '\n';
  // std::cout << str_bin << ": " << i_bin << '\n';
  // std::cout << str_auto << ": " << i_auto << '\n';
  string a[3];
  a[0]="qw";
  a[1]="rt";
  a[2]="bn";
  cout<< &(a+2);
  // cout <<a+to_string(2);



  return 0;
}

// int countDistinct(int a[]){
//   sort (a, a+m);
//   // print (a);
//   int rs=0;

//   for (int i=0; i<m; i++){
//     // cout << "val=" << a[i] << endl;
//     while (i<m-1 && a[i]==a[i+1]){
//       // cout << "check " << a[i];
//       i++;
//     }
//     rs++;
//     // cout << rs;
//   }
//   return rs;
// }