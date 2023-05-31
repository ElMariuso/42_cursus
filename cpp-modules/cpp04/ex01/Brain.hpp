/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:16:07 by root              #+#    #+#             */
/*   Updated: 2022/10/20 23:21:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
    public:
        Brain(void);
        Brain(const Brain& rhs);
        Brain(const Brain* rhs);
        ~Brain(void);
        Brain& operator=(const Brain& rhs);
        /* Functions */
        void        setMultIdeas(std::string idea);
        void        setIdea(std::string idea, int i);
        std::string getIdea(int i) const;

    private:
        std::string _ideas[100];
};

#endif