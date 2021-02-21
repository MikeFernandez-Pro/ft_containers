/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputIterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:48:51 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 12:48:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTITERATOR_H
#define INPUTITERATOR_H

#include "../Headers/Header.hpp"
template <typename T>
class InputIterator
{
	public :

		/**************************************************
		****************** Form Coplien *******************
		**************************************************/
		InputIterator(){
			this->it = NULL;
		}
		InputIterator(InputIterator const &src){
			operator=(src);
		}
		InputIterator &	operator=( InputIterator const &src){
			if (this != &src)
				this->it = src.it;
			return (*this);
		}
		virtual ~InputIterator(void){}
		
		/**************************************************
		*************** operator '==' '!=' ****************
		**************************************************/
		bool						operator==(const InputIterator &src) const{
			if (src.it == this->it)
				return (true);
			return (false);
		}
		bool						operator!=(const InputIterator &src) const{
			return (!operator==(src));
		}
		

		/**************************************************
		************* operator '*a' 'a->m' ****************
		**************************************************/
		T							&operator*(void){
			return (*this->it->ptr);
		}
		T							*operator->(void){
			return (this->it->ptr);
		}

		/**************************************************
		********* operator '++a' 'a++' '*a++' *************
		**************************************************/
		InputIterator				operator++(int){
			InputIterator I = *this;
			if (this->it && this->it->next)
				this->it = this->it->next;
			return (I);
		}
		InputIterator				operator++(void){
			if (this->it && this->it->next)
				this->it = this->it->next;
			return (*this);
		}
		maillon<T>					*get_it(void) const{
			return (this->it);
		}

	protected :
		maillon<T>					*it;

};

#endif
