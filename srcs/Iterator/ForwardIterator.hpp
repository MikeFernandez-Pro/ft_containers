/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ForwardIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 12:48:46 by user42            #+#    #+#             */
/*   Updated: 2020/11/12 12:48:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORWARDITERATOR_H
#define FORWARDITERATOR_H

#include "../Headers/Header.hpp"

template <typename T>
struct ForwardIterator : public InputIterator<T>
{
	public :
		/**************************************************
		****************** Form Coplien *******************
		**************************************************/
		ForwardIterator(void){}

};

#endif
