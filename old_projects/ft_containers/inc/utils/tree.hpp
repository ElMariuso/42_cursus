/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:26:52 by mthiry            #+#    #+#             */
/*   Updated: 2023/02/17 23:41:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# include <memory>

# include "../containers/map.hpp"

namespace ft
{
    /* tree_is_left_child */
    template <class NodePtr>
    bool tree_is_left_child_base(NodePtr x)
    {
        return (x == x->parent->left);
    }
        
    /* tree_min_base */
    template <class NodePtr>
    NodePtr tree_min_base(NodePtr x)
    {
        while (x->left != NULL)
            x = x->left;
        return (x);
    }

    /* tree_max_base */
    template <class NodePtr>
    NodePtr tree_max_base(NodePtr x)
    {
        while (x->right != NULL)
            x = x->right;
        return (x);
    }
    
    /* tree_next */
    template <class NodePtr>
    NodePtr tree_next(NodePtr x)
    {
        NodePtr xx;

        if (x->right != NULL)
            return (tree_min_base(x->right));
        xx = x;
        while (!tree_is_left_child_base(xx))
            xx = xx->parent_unsafe();
        return (xx->parent_unsafe());
    }

    /* tree_prev */
    template <class NodePtr>
    NodePtr tree_prev(NodePtr x)
    {
        NodePtr xx;
        
        if (x->left != NULL)
            return (tree_max_base(x->left));
        xx = x;
        while (tree_is_left_child_base(xx))
            xx = xx->parent_unsafe();
        return (xx->parent_unsafe()); 
    }
    
    /* tree_node **************************************************************** */
    template <typename T>
    class tree_node
    {
        public:
            typedef T   value_type;

            value_type  value;
            tree_node   *parent;
            tree_node   *left;
            tree_node   *right;
        
        /* Constructor */
        tree_node(): value(), parent(NULL), left(NULL), right(NULL) {}
        tree_node(tree_node *left = NULL, tree_node *right = NULL, tree_node *parent = NULL):
            value(), parent(parent), left(left), right(right) {}
        tree_node(const value_type &val, tree_node *left = NULL, tree_node *right = NULL, tree_node *parent = NULL):
            value(val), parent(parent), left(left), right(right) {}
        tree_node(const tree_node &x): value(x.value), parent(x.parent), left(x.left), right(x.right) {}

        /* Destructor */
        virtual ~tree_node() {}

        /* operator= */
        tree_node& operator=(const tree_node &x)
        {
            if (x == *this)
                return (*this);
            this->value = x.value;
            this->parent = x.parent;
            this->left = x.left;
            this->right = x.right;
            return (*this);
        }

        /* operator== */
        bool operator==(const tree_node &x) { return (this->value == x.value); }

        /* parent_unsafe */
        tree_node *parent_unsafe() const { return (this->parent); }

        /* set_parent */
        void set_parent(tree_node *p) { this->parent = p; }
    };
    
    /* tree_iterator ************************************************************ */
    template <typename T, class Compare>
    class tree_iterator: ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        /* Member types ************************************************************* */
        public:
            typedef typename T::value_type                                                                  value_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category    iterator_category;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type      difference_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer              pointer;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference            reference;
            typedef T*                                                                                      iter_pointer;

        /* Attributes *************************************************************** */
        private:
            iter_pointer    node;
            Compare         comp;

        public:
        /* Member functions ********************************************************* */
        /***** Basic *****/
        /* Constructor */
        tree_iterator(const Compare &comp = Compare()): node(), comp(comp) {}
        tree_iterator(iter_pointer node, const Compare &comp = Compare()): node(node), comp(comp) {}
        tree_iterator(const tree_iterator &x): node(x.node), comp() {}

        /* Destructor */
        virtual ~tree_iterator() {}

        /* operator= */
        tree_iterator& operator=(const tree_iterator &x)
        {
            if (*this == x)
                return (*this);
            this->node = x.node;
            this->comp = x.comp;
            return (*this);
        }

        /* operator* */
        reference operator*() const { return(this->node->value); }

        /* operator-> */
        pointer operator->() const { return(&this->node->value); }

        /* operator++ */
        tree_iterator& operator++()
        {
            this->node = static_cast<iter_pointer>(tree_next<iter_pointer>(this->node));
            return (*this);
        }

        /* operator++(int) */
        tree_iterator operator++(int)
        {
            tree_iterator t(*this);
            
            ++(*this);
            return (t);
        }

        /* operator-- */
        tree_iterator& operator--()
        {
            this->node = static_cast<iter_pointer>(tree_prev<iter_pointer>(this->node));
            return (*this);
        }

        /* operator--(int) */
        tree_iterator operator--(int)
        {
            tree_iterator t(*this);
            
            --(*this);
            return (t);
        }

        /* operator== */
        bool operator==(const tree_iterator &x)
        { return (this->node == x.node); }

        /* operator!= */
        bool operator!=(const tree_iterator &x)
        { return (this->node != x.node); }
    };

    /* tree_const_iterator ********************************************************** */
    template <typename T, class Compare>
    class tree_const_iterator: ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        /* Member types ************************************************************* */
        public:
            typedef typename T::value_type                                                                  value_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category    iterator_category;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type      difference_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer              pointer;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference            reference;
            typedef T*                                                                                      iter_pointer;

        /* Attributes *************************************************************** */
        private:
            iter_pointer    node;
            Compare         comp;

        public:
        /* Member functions ********************************************************* */
        /***** Basic *****/
        /* Constructor */
        tree_const_iterator(const Compare &comp = Compare()): node(), comp(comp) {}
        tree_const_iterator(iter_pointer node, const Compare &comp = Compare()): node(node), comp(comp) {}
        tree_const_iterator(const tree_const_iterator &x): node(x.node), comp() {}

        /* Destructor */
        virtual ~tree_const_iterator() {}

        /* operator= */
        tree_const_iterator& operator=(const tree_const_iterator &x)
        {
            if (*this == x)
                return (*this);
            this->node = x.node;
            this->comp = x.comp;
            return (*this);
        }

        /* operator* */
        reference operator*() const { return (this->node->value); }

        /* operator-> */
        pointer operator->() { return (&this->node->value); }

        /* operator++ */
        tree_const_iterator& operator++()
        {
            this->node = static_cast<iter_pointer>(tree_next<iter_pointer>(this->node));
            return (*this);
        }

        /* operator++(int) */
        tree_const_iterator operator++(int)
        {
            tree_const_iterator t(*this);
            
            ++(*this);
            return (t);
        }

        /* operator-- */
        tree_const_iterator& operator--()
        {
            this->node = static_cast<iter_pointer>(tree_prev<iter_pointer>(this->node));
            return (*this);
        }

        /* operator--(int) */
        tree_const_iterator operator--(int)
        {
            tree_const_iterator t(*this);
            
            --(*this);
            return (t);
        }

        /* operator== */
        bool operator==(const tree_const_iterator &x)
        { return (this->node == x.node); }

        /* operator!= */
        bool operator!=(const tree_const_iterator &x)
        { return (this->node != x.node); }
    };

    /* tree ********************************************************************* */
    template <class T, class Compare = ft::less<T>, class Node = ft::tree_node<T>,
        class Allocator = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
    class tree
    {
        /* Member types ************************************************************* */
        public:
            typedef T                                           value_type;
            typedef Compare                                     value_compare;
            typedef Allocator                                   allocator_type;
            typedef Node_Alloc                                  node_alloc;
            typedef value_type&                                 reference;
            typedef const value_type&                           const_reference;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::difference_type    difference_type;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef Node                                        node_type;
            typedef Node*                                       node_pointer;
            typedef ft::tree_iterator<Node, Compare>            iterator;
            typedef ft::tree_const_iterator<Node, Compare>      const_iterator;

        /* Attributes *************************************************************** */
        private:
            node_pointer    _root;
            node_alloc      _node_alloc;
            size_type       _size;
            Compare         _comp;

        public:
        /* Member functions ********************************************************* */
        /***** Basic *****/
        /* Constructor */
        tree(const node_alloc &node_alloc_t = node_alloc()): _node_alloc(node_alloc_t), _size(0)
        {
            this->_root = this->_node_alloc.allocate(1);
            this->_node_alloc.construct(this->_root, Node(NULL, NULL, NULL));
        }

        /* Destructor */
        ~tree()
        {
            this->_node_alloc.destroy(this->_root);
            this->_node_alloc.deallocate(this->_root, 1);
        }

        /***** Iterators *****/
        /* begin */
        iterator begin() { return (iterator(this->tree_min(this->_root))); }
        const_iterator begin() const { return (const_iterator(this->tree_min(this->_root))); }

        /* end */
        iterator end() { return (iterator(this->_root)); }
        const_iterator end() const { return (const_iterator(this->_root)); }

        /* insert */
        ft::pair<iterator, bool> insert(value_type insert)
        {
            node_pointer    node;
            node_pointer    new_node;
            bool            side;

            node = this->_root;
            side = true;
            while (node != NULL)
            {
                if (node->value.first == insert.first)
                {
                    node->value.second = insert.second;
                    return (ft::make_pair(iterator(node, this->_comp), false));
                }
                if (!this->_comp(node->value.first, insert.first))
                {
                    if (node->left == NULL)
                    {
                        side = true;
                        break ;   
                    }
                    node = node->left;   
                }
                else
                {
                    if (node->right == NULL)
                    {
                        side = false;
                        break ;
                    }
                    node = node->right;   
                }
            }
            if (side == true)
            {
                new_node = this->_node_alloc.allocate(1);
                this->_node_alloc.construct(new_node, Node(insert, NULL, NULL, node));
                node->left = new_node;
                this->_size++;
                return (ft::make_pair(iterator(new_node, this->_comp), true));
            }
            else
            {
                new_node = this->_node_alloc.allocate(1);
                this->_node_alloc.construct(new_node, Node(insert, NULL, NULL, node));
                node->right = new_node;
                this->_size++;
                return (ft::make_pair(iterator(new_node, this->_comp), true));
            }
        }

        /* destroy */
        void    destroy(value_type remove)
        {
            node_pointer    node;
            node_pointer    parent;
            
            node = this->search(remove);
            parent = node->parent;
            if ((node->right == NULL) && (node->left == NULL))
            {
                if (this->tree_is_left_child(node) == true)
                    parent->left = NULL;
                else
                    parent->right = NULL;
                this->_node_alloc.destroy(node);
                this->_node_alloc.deallocate(node, 1);
                this->_size--;
            }
            else if ((node->right == NULL) ^ (node->left == NULL))
            {
                if (this->tree_is_left_child(node) == true)
                {
                    if (node->right != NULL)
                        parent->left = node->right;
                    else
                        parent->left = node->left;
                    parent->left->parent = parent;
                }
                else
                {
                    if (node->right != NULL)
                        parent->right = node->right;
                    else
                        parent->right = node->left;
                    parent->right->parent = parent;
                }
                this->_node_alloc.destroy(node);
                this->_node_alloc.deallocate(node, 1);
                this->_size--;
            }
            else
            {
                if (this->tree_is_left_child(node) == true)
                {
                    parent->left = node->left;
                    parent->left->parent = parent;
                    this->reinsert_node(node->right);
                }
                else
                {
                    parent->right = node->right;
                    parent->right->parent = parent;
                    this->reinsert_node(node->left);
                }
                this->_node_alloc.destroy(node);
                this->_node_alloc.deallocate(node, 1);
                this->_size--;
            }
        }

        /* search */
        node_pointer search(value_type search)
        {
            node_pointer    node;

            node = this->_root;
            while (node != NULL)
            {
                if (node->value.first == search.first)
                    return (node);
                if (!this->_comp(node->value.first, search.first))
                    node = node->left;
                else
                    node = node->right;
            }
            return (node);
        }

        /* swap */
        void swap(tree &x)
        {
            if (*this == x)
                return ;
            ft::swap(this->_root, x._root);
			ft::swap(this->_node_alloc, x._node_alloc);
        }

        /* max_size */
        size_type max_size() const { return (this->_node_alloc.max_size()); }

        /* getter */
        size_type get_size() const { return (this->_size); }

        /***** Utils Functions *****/
        private:
        /* insert_node */
        void    reinsert_node(node_pointer insert)
        {
            node_pointer    node;
            bool            side;

            node = this->_root;
            side = true;
            while (node != NULL)
            {
                if (!this->_comp(node->value.first, insert->value.first))
                {
                    if (node->left == NULL)
                    {
                        side = true;
                        break ;   
                    }
                    node = node->left;   
                }
                else
                {
                    if (node->right == NULL)
                    {
                        side = false;
                        break ;
                    }
                    node = node->right;   
                }
            }
            if (side == true)
                node->left = insert;
            else
                node->right = insert;
        }

        /* tree_is_left_child */
        bool tree_is_left_child(node_pointer x)
        {
            return (x == x->parent->left);
        }

        /* tree_min */
        node_pointer tree_min(node_pointer x) const
        {
            while (x->left != NULL)
                x = x->left;
            return (x);
        }

        /* tree_max */
        node_pointer tree_max(node_pointer x) const
        {
            while (x->right != NULL)
                x = x->right;
            return (x);
        }

        /* tree_next */
        node_pointer tree_next(node_pointer x) const
        {
            node_pointer xx;

            if (x->right != NULL)
                return (tree_min(x->right));
            xx = x;
            while (!tree_is_left_child(xx))
                xx = xx->parent_unsafe();
            return (xx->parent_unsafe());
        }

        /* tree_prev */
        node_pointer tree_prev(node_pointer x) const
        {
            node_pointer xx;
        
            if (x->left != NULL)
                return (tree_max(x->left));
            xx = x;
            while (tree_is_left_child(xx))
                xx = xx->parent_unsafe();
            return (xx->parent_unsafe()); 
        }

        /***** Utils Functions Public *****/
        public:
        /* isEmpty */
        bool isEmpty() const { return (this->_size == 0); }
    };
}

#endif