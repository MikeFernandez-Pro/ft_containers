/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:48:18 by user42            #+#    #+#             */
/*   Updated: 2020/11/13 10:47:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H
#include "../Headers/Header.hpp"

namespace ft
{
	template<typename T, class Alloc = std::allocator<T> >
	class vector
	{

		public:

			typedef T 											value_type;
			typedef Alloc 										allocator_type;
			typedef RandomAccessIterator<T>						Iterator;
			typedef T &											reference;
			typedef const T&									const_reference;
			typedef T*											pointer;
			typedef const T*									const_pointer;
			typedef const Iterator 								const_Iterator;
			typedef size_t										size_type;
			typedef ReverseRandomAccessIterator<T> 				reverse_Iterator;
			typedef ReverseRandomAccessIterator< const T>		const_reverse_Iterator;
			typedef std::ptrdiff_t 								difference_type;

			/**************************************************
			****************** Form Coplien *******************
			**************************************************/

			explicit 							vector (const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_array = NULL;
				this->_size = 0;
				this->_capacity = 0;
			}
			explicit 							vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_array = NULL;
				this->_size = 0;
				this->_capacity = 0;
				assign(n, val);
			}
			explicit 							vector (int n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_array = NULL;
				this->_size = 0;
				this->_capacity = 0;
				assign(n, val);
			}
			template <class InputIterator>
												vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_array = NULL;
				this->_size = 0;
				this->_capacity = 0;
				this->assign(first, last);
			}
			vector(const vector& x){
				this->_array = NULL;
				this->_size = 0;
				this->_capacity = 0;
				operator=(x);
			}
			virtual 							~vector(void){
				this->clear();
			}
			vector &							operator=( vector const &src){
				this->clear();
				if (this != &src){
					this->_array = new T[src._capacity];
					assign(src.begin(), src.end());
					this->_capacity = src._capacity;
					this->_size = src._size;
					this->_al = src._al;
				}
				return (*this);
			}

			/**************************************************
			******************** Iterators ********************
			**************************************************/

			Iterator							begin(){
				return (this->_array);
			}
			const_Iterator						begin() const{
				return (this->_array);
			}
			Iterator							end(){
				return (&this->_array[this->_size]);
			}
			const_Iterator						end() const{
				return (&this->_array[this->_size]);
			}
			reverse_Iterator 					rbegin(){
				return (&this->_array[this->_size - 1]);
			}
			const_reverse_Iterator 				rbegin() const{
				return (&this->_array[this->_size - 1]);
			}
			reverse_Iterator 					rend(){
				return (this->_array - 1);
			}
			const_reverse_Iterator 				rend() const{
				return (this->_array - 1);
			}

			/**************************************************
			********************* Capacity ********************
			**************************************************/

			size_type							size() const{
				return (this->_size);
			}
			size_type							max_size() const{
				size_type res = (pow(2, 64) / sizeof(value_type));
                return (res - 1);
			}
			void								resize (size_type n, value_type val = value_type()){
				if (n <= this->_size)
					this->_size = n;
				while (n > this->_size)
					push_back(val);
			}
			size_type 							capacity() const{
				return (this->_capacity);
			}
			bool								empty() const{
				return (!this->_size);
			}
			void								reserve (size_type n){
				if (n > this->_capacity){
					pointer tmp = new value_type[n];
					for (size_type i = 0; i < this->_size; i++) 
						tmp[i] = this->_array[i];
					delete[] this->_array;
					this->_array = tmp;
					this->_capacity = n;
				}
			}

			/**************************************************
			****************** Element Access *****************
			**************************************************/

			reference 							operator[](size_type n){
				return (this->_array[n]);
			}
			const_reference 					operator[](size_type n) const{
				return (this->_array[n]);
			}
			reference 							at(size_type n){
				if (n >= this->_size)
					throw(vector::out_of_range());
				return (this->_array[n]);
			}
			const_reference 					at(size_type n) const{
				if (n >= this->_size)
					throw(vector::out_of_range());
				return (this->_array[n]);
			}
			reference 							front(){
				return (this->_array[0]);
			}
			const_reference 					front() const{
				return (this->_array[0]);
			}
			reference							back(){
				return (this->_array[this->_size - 1]);
			}
			const_reference						back() const{
				return (this->_array[this->_size - 1]);
			}

			/**************************************************
			******************** Modifiers ********************
			**************************************************/

			template <class InputIterator>
			void 								assign(InputIterator first, InputIterator last){
				if (this->_size)
					this->clear();
				while (first != last){
					this->push_back(*first);
					first++;
				}
			}
			void								assign(size_type n, const value_type& val){
				if (this->_size)
					this->clear();
				for (size_t i = 0; i < n; i++)
					push_back(val);
			}
			void								assign(int n, const value_type& val){
				if (this->_size)
					this->clear();
				for (int i = 0; i < n; i++)
					push_back(val);
			}
			void 								push_back (const value_type& val){
				if (this->_size == this->_capacity){
					if (this->_size == 0)
						reserve(1);
					else
						reserve(this->_capacity * 2);
				}
				this->_array[this->_size] = val;
				this->_size++;
			}
			void 								pop_back(void){
				this->_size--;
			}
			Iterator							insert (Iterator position, const value_type& val){
				
				if ((this->_size + 1) > this->max_size())
					throw (vector::bad_alloc());
				size_t i = this->_size - 1;
				size_t j = 0;
				T	tmp[this->_size];

				for (Iterator it = this->end(); position != it; it--)
					tmp[j++] = this->_array[i--];

				if (this->_size + 1 > this->_capacity)
					reserve(this->_size + 1);

				this->_size += 1;
				i = 0;
				for (size_t size = this->_size ; i < j; i++)
					this->_array[--size] = tmp[i];

				this->_array[this->_size - 1 - i] = val;

				return (Iterator(&this->_array[this->_size - i - 1]));
			}	
			void								insert (Iterator position, size_type n, const value_type& val){
				if ((this->_size + 1) > this->max_size())
					throw (vector::bad_alloc());
				while (n--){
					position = insert(position, val);
					position++;
				}
			}
			void								insert (Iterator position, int n, const value_type& val){
				if ((this->_size + 1) > this->max_size())
					throw (vector::bad_alloc());
				while (n--){
					position = insert(position, val);
					position++;
				}
			}
			template <class InputIterator>
			void								insert (Iterator position, InputIterator first, InputIterator last){
				if ((this->_size + 1) > this->max_size())
					throw (vector::bad_alloc());
				for (;first != last; first++){
					position = insert(position, *first);
					position++;
				}
			}
			Iterator							erase (Iterator position){
				return (erase(position, position));
			}
			Iterator							erase (Iterator first, Iterator last){
				T	*tmp = new T[this->_size];
				size_t i = 0;

				for (Iterator it = this->begin(); it != first; it++, i++)
					tmp[i] = this->_array[i];

				size_t j = i;
				while (first++ != last)
					j++;

				j = j == i ? j + 1 : j;
				while (j < this->_size)
					tmp[i++] = this->_array[j++];

				delete [] this->_array;
				this->_array = tmp;
				this->_size -= (j - i);

				return (Iterator(&this->_array[j - i]));
				
			}
			void								swap (vector& x){
				std::swap(this->_array, x._array);
				std::swap(this->_size, x._size);
				std::swap(this->_capacity, x._capacity);
			}
			void								clear(void){
				if (this->_array != NULL)
					delete[] this->_array;
				this->_array = NULL;
				this->_size = 0;
				this->_capacity = 0;
			}
		
		class out_of_range : public std::exception
 		{
			public:
				out_of_range() {}
				out_of_range(const out_of_range &rhs) {out_of_range::operator=(rhs);}
				out_of_range& operator=(const out_of_range &rhs) {static_cast<void>(rhs); return *this;}
				virtual ~out_of_range(void) throw() {}
				char const *what(void) const throw() {return("ft::vector::_M_range_check");}
    	};
		class bad_alloc: public std::exception
 		{
			public:
				bad_alloc() {}
				bad_alloc(const bad_alloc&rhs) {bad_alloc::operator=(rhs);}
				bad_alloc& operator=(const bad_alloc&rhs) {static_cast<void>(rhs); return *this;}
				virtual ~bad_alloc(void) throw() {}
				char const *what(void) const throw() {return("ft::vector::bad_alloc");}
    	};




		private :
			pointer								_array;
			size_type							_size;
			size_type							_capacity;
			allocator_type						_al;

	};
}

