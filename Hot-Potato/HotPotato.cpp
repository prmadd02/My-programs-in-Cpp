// Hot Potato
// Paul Maddox

#include <iostream>
#include <list>

using namespace std;

int main()
 {
  int i,j, n, m, mMod, numLeft;
  	list <int > L;
  	list<int>::iterator iter; 

  cout<<"enter N (# of people): ";
  cin>>n;
  cout<<"enter M (# of passes before elimination): ";
  cin>>m;
  	numLeft = n;
  	mMod = m % n;
  
  for (i = 1 ; i <= n; i++)
      L.push_back(i);
  		iter = L.begin();


// Pass the potato
  for (i = 0; i < n; i++)
  {
   mMod = mMod % numLeft;
   if (mMod <= numLeft/2) // pass forward
    for (j = 0; j < mMod; j++)
      {
	iter++;
	if (iter == L.end())
   		iter = L.begin();
}
    else // pass backward
      for (j = 0; j < mMod; j++)
      	{
  if (iter == L.begin())
   	iter = --L.end();
  else
   	iter--;
    	}
   
   
   cout<<*iter<<" ";
   iter= L.erase(iter);
   if (iter == L.end())
      iter = L.begin();
   }
  cout<<endl;
  return 0;
}
