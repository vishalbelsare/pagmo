/*****************************************************************************
 *   Copyright (C) 2004-2013 The PaGMO development team,                     *
 *   Advanced Concepts Team (ACT), European Space Agency (ESA)               *
 *   http://apps.sourceforge.net/mediawiki/pagmo                             *
 *   http://apps.sourceforge.net/mediawiki/pagmo/index.php?title=Developers  *
 *   http://apps.sourceforge.net/mediawiki/pagmo/index.php?title=Credits     *
 *   act@esa.int                                                             *
 *                                                                           *
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License, or       *
 *   (at your option) any later version.                                     *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.               *
 *****************************************************************************/

#ifndef PAGMO_UTIL_LEBMEASURE_H
#define PAGMO_UTIL_LEBMEASURE_H

#include <iostream>
#include <string>
#include <vector>

#include "../config.h"
#include "../serialization.h"
#include "../pagmo.h"

namespace pagmo { namespace util {

/// lebmeasure_points typedef
/**
 * This is the main container type, used for LebMeasure.
 * std::deque is used for the purpose of fast insertion and removal at the two ends of the list.
 * Because we need to store a "spawn dimension" along with given point, we use std::deque of std::pair<fitness_vector, fitness_vector::size_type>.
 * Spawn dimension is originally equal to fitness_vector.size() for each point, but it changes over the course of the algorithm.
 */
typedef std::deque<std::pair<fitness_vector, fitness_vector::size_type> > lebmeasure_points;

/// lebmeasure class.
/**
 * This is the class containing implementation of the LebMeasure algorithm
 *
 * @see L. While, "A new analysis of the LebMeasure Algorithm for Calculating Hypervolume"
 * @author Krzysztof Nowak (kn@kiryx.net)
 */
class lebmeasure
{
	public:
		static double compute(const std::vector<fitness_vector> &, const fitness_vector &);

	private:
		/// Methods below are used by the LebMeasure algorithm
		static lebmeasure_points generate_spawns(const fitness_vector &, const fitness_vector::size_type, const fitness_vector &, lebmeasure_points &, const fitness_vector &);
		static bool dominated(const fitness_vector &, lebmeasure_points &);
		static double volume_between(const fitness_vector &, const fitness_vector &);
		static fitness_vector get_opposite_point(const fitness_vector &, lebmeasure_points &, const fitness_vector &);

};

}}

#endif
