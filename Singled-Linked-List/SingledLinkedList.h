#ifndef SLLIST_H_
#define SLLIST_H_

typedef int Type;

enum Boolean
{
	False = 0, True
};

class Item
{
		friend class SLList;

	public:
		Type getVal()
		{
			return val;
		}

	private:
		Item(Type value, Item *item = 0)
		{
			val = value;
			next = item;
		}

		Type val;
		Item *next;
};

class SLList
{
	public:

		class Const_Iterator
		{
				friend class SLList;
			public:
				Item *current;
				Const_Iterator() :
					current(NULL)
				{
				}

				const Item & operator*() const
				{
					return *this->current;
				}

				Const_Iterator operator++()
				{
					current = current->next;
					return *this;
				}

				Const_Iterator operator++(int)
				{
					Const_Iterator old = *this;
					++(*this);
					return old;
				}

				bool operator==(const Const_Iterator & rhs)
				{
					return current == rhs.current;
				}
				bool operator!=(const Const_Iterator & rhs)
				{
					return !(*this == rhs);
				}

				Item retrieve() const
				{
					return current->val;
				}

				Const_Iterator(Item *p) :
					current(p)
				{
				}

		};

		class Iterator
		{
				friend class SLList;
			public:
				Item *current;
				Iterator() :
					current(NULL)
				{
				}

				const Item & operator*() const
				{
					return *this->current;
				}

				Iterator operator++()
				{
					current = current->next;
					return *this;
				}

				Iterator operator++(int)
				{
					Iterator old = *this;
					++(*this);
					return old;
				}

				bool operator==(const Iterator & rhs) const
				{
					return current == rhs.current;
				}
				bool operator!=(const Iterator & rhs)
				{
					return !(*this == rhs);
				}

				Item retrieve()
				{
					return current->val;
				}

				Iterator(Item *p) :
					current(p)
				{
				}
		};

		SLList()
		{
			list = 0;
		}
		~SLList()
		{
			remove();
		}

		void insert(Type someItem);
		void append(Type someItem);
		int remove(Type someItem);
		void remove();
        void push_back(Type someItem);

		Item *atEnd();
		Item *head();
		Item *tail();

		Boolean isPresent(Type someItem);
		Boolean isEmpty();
		void display();

	private:
		Iterator iterator;
		Item *list;
		Item *atLastItem;
};

#endif /* SLLIST_H_ */