/**************************************************
*********  Non-member function overloads  *********
**************************************************/

template <class T, class Alloc>
	bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
	  	if (lhs.size() != rhs.size())
			return false;
		RandomAccessIterator<T>	itr = rhs.begin();
		RandomAccessIterator<T>	itl = lhs.begin();

		while (itr != rhs.end())
		{
			if (*itr != *itl)
				return (false);
			itr++;
			itl++;
		}
		return true;
	}
template <class T, class Alloc>
  	bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
		return (!operator==(lhs, rhs));
  	}
template <class T, class Alloc>
 	bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
		if (lhs.size() < rhs.size())
			return true;
		else if (rhs.size() > lhs.size())
			return false;
		RandomAccessIterator<T>	itr = rhs.begin();
		RandomAccessIterator<T>	itl = lhs.begin();

		while (itr != rhs.end())
		{
			if (*itl < *itr)
				return (true);
			itr++;
			itl++;
		}
		return false;
  	}
template <class T, class Alloc>
  	bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
		if (operator<(lhs, rhs) || operator==(lhs, rhs))
			return (true);
		return (false);
  	}
template <class T, class Alloc>
  	bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
		return (!operator<=(lhs,rhs));
  	}
template <class T, class Alloc>
  	bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs){
		return (!operator<(lhs, rhs));
  	}
template <class T, class Alloc>
  	void swap(ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y){
		x->swap(y);
  	}

#endif