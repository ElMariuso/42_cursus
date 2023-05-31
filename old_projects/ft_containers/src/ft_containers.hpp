/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:54:24 by root              #+#    #+#             */
/*   Updated: 2023/02/17 22:58:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

/* Includes ***************************************************************** */

# include <stack>
# include <map>
# include <vector>
# include <deque>
# include <ctime>
# include <sys/time.h>

/* Containers *************************************************************** */

# include "../inc/containers/vector.hpp"
# include "../inc/containers/stack.hpp"
# include "../inc/containers/map.hpp"

/* Utils ******************************************************************** */

# include "../inc/utils/utility.hpp"
# include "../inc/utils/type_traits.hpp"
# include "../inc/utils/iterator.hpp"
# include "../inc/utils/algorithm.hpp"
# include "../inc/utils/functional.hpp"
# include "../inc/utils/tree.hpp"

/* Tests Vector ************************************************************* */

void    vector_constructor(); // 1
void    vector_constructor_value(); // 2
void    vector_constructor_iterator(); // 3
void    vector_copy_constructor(); // 4
void    vector_operator_assignement(); // 5
void    vector_assign_range(); // 6
void    vector_assign_value(); // 7
void    vector_at(); // 8
void    vector_operator_brackets(); // 9
void    vector_front(); // 10
void    vector_back(); // 11
void    vector_rbegin(); // 12
void    vector_rend(); // 13
void    vector_empty(); // 14
void    vector_size(); // 15
void    vector_capacity(); // 16
void    vector_clear(); // 17
void    vector_insert_mono(); // 18
void    vector_insert_multi(); // 19
void    vector_insert_range(); // 20
void    vector_erase(); // 21
void    vector_erase_range(); // 22
void    vector_push_back(); // 23
void    vector_pop_back(); // 24
void    vector_resize(); // 25
void    vector_swap(); // 26
void    vector_relational_operators(); // 27

/* Tests Stack ************************************************************** */

void    stack_constructor();  // 1
void    stack_operator_assignement(); // 2
void    stack_top(); // 3
void    stack_empty(); // 4
void    stack_size(); // 5
void    stack_relational_operators(); // 6

/* Tests Map **************************************************************** */

void    map_constructor(); // 1

#endif