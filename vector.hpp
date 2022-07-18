/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <vgallois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:17:09 by vgallois          #+#    #+#             */
/*   Updated: 2022/07/18 18:53:51 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <string>
#include "Rand_iterator.hpp"
std::vector<int> q;
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

		explicit vector(const allocator_type &alloc = allocator_type()): _data(NULL), _alloc(alloc), _size(0), _capacity(0);
		
		explicit vector(size_type size, const value_type &val, const allocator_type &alloc = allocator_type): _data(NULL), _alloc(alloc), _size(0), _capacity(0), _capacity(0)
		{
			this->create_data(size, val);
			return ;
		}
		
		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		{
			this->create_data(first, last);
			return ;
		}

		vector(const vector &other): _data(NULL), _alloc(other._alloc), _size(other._size), _capacity(other._capacity)
		{
			this->create_data(other._size, other._data);
			return ;
		}

		vector& operator= (const vector& x)
		{
			this->destroy_data();
			this->create_data(x._size, x._data[0]);
			return *this;
		}

//		Destructor
		~vector()
		{
			this->destroy_data();
			return ;
		}




//		Iterator
		iterator begin()
		{
			return iterator(this->_data);
		}

		iterator end()
		{
			return iterator(this->_data + this->_size);
		}

		const_iterator begin() const
		{
			return const_iterator(this->_data);
		}

		const_iterator end() const
		{
			return const_iterator(this->_data + this->_size);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(this->end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(this->begin());
		}
		
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(this->end());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(this->begin());
		}

//		Capacity

		size_type size() const
		{
			return this->_size;
		}

		size_type max_size() const
		{
			return allocator_type::max_size();
		}

		void	resize(size_type size, value_type val = value_type())
		{
			if (size > this->max_size())
			{
				throw std::length_error("size requested is higher than max_size");
			}
			if (size > this->_size)
			{
				value_type *tmp = this->_data;
				this->_data = this->_alloc.allocate(size);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(this->_data + i, *(tmp + i));
				for (size_type i = this->_size; i < size; i++)
					this->_alloc.construct(this->_data + i, val);
				_alloc.deallocate(tmp, this->_size);
				this->_size = size;
			}
			else
			{
				this->_size = size;
				for (size_type i = size; i < this->_size; i++)
					this->_alloc.destroy(&this->_data[i]);
			}
			return ;
		}

		size_type capacity() const
		{
			return this->_capacity;
		}

		bool empty() const {return (this->_size == 0);}

		void reserve(size_type size)
		{
			if (size > this->max_size())
			{
				throw std::length_error("reserve size requested is higher than max_size");
			}
			if (size > this->_capacity)
			{
				value_type *tmp = this->_data;
				std::size_t new_capacity = size > this->_capacity * 2 ? size : this->_capacity * 2;
				this->_data = this->_alloc.allocate(new_size); // potentiel leak?
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(this->_data + i, *(tmp + i));
				_alloc.deallocate(tmp, this->_capacity);
				this->_capacity = new_size;
			}
			return ;
		}

//		Element access

		reference operator[] (size_type n)
		{
			return this->_data[n];
		}

		reference at (size_type n)
		{
			if (n >= this->_size)
		 		throw std::out_of_range("index out of range");
		 	return this->_data[n];
		}

		const_reference operator[] (size_type n) const
		{
			if (n >= this->_size)
		 		throw std::out_of_range("index out of range");
		 	return this->_data[n];
		}

		reference front()
		{
			return this->_data[0];
		}

		const_reference front() const
		{
			return this->_data[0];
		}

		reference back()
		{
			return this->_data[this->_size - 1];
		}

		const_reference back() const
		{
			return this->_data[this->_size - 1];
		}


		private:
		
		void create_data(size_type size, const value_type &val)
		{
			this->_data = this->_alloc.allocate(size);
			this->_size = size;
			this->_capacity = size;
			for (size_type i = 0; i < size; i++)
				this->_alloc.construct(&this->_data[i], val);
			return ;
		}

		void create_data(InputIterator first, InputIterator last)
		{
			this->_data = this->_alloc.allocate(last - first);
			this->_size = last - first;
			this->_capacity = this->_size;
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.construct(&this->_data[i], first[i]);
			return ;
		}

		void	destroy_data(void)
		{
			for (size_type i = 0; i < this->_size; i++)
				this->_alloc.destroy(&this->_data[i]);
			this->_alloc.deallocate(this->_data, this->_capacity);
			this->_data = NULL;
			this->_size = 0;
			this->_capacity = 0;
			return ;
		}

	};
}
#endif