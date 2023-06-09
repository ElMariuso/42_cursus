/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:56:02 by mthiry            #+#    #+#             */
/*   Updated: 2023/01/13 22:26:21 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

/* Includes ***************************************************************** */

# include <cstddef>
# include <memory>
# include <iostream>

/* Includes.h *************************************************************** */

# include "type_traits.hpp"

/* Namespace **************************************************************** */
namespace ft
{
    /* Types ******************************************************************** */
    struct output_iterator_tag {};
    struct input_iterator_tag {};
    struct forward_iterator_tag         : public input_iterator_tag {};
    struct bidirectional_iterator_tag   : public forward_iterator_tag {};
    struct random_access_iterator_tag    : public bidirectional_iterator_tag {};
    /* iterator_traits ********************************************************** */
    template <class Iter>
    struct iterator_traits
    {
        typedef typename Iter::difference_type      difference_type;
        typedef typename Iter::value_type           value_type;
        typedef typename Iter::pointer              pointer;
        typedef typename Iter::reference            reference;
        typedef typename Iter::iterator_category    iterator_category;
    };
    template <class T>
    struct iterator_traits<T*>
    {
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef ft::random_access_iterator_tag  iterator_category;
    };
    /* iterator ***************************************************************** */
    template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
    struct iterator
    {
        typedef Category   iterator_category;
        typedef T          value_type;
        typedef Distance   difference_type;
        typedef Pointer    pointer;
        typedef Reference  reference;
    };
    /* distance ***************************************************************** */
    template <class InputIter>
    typename ft::iterator_traits<InputIter>::difference_type
    distance(InputIter first, InputIter last)
    {
        typename ft::iterator_traits<InputIter>::difference_type r(0);
        for (; first != last; ++first)
            ++r;
        return (r);
    }
    /* reverse_iterator ********************************************************* */
    template <class Iter>
    class reverse_iterator :
        public ft::iterator<typename ft::iterator_traits<Iter>::iterator_category, typename ft::iterator_traits<Iter>::value_type,
                        typename ft::iterator_traits<Iter>::difference_type, typename ft::iterator_traits<Iter>::pointer,
                        typename ft::iterator_traits<Iter>::reference>
    {
        private:
            Iter    t; /* Not used */
            
        protected:
            Iter    current;

        public:
            /* Member types ************************************************************* */
            typedef Iter                                                iterator_type;
            typedef typename iterator_traits<Iter>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iter>::value_type          value_type;
            typedef typename iterator_traits<Iter>::difference_type     difference_type;
            typedef typename iterator_traits<Iter>::pointer             pointer;
            typedef typename iterator_traits<Iter>::reference           reference;

            /* Member function ********************************************************** */
            /***** Basic *****/
            /* Constructor */
            reverse_iterator() : t(), current() {}
            explicit reverse_iterator(Iter x) : t(x), current(x) {}
            template <class U>
            reverse_iterator(const reverse_iterator<U> &other) : t(other.base()), current(other.base()) {}
            
            /* operator= */
            template <class U>
            reverse_iterator& operator=(const reverse_iterator<U>& other) { this->t = this->current = other.base(); return (*this); }

            /* base */
            Iter base() const { return (this->current); }
            /* operator* */
            reference operator*() const
            { 
                Iter    tmp;
                
                tmp = this->current;
                return (*--tmp);
            }
            /* operator-> */
            pointer operator->() { return (&(this->operator*())); }
            /* operator[] */
            reference operator[](difference_type n) const { return (*(this->current + n)); }
            /* operator++ */
            reverse_iterator& operator++() { --this->current; return (*this); }
            /* ++operator (operator++(int)) */
            reverse_iterator operator++(int)
            {
                reverse_iterator    tmp;

                tmp = *this;
                --current;
                return (tmp);
            }
            /* operator+= */
            reverse_iterator& operator+=(difference_type n) { this->current -= n; return (*this); }
            /* operator+ */
            reverse_iterator operator+(difference_type n) const { return (reverse_iterator(this->current - n)); }
            /* operator-- */
            reverse_iterator& operator--() { ++this->current; return (*this); }
            /* --operator (operator--(int)) */
            reverse_iterator operator--(int)
            {
                reverse_iterator    tmp;

                tmp = *this;
                ++current;
                return (tmp);
            }
            /* operator-= */
            reverse_iterator& operator-=(difference_type n) { this->current += n; return (*this); }
            /* operator- */
            reverse_iterator operator-(difference_type n) const { return (reverse_iterator(this->current + n)); }
    };
    /* Non-Member function ****************************************************** */
    /* operator== */
    template <class Iter1, class Iter2>
    bool operator==(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    /* operator!= */
    template <class Iter1, class Iter2>
    bool operator!=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
    {
        return (lhs.base() != rhs.base());
    }
    /* operator< */
    template <class Iter1, class Iter2>
    bool operator<(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
    {
        return (lhs.base() < rhs.base());
    }
    /* operator<= */
    template <class Iter1, class Iter2>
    bool operator<=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    /* operator> */
    template <class Iter1, class Iter2>
    bool operator>(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
    {
        return (lhs.base() > rhs.base());
    }
    /* operator>= */
    template <class Iter1, class Iter2>
    bool operator>=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    /* operator+ */
    template <class Iter>
    reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &it)
    {
        return (reverse_iterator<Iter>(it.base() - n));
    }
    /* operator- */
    template <class Iter1, class Iter2>
    typename reverse_iterator<Iter1>::difference_type
    operator-(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs)
    {
        return (rhs.base() - lhs.base());
    }

    /* vt_iterator ************************************************************** */
    template <class Iter>
    class vt_iterator :
        public ft::iterator<typename ft::iterator_traits<Iter>::iterator_category, typename ft::iterator_traits<Iter>::value_type,
                        typename ft::iterator_traits<Iter>::difference_type, typename ft::iterator_traits<Iter>::pointer,
                        typename ft::iterator_traits<Iter>::reference>
    {       
        protected:
            Iter    current;

        public:
            /* Member types ************************************************************* */
            typedef Iter                                                iterator_type;
            typedef typename iterator_traits<Iter>::iterator_category   iterator_category;
            typedef typename iterator_traits<Iter>::value_type          value_type;
            typedef typename iterator_traits<Iter>::difference_type     difference_type;
            typedef typename iterator_traits<Iter>::pointer             pointer;
            typedef typename iterator_traits<Iter>::reference           reference;

            /* Member function ********************************************************** */
            /***** Basic *****/
            /* Constructor */
            vt_iterator() : current(NULL) {}
            explicit vt_iterator(Iter x) : current(x) {}
            template <class U>
            vt_iterator(const vt_iterator<U> &other) : current(other.base()) {}
            
            /* operator= */
            template <class U>
            vt_iterator& operator=(const vt_iterator<U>& other) { this->current = other.base(); return (*this); }

            /* base */
            Iter base() const { return (this->current); }
            /* operator* */
            reference operator*() const { return (*(this->current)); }
            /* operator-> */
            pointer operator->() { return (&(this->operator*())); }
            /* operator[] */
            reference operator[](difference_type n) const { return (*(this->current + n)); }
            /* operator++ */
            vt_iterator& operator++() { ++this->current; return (*this); }
            /* ++operator (operator++(int)) */
            vt_iterator operator++(int)
            {
                vt_iterator    tmp;

                tmp = *this;
                ++current;
                return (tmp);
            }
            /* operator+= */
            vt_iterator& operator+=(difference_type n) { this->current += n; return (*this); }
            /* operator+ */
            vt_iterator operator+(difference_type n) const { return (vt_iterator(this->current + n)); }
            /* operator-- */
            vt_iterator& operator--() { --this->current; return (*this); }
            /* --operator (operator--(int)) */
            vt_iterator operator--(int)
            {
                vt_iterator    tmp;

                tmp = *this;
                --current;
                return (tmp);
            }
            /* operator-= */
            vt_iterator& operator-=(difference_type n) { this->current -= n; return (*this); }
            /* operator- */
            vt_iterator operator-(difference_type n) const { return (vt_iterator(this->current - n)); }
    };
    /* Non-Member function ****************************************************** */
    /* operator== */
    template <class Iter1, class Iter2>
    bool operator==(const vt_iterator<Iter1> &lhs, const vt_iterator<Iter2> &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    /* operator!= */
    template <class Iter1, class Iter2>
    bool operator!=(const vt_iterator<Iter1> &lhs, const vt_iterator<Iter2> &rhs)
    {
        return (lhs.base() != rhs.base());
    }
    /* operator< */
    template <class Iter1, class Iter2>
    bool operator<(const vt_iterator<Iter1> &lhs, const vt_iterator<Iter2> &rhs)
    {
        return (lhs.base() < rhs.base());
    }
    /* operator<= */
    template <class Iter1, class Iter2>
    bool operator<=(const vt_iterator<Iter1> &lhs, const vt_iterator<Iter2> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    /* operator> */
    template <class Iter1, class Iter2>
    bool operator>(const vt_iterator<Iter1> &lhs, const vt_iterator<Iter2> &rhs)
    {
        return (lhs.base() > rhs.base());
    }
    /* operator>= */
    template <class Iter1, class Iter2>
    bool operator>=(const vt_iterator<Iter1> &lhs, const vt_iterator<Iter2> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    /* operator+ */
    template <class Iter>
    vt_iterator<Iter>
    operator+(typename vt_iterator<Iter>::difference_type n, const vt_iterator<Iter> &it)
    {
        return (vt_iterator<Iter>(it.base() - n));
    }
    /* operator- */
    template <class Iter1, class Iter2>
    typename vt_iterator<Iter1>::difference_type
    operator-(const vt_iterator<Iter1> &lhs, const vt_iterator<Iter2> &rhs) { return (lhs.base() - rhs.base()); }
}

#endif