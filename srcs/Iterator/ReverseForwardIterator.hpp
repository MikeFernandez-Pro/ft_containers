/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseForwardIterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:49:14 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 12:49:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEFORWARDITERATOR_H
#define REVERSEFORWARDITERATOR_H

#include "../Headers/Header.hpp"

template <typename T>
struct ReverseForwardIterator : public ReverseInputIterator<T>
{
	/**************************************************
	****************** Form Coplien *******************
	**************************************************/
	public :
		ReverseForwardIterator(void){}

};

#endif
