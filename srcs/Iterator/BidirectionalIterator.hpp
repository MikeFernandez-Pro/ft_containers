/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BidirectionalIterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:48:35 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 12:48:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_H
#define BIDIRECTIONALITERATOR_H

#include "../Headers/Header.hpp"

template <typename T>
class BidirectionalIterator : public ForwardIterator<T>
{
	public:

		/**************************************************
		****************** Form Coplien *******************
		**************************************************/
		BidirectionalIterator(void){}	
		BidirectionalIterator(BidirectionalIterator const &src){
			operator=(src);
		}
		BidirectionalIterator &	operator=( BidirectionalIterator const &src){
			if (this != &src){
				this->it = src.it;
			}
			return (*this);
		}
		virtual ~BidirectionalIterator(void){}
		BidirectionalIterator(maillon<T> *src){
			this->it = src;
		}

		/**************************************************
		********* operator '--a' 'a--' '*a--' *************
		**************************************************/
		BidirectionalIterator				operator--(int){
			BidirectionalIterator I = *this;
			if (this->it && this->it->prev)
				this->it = this->it->prev;
			return (I);
		}
		BidirectionalIterator				&operator--(void){
			if (this->it && this->it->prev)
				this->it = this->it->prev;
			return (*this);
		}

		/**************************************************
		********* operator '++a' 'a++' '*a++' *************
		**************************************************/
		BidirectionalIterator				operator++(int){
			BidirectionalIterator I = *this;
			if (this->it && this->it->next)
				this->it = this->it->next;
			return (I);
		}
		BidirectionalIterator				operator++(void){
			if (this->it && this->it->next)
				this->it = this->it->next;
			return (*this);
		}

};

#endif
