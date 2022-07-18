/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <vgallois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:17:09 by vgallois          #+#    #+#             */
/*   Updated: 2022/03/24 17:40:38 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <string>
#include "Rand_iterator.hpp"

namespace ft{

template <typename T, typename Alloc = std::allocator<T>>
class vector{
		public:

		typedef T								value_type;
		typedef Alloc							allocator_type;
		typedef allocator_type::reference		reference;
		typedef allocator_type::pointer			pointer;
		typedef allocator_type::const_pointer	const_pointer;
		typedef ptrdiff_t						difference_type;
		typedef size_t							size_type;
		class iterator: public RandIte
		{};
		//typedef const RandIte					const_iterator;
		//typedef reverse_iterator				

		private:

		value_type		*_data;
		allocator_type	_alloc;
		size_type		_size;
		size_type		_capacity;
		const static size_type	_max_size;

		public:

//		Constructor

		vector(const allocator_type &alloc = allocator_type()): _data(NULL), _alloc(alloc), _size(0), _capacity(0);
		vector(size_type size, const value_type &val, const allocator_type &alloc = allocator_type): _data(NULL), _alloc(alloc), _size(0), _capacity(0), _capacity(0)
		{
			this->create_data(size, val);
			return ;
		}

//		Iterator
		iterator begin() {return (iterator(_data));};
		iterator end() {return (iterator(_data + size_type));};


		private:
		
		void create_data(size_type size, const value_type &val)
		{
			this->destroy_data();
			this->_data = this->_alloc.allocate(size);
			for (size_type i = 0; i < size, i++)
				this->_alloc.construct(&this->data[i], val);
			this->_size = size;
			this->_capacity = size;
		}

		void	destroy_data(void)
		{
			if (!this->_data)
				return ;
			this->clear();
			this->_alloc.deallocate(this->_data, this->_capacity);
			this->_data = NULL;
			this->_capacity = 0;
			this->_size = 0;
		}

	};
}
#endif