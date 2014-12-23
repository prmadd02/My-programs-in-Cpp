// Paul Maddox
// Single Linked List


#include <assert.h>
#include <iostream>
#include <ctime>
#include "SLList Paul Maddox.h""

using namespace std;

Boolean SLList::isEmpty()
{
	return list == 0 ? True : False;
}

void SLList::insert(Type val)
{
	Item *pt = new Item(val, list); // create new item put it in front of list
	assert(pt != 0);
	if (list == 0)
	{
		atLastItem = pt;
	}
	list = pt; // and point next top the list
}

Item *SLList::atEnd()
{
	if (list == 0)
	{
		return 0;
	}

	Item *prev, *curr;
	prev = curr = list;

	while (curr)
	{
		prev = curr;
		curr = curr->next;
	}
	return prev;
}

Item *SLList::tail()
{
	if (list == 0)
	{
		return 0;
	}

	Item *prev, *curr;
	prev = curr = list;

	while (curr)
	{
		prev = curr;
		curr = curr->next;
	}
	return prev;
}

Item *SLList::head()
{
	if (list == 0)
	{
		cout << "List is empty" << endl;
		return 0;
	}
	else
	{
		return list;
	} // end if
	return list;
}

void SLList::append(Type val)
{
	Item *pt = new Item(val);
	assert(pt != 0);
	if (list == 0)
	{
		list = pt;
	}
	else
	{
		atLastItem->next = pt;
	}
	atLastItem = pt;
}

void SLList::display()
{
	cout << "(";
	for (Item *pt = list; pt; pt = pt->next)
	{
		cout << pt->val << " ";
	} // end for
	cout << ")" << endl;
}

void SLList::remove()
{
	Item *pt = list;
	while (pt)
	{
		Item *temp = pt;
		pt = pt->next;
		delete temp;
	} // end while
	list = atLastItem = 0;
}

Boolean SLList::isPresent(Type item)
{
	Boolean rc = False;
	if (list != 0)
	{
		if (list->val == item || atLastItem->val == item)
		{
			rc = True;
		}
		else
		{
			Item *pt = list->next;
			for (; pt != atLastItem; pt = pt->next)
			{
				if (pt->val == item)
				{
					rc = True;
				} // end if
			} // end for
		} // end if
	} // end if
	return rc;
}
int SLList::remove(Type val)
{
	Item *pt = list;
	int cnt = 0;

	while (pt && pt->val == val)
	{
		Item *tmp = pt->next;
		delete pt;
		cnt++;
		pt = tmp;
	} // end while

	if ((list = pt) == 0)
	{
		atLastItem = 0;
		return cnt;
	} // end if

	Item *prv = pt;
	pt = pt->next;

	while (pt)
	{
		if (pt->val == val)
		{
			prv->next = pt->next;
			if (atLastItem == pt)
			{
				atLastItem = prv;
			} // end if
			delete pt;
			++cnt;
			pt = prv->next;
		}
		else
		{
			prv = pt;
			pt = pt->next;
		} // end if else
	} // end while
	return cnt;
}

void SLList::push_back(Type someItem) {
   Item* newItem = new Item(someItem);
		if(list == 0) {
       	list = newItem;
   		}
		    
   		else {
       		atLastItem->next = newItem;
   		}
   		
		atLastItem = newItem;
}

int main()
{
   SLList myList;
   
   	myList.append(1);
   	myList.append(2);
   	cout << "Testing append function: ";
   	myList.display();
   	cout << endl;

	myList.push_back(3);
   	myList.push_back(4);
   	cout << "Testing push_back function: ";
   	myList.display();
   	cout << endl;

   myList.insert(5);
   cout << "Testing insert function: ";
   myList.display();
   cout << endl;
   
   cout << "Testing isPresent function with value of 5" << endl;
   if(myList.isPresent(5)) {
   	   cout << endl;
       cout << "5 is present\n" << endl;
   } else {
        cout << "5 is not present" << endl;
   }

   myList.remove(2);
   cout << "Testing remove function with value of 2: ";
   myList.display();
   cout << endl;

   myList.remove();
   cout << "Testing remove function: ";
   myList.display();
   cout << endl;
   
   cout << "Testing if the list is Empty:" << endl;
   if(myList.isEmpty()) {
   	   cout << endl;
       cout << "List is Empty" << endl;
   	   cout << endl;
		}
   else {
       cout << "List is not empty" << endl;
   		}
   
   clock_t start, end;
   int n = 10000000;
   cout << "Comparing times of append and push back functions: " << endl;
   cout << endl;
   start = clock();
   for(int i = 1; i <= n; i++) {
       myList.push_back(i);
   }
   end = clock() - start;
   cout << "The time for push back function " << n << " times is " << (double)end << " seconds" << endl;
   cout << endl;
   myList.remove();
   
   start = clock();
   for(int i = 1; i <= n; i++) {
       myList.append(i);
   } 
   end = clock() - start;
   cout << "The time for append function " << n << " times is " << (double)end << " seconds" << endl;
   return 0;
}
