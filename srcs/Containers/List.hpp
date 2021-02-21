/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:47:50 by user42            #+#    #+#             */
/*   Updated: 2020/11/13 10:38:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP
#include "../Headers/Header.hpp"

namespace ft
{
	template<typename T, class Alloc = std::allocator<T> >
	class list
	{

		public:

			typedef T 											value_type;
			typedef Alloc 										allocator_type;
			typedef BidirectionalIterator<T>					Iterator;
			typedef T &											reference;
			typedef const T&									const_reference;
			typedef T*											pointer;
			typedef const T*									const_pointer;
			typedef const Iterator 								const_Iterator;
			typedef size_t										size_type;
			typedef ReverseBidirectionalIterator<T> 			reverse_Iterator;
			typedef ReverseBidirectionalIterator< const T>		const_reverse_Iterator;
			typedef std::ptrdiff_t 								difference_type;
			

			/**************************************************
			****************** Form Coplien *******************
			**************************************************/

			explicit 							list (const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_begin = new maillon<T>;
				memset(this->_begin, 0, sizeof(maillon<T>));
				this->_begin->prev = this->_begin;
				this->_begin->next = this->_begin;
				this->_size = 0;
				this->_begin->ptr = reinterpret_cast<T *>(&this->_size);
			}
			explicit 							list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_begin = new maillon<T>;
				memset(this->_begin, 0, sizeof(maillon<T>));
				this->_begin->prev = this->_begin;
				this->_begin->next = this->_begin;
				this->_size = 0;
				this->_begin->ptr = reinterpret_cast<T *>(&this->_size);
				assign(n, val);
			}
			explicit 							list (int n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_begin = new maillon<T>;
				memset(this->_begin, 0, sizeof(maillon<T>));
				this->_begin->prev = this->_begin;
				this->_begin->next = this->_begin;
				this->_size = 0;
				this->_begin->ptr = reinterpret_cast<T *>(&this->_size);
				assign(n, val);
			}
			template <class InputIterator>
												list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
				this->_al = alloc;
				this->_begin = new maillon<T>;
				memset(this->_begin, 0, sizeof(maillon<T>));
				this->_begin->prev = this->_begin;
				this->_begin->next = this->_begin;
				this->_size = 0;
				this->_begin->ptr = reinterpret_cast<T *>(&this->_size);
				assign(first,last);
			}
												list(const list& x){
				this->_begin = new maillon<T>;
				memset(this->_begin, 0, sizeof(maillon<T>));
				this->_begin->prev = this->_begin;
				this->_begin->next = this->_begin;
				this->_size = 0;
				this->_begin->ptr = reinterpret_cast<T *>(&this->_size);
				operator=(x);
			}
			virtual 							~list(void){
				clear();
				delete (this->_begin);
				this->_begin = NULL;
			}
			list &								operator=( list const &src){
				this->clear();
				if (this != &src){
					this->_al = src._al;
					assign(src.begin(), src.end());
				}
				return (*this);
			}

			/**************************************************
			************** begin end rbegin rend **************
			**************************************************/

			Iterator							begin(){
				return (this->_begin->next);
			}
			const_Iterator						begin() const{
				return (this->_begin->next);
			}
			Iterator							end(){	
				return (this->_begin);
			}
			const_Iterator						end() const{
				return (this->_begin);
			}
			reverse_Iterator 					rbegin(){
				return (this->_begin->prev);
			}
			const_reverse_Iterator 				rbegin() const{
				return (this->_begin->prev);
			}
			reverse_Iterator 					rend(){
				return (this->_begin);
			}
			const_reverse_Iterator 				rend() const{
				return (this->_begin);
			}

			/**************************************************
			*************** empty size max_endsize->ptr *******
			**************************************************/

			bool								empty() const{
				return (this->_size == 0);
			}
			size_type							size() const{
				return (this->_size);
			}
			size_type							max_size() const{
				if (sizeof(value_type) == 32)
					return (384307168202282325);
				return (768614336404564650);
			}

			/**************************************************
			******************** front back *******************
			**************************************************/

			reference 							front(){
				return (*this->_begin->next->ptr);
			}
			const_reference 					front() const{
				return (*this->_begin->next->ptr);
			}
			reference							back(){
				return (*this->_begin->prev->ptr);
			}
			const_reference						back() const{
				return (*this->_begin->prev->ptr);
			}

			/**************************************************
			* assign push_front pop_front push_back pop_back  *
			********* insert erase swap resize clear **********
			**************************************************/

			void								assign(size_type n, const value_type& val){
				if (this->_begin != NULL)
					this->clear();
				for (size_t i = 0; i < n; i++)
					push_back(val);
			}
			void								assign(int n, const value_type& val){
				if (this->_begin != NULL)
					this->clear();
				for (int i = 0; i < n; i++)
					push_back(val);
			}
			template <class InputIterator>
			void 								assign(InputIterator first, InputIterator last){
				if (this->size() > 0)
					this->clear();
				while (first != last){
					this->push_back(*first);
					first++;
				}
			}
			void								push_front (const value_type& val){
				maillon<T> *new_start =  new maillon<T>;
				memset(new_start, 0, sizeof(maillon<T>));

				//Initialisation du nouveau premier maillon<T>
				new_start->ptr = this->_al.allocate(1);
				this->_al.construct(new_start->ptr, val);
				new_start->prev = this->_begin;
				new_start->next = this->_begin->next;
				this->_begin->next->prev = new_start;

				//Modification des variables
				this->_begin->next = new_start;

				this->_size += 1;
			}
			void								pop_front(void){
				if (this->_size){
					maillon<T>	*cpy = this->_begin->next;

					this->_al.deallocate(cpy->ptr, 1);
					this->_begin->next = cpy->next;
					delete cpy;
					this->_begin->next->prev = this->_begin;
					this->_size -= 1;
				}
			}
			void 								push_back (const value_type& val){
					maillon<T> *new_end =  new maillon<T>;
					memset(new_end, 0, sizeof(maillon<T>));
					maillon<T> *old_end =  this->_begin->prev;

					old_end->next = new_end;
					//Initialisation du nouveau dernier maillon<T>
					new_end->ptr = this->_al.allocate(1);
					this->_al.construct(new_end->ptr, val);
					new_end->prev = old_end;
					new_end->next = this->_begin;

					//Modification des variables
					this->_begin->prev = new_end;

					this->_size += 1;
			}
			void 								pop_back(void){
				if (this->_size){
					maillon<T> *replaced = this->_begin->prev;
					maillon<T> *new_end = this->_begin->prev->prev;
					
					if (replaced->ptr) {
						this->_al.deallocate(replaced->ptr, 1);
					}
					this->_begin->prev = new_end;
					new_end->next = this->_begin;
					delete (replaced);
					this->_size -= 1;
				}
				
			}
			Iterator							insert (Iterator position, const value_type& val){
				if ((this->_size + 1) > this->max_size())
					throw (list::bad_alloc());
				maillon<T> *new_maillon = new maillon<T>;
				memset(new_maillon, 0, sizeof(maillon<T>));

				new_maillon->ptr = this->_al.allocate(1);
				this->_al.construct(new_maillon->ptr, val);

				new_maillon->next = position.get_it();
				new_maillon->prev = position.get_it()->prev;
			
				if (position.get_it() == this->_begin->next)
				this->_begin->next = new_maillon;

				new_maillon->next->prev = new_maillon;
				new_maillon->prev->next = new_maillon;

				this->_size += 1;
				return (position);
			}	
			void								insert (Iterator position, size_type n, const value_type& val){
				if ((this->_size + 1) > this->max_size())
					throw (list::bad_alloc());
				while (n--){
					insert(position, val);
				}
			}
			void								insert (Iterator position, int n, const value_type& val){
				if ((this->_size + 1) > this->max_size())
					throw (list::bad_alloc());
				while (n--){
					insert(position, val);
				}
			}
			template <class InputIterator>
			void								insert (Iterator position, InputIterator first, InputIterator last){
				if ((this->_size + 1) > this->max_size())
					throw (list::bad_alloc());
				while (first != last){
					insert(position, *first);
					first++;
				}
			}
			Iterator							erase (Iterator position){
				maillon<T> *pos = position.get_it();
				pos->prev->next = pos->next;
				pos->next->prev = pos->prev;
				this->_al.deallocate(pos->ptr, 1);
				position++;
				delete (pos);
				this->_size -= 1;
				return (position);
			}
			Iterator							erase (Iterator first, Iterator last){
				while (first != last)
					first = erase(first);
				return (last);
			}
			void								swap (list& x){
				std::swap(this->_begin, x._begin);
				std::swap(this->_size, x._size);
				std::swap(this->_al, x._al);
			}
			void								resize (size_type n, value_type val = value_type()){
			while (this->_size > n)
				this->pop_back();
			while (this->_size < n)
				this->push_back(val);
			}
			void								clear(void){
				while (this->_size)
					this->pop_back();
			}

			/**************************************************
			**** splice remove remove_if unique merge sort ****
			********************* reverse *********************
			**************************************************/

			void 								splice (Iterator position, list& x){
				Iterator	first = x.begin();
				Iterator 	last  = x.end();

				splice(position, x, first, last);
			}
			void 								splice (Iterator position, list& x, Iterator i){

					//creation du maillon
					maillon<T>	*stock = new maillon<T>;
					memset(stock, 0, sizeof(maillon<T>));
					stock->ptr = i.get_it()->ptr;
					if (this->_begin->next == position.get_it()){
						this->_begin->next = stock;
					}
					i.get_it()->ptr = NULL;
					stock->prev = position.get_it()->prev;
					stock->next = position.get_it();

					//ajout du maillon a la nouvelle position
					position.get_it()->prev->next = stock;
					position.get_it()->prev = stock;
					this->_size += 1;



					i.get_it()->prev->next = i.get_it()->next;
					i.get_it()->next->prev = i.get_it()->prev;
					//rectification des size
					x._size -= 1;
					if (i.get_it() == x._begin->next){
						x._begin->next = x._begin->next->next;
						x._begin = x._begin->next;
					}
					delete i.get_it();

				
			}
			void 								splice (Iterator position, list& x, Iterator first, Iterator last){
				Iterator cpy;
				while (first != last){
					cpy = first;
					cpy++;
					splice(position, x, first);
					first = cpy;
				}
			}
			void 								sort(void){
				maillon<T> 		*start = this->_begin->next;
				maillon<T> 		*end = this->_begin->prev;

				while (start != end){
					while (start != end){
						if (std::min(*start->ptr, *end->ptr) != *start->ptr)
							std::swap(start->ptr, end->ptr);
						end = end->prev;
					}
					end = this->_begin->prev;
					start = start->next;
				}
			}
			template <class Compare>
			void 								sort (Compare comp){
				maillon<T> 		*start = this->_begin->next;
				maillon<T> 		*end = this->_begin->prev;

				while (start != end){
					while (start != end){
						if (comp(*end->ptr, *start->ptr)){
							std::swap(start->ptr, end->ptr);
							end = end->prev;
						}
						else{
						end = end->prev;
						}
					}
					end = this->_begin->prev;
					start = start->next;
				}
			}
			void 								remove(const value_type& val) {
				maillon<T>		*tmp = this->_begin->next;
				maillon<T>		*cpy;
				if (tmp != NULL){
					while (tmp != this->_begin){
						if (*tmp->ptr == val){
							cpy = tmp->prev;
							this->erase(tmp);
							tmp = cpy;

						}
						tmp = tmp->next;
					}
				}
			}
			template <class Predicate>
			void 								remove_if(Predicate pred) {
				maillon<T>		*tmp = this->_begin->next;
				maillon<T>		*cpy = tmp;
			
				if (tmp != NULL) {
					while (tmp != this->_begin)
					{
						if (pred(*tmp->ptr)) {
							cpy = tmp;
							if (tmp == this->_begin->next)
								this->_begin->next = tmp->next;
							tmp = tmp->next;
							cpy->prev->next = cpy->next;
							cpy->next->prev = cpy->prev;
							this->_al.deallocate(cpy->ptr, 1);
							delete cpy;
							this->_size -= 1;
						} else
							tmp = tmp->next;
					}
				}
			}
			void 								unique() {
				maillon<T>		*tmp = this->_begin->next;
				maillon<T>		*cpy;

				if (tmp) {
					while (tmp != this->_begin) {
								if (*tmp->ptr == *tmp->next->ptr){
									cpy = tmp->prev;
									this->erase(tmp);
									tmp = cpy;
								}
						tmp = tmp->next;
					}
				}
			}
			template <class BinaryPredicate>
			void								unique(BinaryPredicate binary_pred)
			{
				maillon<T>		*tmp = this->_begin->next;

					while (tmp != this->_begin->prev && tmp) {
						if (binary_pred(*tmp->ptr, *tmp->next->ptr))
								erase(tmp->next);
						else
							tmp = tmp->next;
					}
			}
			void								merge(list &x) {
				this->splice(this->end(), x);
				this->sort();
			}
			template<class Compare>
			void 								merge (list& x, Compare comp) {
				this->sort(comp);
				Iterator it = this->begin();
				Iterator itx = x.begin();

				while (x.size())
				{
					if (comp(*itx,*it) || (it == this->end()))
						this->splice(it, x, itx);
					else
						it++;
					itx = x.begin();
				}
			}
			void 								reverse(void){

				maillon<T> 		*start = this->_begin->next;
				maillon<T> 		*end = this->_begin->prev;

				while (start != end && start != end->next){
					std::swap(start->ptr, end->ptr);
					start = start->next;
					end = end->prev;
				}
			}
		
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
			allocator_type						_al;
			maillon<T>							*_begin;
			size_t								_size;
	};
}



