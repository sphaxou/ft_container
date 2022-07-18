/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rand_iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <vgallois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 03:44:31 by vgallois          #+#    #+#             */
/*   Updated: 2022/03/20 04:08:33 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAND_ITERATOR_HPP
#define RAND_ITERATOR_HPP

namespace ft {

	template <typename Spe>
	class RandIte{

		protected:
		Spe		*_value;
		public:
		typedef Spe 		value_type;
		typedef ptrdiff_t	difference_type;

		RandIte(void) : _value(NULL) {return ;};
		RandIte(Spe *src) : _value(src) {return ;};
		RandIte(const RandIte &src) {*this = src;};
		virtual ~RandIte(void) {return ;};
		RandIte &operator=(RandIte const &rhs) {
			if (this == &rhs)
				return (*this);
			this->value = rhs._value
			return (*this);
		};

		bool operator==(const RandIte &rhs) const {return (this->_value == rhs._value)};
		bool operator!=(const RandIte &rhs) const {return (this->_value != rhs._value)};
		bool operator<(const RandIte &rhs) const {return (this->_value < rhs._value)};
		bool operator<=(const RandIte &rhs) const {return (this->_value <= rhs._value)};
		bool operator>(const RandIte &rhs) const {return (this->_value > rhs._value)};
		bool operator>=(const RandIte &rhs) const {return (this->_value >= rhs._value)};

		RandIte<Spe>	&operator++(void){
			++this->_value;
			return (*this);
		};
		RandIte<Spe>	operator++(int){
			RandIte<Spe>	tmp(*this);
			++this->_value;
			return (tmp);
		};
		RandIte<Spe>	&operator--(void){
			--this->_value;
			return (*this);
		};
		RandIte<Spe>	operator--(int){
			RandIte<Spe> 	tmp(*this);
			--this->_value;
			return (tmp);
		};

		difference_type	operator-(const RandIte &rhs) const {return (this->_value - rhs._value);};
		RandIte<Spe>	operator+(difference_type n) const {return(RandIte(this->_value + n))};
		RandIte<Spe>	operator-(difference_type n) const {return(RandIte(this->_value - n))};
		friend RandIte<Spe>	operator+(difference_type n, const RandIte &rhs)
			{return rhs.operator+(n);};

			operator[](int n) {return (this->_value[n]);};
		

		RandIte<Spe>	&operator[](int n){return (_value + n);};
		RandIte<Spe>	*operator->(){return (_value)};
		RandIte<Spe>	&operator*(){return (*_value);};
	};
}

#endif