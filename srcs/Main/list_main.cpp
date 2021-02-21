/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:49:26 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 12:49:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/Header.hpp"

bool 			compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}
bool 			single_digit (const int& value) { return (value<10); }
struct 			is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};
bool 			same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }
struct 			is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};
bool 			mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

int list_main()
{
	std::cout << std::endl << std::endl << YELLOW;
	std::cout << "***********************************************************" << std::endl;
	std::cout << "*****************            LIST         *****************" << std::endl;
	std::cout << "***********************************************************" << std::endl;
	std::cout << RESET << std::endl << std::endl;

	std::cout << std::endl << BLUE << "**********     Constructor      **********" << RESET << std::endl;
	try{
		// constructors used in the same order as described above:
		ft::list<int> first;                                // empty list of ints
		ft::list<int> second (4,100);                       // four ints with value 100
		ft::list<int> third (second.begin(),second.end());  // iterating through second
		ft::list<int> fourth (third);                       // a copy of third
		std::stringstream res;

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		for (int i = 0; i < 4; i++)
			first.push_back(myints[i]);
		first.unique();
		res << "The contents of fifth are: ";
		for (ft::list<int>::Iterator it = first.begin(); it != first.end(); it++)
			res << *it << ' ';

		compare_result(res.str(), "The contents of fifth are: 16 2 77 29 ");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      operator=       **********" << RESET << std::endl;
	try{
		ft::list<int> first (3);      // list of 3 zero-initialized ints
		ft::list<int> second (5);     // list of 5 zero-initialized ints
		std::stringstream res;
		std::stringstream res1;

		second = first;
		first = ft::list<int>();

		res << "Size of first: " << int (first.size());
		compare_result(res.str(), "Size of first: 0");
		res1 << "Size of second: " << int (second.size());
		compare_result(res1.str(), "Size of second: 3");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        begin         **********" << RESET << std::endl;
	try{
		int myints[] = {75,23,65,42,13};
		ft::list<int> mylist (myints,myints+5);
		std::stringstream res;

		res << "mylist contains:";
		for (ft::list<int>::Iterator it=mylist.begin(); it != mylist.end(); ++it)
			res << ' ' << *it;
		compare_result(res.str(), "mylist contains: 75 23 65 42 13");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********         end          **********" << RESET << std::endl;
	try{
		int myints[] = {75,23,65,42,13};
		ft::list<int> mylist (myints,myints+5);
		std::stringstream res;

		res << "mylist contains:";
		for (ft::list<int>::Iterator it=mylist.begin() ; it != mylist.end(); ++it)
			res << ' ' << *it;

		compare_result(res.str(), "mylist contains: 75 23 65 42 13");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        rbegin        **********" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		std::stringstream res;
		for (int i=1; i<=5; ++i) mylist.push_back(i);

		res << "mylist backwards:";
		for (ft::list<int>::reverse_Iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
			res << ' ' << *rit;

		compare_result(res.str(), "mylist backwards: 5 4 3 2 1");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        rend          **********" << RESET << std::endl;
	try{
		 ft::list<int> mylist;
		 std::stringstream res;
		for (int i=1; i<=5; ++i) mylist.push_back(i);

		res << "mylist backwards:";
		for (ft::list<int>::reverse_Iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
			res << ' ' << *rit;

		compare_result(res.str(), "mylist backwards: 5 4 3 2 1");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        empty         **********" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		std::stringstream res;
		int sum (0);

		for (int i=1 ;i <= 10; ++i) mylist.push_back(i);

		while (!mylist.empty())
		{
			sum += mylist.front();
			mylist.pop_front();
		}
		res << "total: " << sum;
		compare_result(res.str(), "total: 55");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        size          **********" << RESET << std::endl;
	try{
		ft::list<int> myints;
		std::stringstream res;
		std::stringstream res1;
		std::stringstream res2;
		std::stringstream res3;
		res << "0. size: " << myints.size();
		compare_result(res.str(), "0. size: 0");

		for (int i=0; i<10; i++) myints.push_back(i);
		res1 << "1. size: " << myints.size();
		compare_result(res1.str(), "1. size: 10");

		myints.insert (myints.begin(),10,100);
		res2 << "2. size: " << myints.size();
		compare_result(res2.str(), "2. size: 20");

		myints.pop_back();
		res3 << "3. size: " << myints.size();
		compare_result(res3.str(), "3. size: 19");

	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "***********      max_size       **********" << RESET << std::endl;
	try{
		size_t i;
		ft::list<int> mylist;

		std::cout << "Enter number of elements: ";
		std::cin >> i;

		if (i < mylist.max_size()) 
			mylist.resize(i);
		else std::cout << "That size exceeds the limit.\n";
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        front         **********" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		std::stringstream res;

		mylist.push_back(77);
		mylist.push_back(22);

		// now front equals 77, and back 22

		mylist.front() -= mylist.back();

		res << "mylist.front() is now " << mylist.front();
		compare_result(res.str(), "mylist.front() is now 55");

	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        back          **********" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		std::stringstream res;

		mylist.push_back(10);

		ft::list<int>::Iterator it1 = mylist.begin();

		while (mylist.back() != 0){
			mylist.push_back ( mylist.back() -1 );
		}

		res << "mylist contains:";
		for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end() ; ++it)
			res << ' ' << *it;
		compare_result(res.str(), "mylist contains: 10 9 8 7 6 5 4 3 2 1 0");

	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        assign        **********" << RESET << std::endl;
	try{
		ft::list<int> first;
		ft::list<int> second;
		std::stringstream res;
		std::stringstream res1;

		first.assign (7,100);                      // 7 ints with value 100

		second.assign (first.begin(),first.end()); // a copy of first

		int myints[]={1776,7,4};
		first.assign (myints,myints+3);            // assigning from array

		res << "Size of first: " << int (first.size());
		compare_result(res.str(), "Size of first: 3");
		res1 << "Size of second: " << int (second.size());
		compare_result(res1.str(), "Size of second: 7");

	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      push_front      **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::list<int> mylist (2,100);         // two ints with a value of 100
		mylist.push_front (200);
		mylist.push_front (300);

		res << "mylist contains:";
		for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
			res << ' ' << *it;
		compare_result(res.str(), "mylist contains: 300 200 100 100");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      pop_front       **********" << RESET << std::endl;
	try{
		std::stringstream res;
		std::stringstream res1;
		ft::list<int> mylist;
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		res << "Popping out the elements in mylist:";
		while (!mylist.empty())
		{
			res << ' ' << mylist.front();
			mylist.pop_front();
		}
		compare_result(res.str(), "Popping out the elements in mylist: 100 200 300");
		res1 << "Final size of mylist is " << mylist.size();
		compare_result(res1.str(), "Final size of mylist is 0");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      Push_back       **********" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		std::stringstream res;
		int myint;

		std::cout << "Please enter some integers (enter 0 to end):\n";

		do {
			std::cin >> myint;
			mylist.push_back (myint);
		} while (myint);

		std::cout << "mylist stores " << mylist.size() << " numbers.\n";
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********       Pop_back         *********" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		std::stringstream res;
		int sum (0);
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		while (!mylist.empty())
		{
			sum+=mylist.back();
			mylist.pop_back();
		}

		res << "The elements of mylist summed " << sum;
		compare_result(res.str(), "The elements of mylist summed 600");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********       Insert         **********" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		ft::list<int>::Iterator it;
		std::stringstream res;

		// set some initial values:
		for (int i=1; i<=5; ++i)
			mylist.push_back(i); // 1 2 3 4 5

		it = mylist.begin();
		++it;       // it points now to number 2           ^

		mylist.insert (it,10);                        // 1 10 2 3 4 5
		// "it" still points to number 2                      ^
		mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

		--it;       // it points now to the second 20            ^

		ft::vector<int> myvector (2,30);
		mylist.insert (it,myvector.begin(),myvector.end());
														// 1 10 20 30 30 20 2 3 4 5
														//               ^
		res << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			res << ' ' << *it;
		compare_result(res.str(), "mylist contains: 1 10 20 30 30 20 2 3 4 5");
		
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        Erase         **********" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		ft::list<int>::Iterator it1,it2;
		std::stringstream res;

		// set some values:
		for (int i=1; i<10; ++i) mylist.push_back(i*10);

									// 10 20 30 40 50 60 70 80 90
		it1 = it2 = mylist.begin(); // ^^
		//std::advance (it2,6);
		for (int i = 0; i < 6; i++){
			it2++;
		}
							        // ^                 ^
		++it1;                      //    ^              ^

		it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
									//    ^           ^

		it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
									//    ^           ^

		++it1;                      //       ^        ^
		--it2;                      //       ^     ^

		mylist.erase (it1,it2);     // 10 30 60 80 90
									//        ^

		res << "mylist contains:";
		for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
			res << ' ' << *it1;
		compare_result(res.str(), "mylist contains: 10 30 60 80 90");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********         SWAP         **********" << RESET << std::endl;
	try{
		ft::list<int> first (3,100);   // three ints with a value of 100
		ft::list<int> second (5,200);  // five ints with a value of 200
		std::stringstream res;
		std::stringstream res1;

		first.swap(second);

		res << "first contains:";
		for (ft::list<int>::Iterator it=first.begin(); it!=first.end(); it++)
			res << ' ' << *it;
		compare_result(res.str(), "first contains: 200 200 200 200 200");

		res1 << "second contains:";
		for (ft::list<int>::Iterator it=second.begin(); it!=second.end(); it++)
			res1 << ' ' << *it;
		compare_result(res1.str(), "second contains: 100 100 100");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        RESIZE        **********" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		std::stringstream res;

		// set some initial content:
		for (int i=1; i<10; ++i) mylist.push_back(i);

		mylist.resize(5);
		mylist.resize(8,100);
		mylist.resize(12);

		res << "mylist contains:";
		for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
			res << ' ' << *it;

		compare_result(res.str(), "mylist contains: 1 2 3 4 5 100 100 100 0 0 0 0");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        CLEAR         **********" << RESET << std::endl;
	try{
		ft::list<int> mylist;
		ft::list<int>::Iterator it;
		std::stringstream res;
		std::stringstream res1;

		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		res << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			res << ' ' << *it;
		compare_result(res.str(), "mylist contains: 100 200 300");

		mylist.clear();
		mylist.push_back (1101);
		mylist.push_back (2202);

		res1 << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			res1 << ' ' << *it;
		compare_result(res1.str(), "mylist contains: 1101 2202");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********       SPLICE         **********" << RESET << std::endl;
	try{
		ft::list<int> mylist1, mylist2;
		ft::list<int>::Iterator it;
		std::stringstream res;
		std::stringstream res1;

		// set some initial values:
		for (int i=1; i<=4; ++i)
			mylist1.push_back(i);      // mylist1: 1 2 3 4

		for (int i=1; i<=3; ++i)
			mylist2.push_back(i*10);   // mylist2: 10 20 30

		it = mylist1.begin();
		++it;                          // points to 2

		mylist1.splice (it, mylist2);   // mylist1: 1 10 20 30 2 3 4
										// mylist2 (empty)
										// "it" still points to 2 (the 5th element)

		mylist2.splice (mylist2.begin(),mylist1, it);
										// mylist1: 1 10 20 30 3 4
										// mylist2: 2
										// "it" is now invalid.

		it = mylist1.begin();
		it++;          // "it" points now to 30
		it++;          // "it" points now to 30
		it++;          // "it" points now to 30
						// mylist1: 1 10 20 30 3 4
						// 					^

		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
										// mylist1: 30 3 4 1 10 20
		res << "mylist1 contains:";
		for (it = mylist1.begin(); it!=mylist1.end(); ++it){
			res << ' ' << *it;
		}
		compare_result(res.str(), "mylist1 contains: 30 3 4 1 10 20");

		res1 << "mylist2 contains:";
		for (it=mylist2.begin(); it!=mylist2.end(); ++it)
			res1 << ' ' << *it;
		compare_result(res1.str(), "mylist2 contains: 2");

	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********       REMOVE         **********" << RESET << std::endl;
	try{
		int myints[]= {17,89,7,14};
		ft::list<int> mylist (myints,myints+4);
		std::stringstream res;

		mylist.remove(89);

		res << "mylist contains:";
		for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
			res << ' ' << *it;
		compare_result(res.str(), "mylist contains: 17 7 14");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********      REMOVE IF       **********" << RESET << std::endl;
	try{
		std::stringstream res;
		int myints[]= {15,36,7,17,20,39,4,1};
		ft::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1

		mylist.remove_if(single_digit);           // 15 36 17 20 39

		mylist.remove_if(is_odd());               // 36 20

		res << "mylist contains:";
		for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
			res << ' ' << *it;
		compare_result(res.str(), "mylist contains: 36 20");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********       UNIQUE         **********" << RESET << std::endl;
	try{
		std::stringstream res;
		double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
                       12.77, 73.35, 72.25, 15.3,  72.25 };
		ft::list<double> mylist (mydoubles,mydoubles+10);
		
		mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
									// 15.3,  72.25, 72.25, 73.0,  73.35

		mylist.unique();           //  2.72,  3.14, 12.15, 12.77
									// 15.3,  72.25, 73.0,  73.35

		mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
											// 15.3,  72.25, 73.0

		mylist.unique (is_near());           //  2.72, 12.15, 72.25

		res << "mylist contains:";
		for (ft::list<double>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
			res << ' ' << *it;
		compare_result(res.str(), "mylist contains: 2.72 12.15 72.25");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        MERGE         **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::list<double> first, second;

		first.push_back (3.1);
		first.push_back (2.2);
		first.push_back (2.9);

		second.push_back (3.7);
		second.push_back (7.1);
		second.push_back (1.4);

		first.sort();
		second.sort();

		first.merge(second);

		// (second is now empty)

		second.push_back (2.1);

		first.merge(second,mycomparison);

		res << "first contains:";
		for (ft::list<double>::Iterator it=first.begin(); it!=first.end(); ++it)
			res << ' ' << *it;
		compare_result(res.str(), "first contains: 1.4 2.2 2.9 2.1 3.1 3.7 7.1");

	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********        SORT          **********" << RESET << std::endl;
	try{
		ft::list<std::string> mylist;
		ft::list<std::string>::Iterator it;
		std::stringstream res;
		std::stringstream res1;
		
		mylist.push_back ("one");
		mylist.push_back ("two");
		mylist.push_back ("Three");

		mylist.sort();

		res << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			res << ' ' << *it;
		compare_result(res.str(), "mylist contains: Three one two");

		mylist.sort(compare_nocase);
		res1 << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			res1 << ' ' << *it;
		compare_result(res1.str(), "mylist contains: one Three two");

	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********       REVERSE        **********" << RESET << std::endl;
	try{
		std::stringstream res;
		ft::list<int> mylist;

		for (int i=1; i<10; ++i) mylist.push_back(i);

		mylist.reverse();

		res << "mylist contains:";
		for (ft::list<int>::Iterator it=mylist.begin(); it!=mylist.end(); ++it)
			res << ' ' << *it;

		compare_result(res.str(), "mylist contains: 9 8 7 6 5 4 3 2 1");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "********** Operators NON MEMBER **********" << RESET << std::endl;
	try{
		std::stringstream res, res1, res2, res3, res4, res5;
		ft::list<int> a;
		a.push_back(10);
		a.push_back(20);
		a.push_back(30);
		ft::list<int> b;
		b.push_back(10);
		b.push_back(20);
		b.push_back(30);
		ft::list<int> c;
		c.push_back(30);
		c.push_back(20);
		c.push_back(10);

		if (a==b) res << "a and b are equal";
		if (b!=c) res1 << "b and c are not equal";
		if (b<c) res2 << "b is less than c";
		if (c>b) res3 << "c is greater than b";
		if (a<=b) res4 << "a is less than or equal to b";
		if (a>=b) res5 << "a is greater than or equal to b";
		compare_result(res.str(), "a and b are equal");
		compare_result(res1.str(), "b and c are not equal");
		compare_result(res2.str(), "b is less than c");
		compare_result(res3.str(), "c is greater than b");
		compare_result(res4.str(), "a is less than or equal to b");
		compare_result(res5.str(), "a is greater than or equal to b");
	}catch(const std::exception &e){};

	std::cout << std::endl << BLUE << "**********  SWAP NON MEMBER     **********" << RESET << std::endl;
	try{
		std::stringstream res, res1;
		ft::list<int> foo (3,100);   // three ints with a value of 100
		ft::list<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		res << "foo contains:";
		for (ft::list<int>::Iterator it = foo.begin(); it!=foo.end(); ++it)
			res << ' ' << *it;

		res1 << "bar contains:";
		for (ft::list<int>::Iterator it = bar.begin(); it!=bar.end(); ++it)
			res1 << ' ' << *it;
		compare_result(res.str(), "foo contains: 200 200 200 200 200");
		compare_result(res1.str(), "bar contains: 100 100 100");
	}catch(const std::exception &e){};
	return 0;
}