template <class T, class Alloc>
	bool operator== (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
		
		if (lhs.size() != rhs.size())
			return false;
		BidirectionalIterator<T>	itr = rhs.begin();
		BidirectionalIterator<T>	itl = lhs.begin();

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
	bool operator!= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
		return (!operator==(lhs, rhs));
	}

template <class T, class Alloc>
	bool operator<  (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
		if (lhs.size() < rhs.size())
			return true;
		else if (rhs.size() > lhs.size())
			return false;
		BidirectionalIterator<T>	itr = rhs.begin();
		BidirectionalIterator<T>	itl = lhs.begin();

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
	bool operator<= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
		if (operator<(lhs, rhs) || operator==(lhs, rhs))
			return (true);
		return (false);
	}

template <class T, class Alloc>
	bool operator>  (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
		if (lhs.size()	> rhs.size())
			return true;
		else if (rhs.size() < lhs.size())
			return false;
		BidirectionalIterator<T>	itr = rhs.begin();
		BidirectionalIterator<T>	itl = lhs.begin();

		while (itr != rhs.end())
		{
			if (*itl > *itr)
				return (true);
			itr++;
			itl++;
		}
		return false;
	}

template <class T, class Alloc>
	bool operator>= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
		if (operator>(lhs, rhs) || operator==(lhs, rhs))
			return (true);
		return (false);
	}

template <class T, class Alloc>
  void swap (ft::list<T,Alloc>& x, ft::list<T,Alloc>& y){
	  x->swap(y);
  }
#endif
