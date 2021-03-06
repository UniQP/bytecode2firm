/*
 * Copyright (C) 1995-2008 University of Karlsruhe.  All right reserved.
 *
 * This file is part of libFirm.
 *
 * This file may be distributed and/or modified under the terms of the
 * GNU General Public License version 2 as published by the Free Software
 * Foundation and appearing in the file LICENSE.GPL included in the
 * packaging of this file.
 *
 * Licensees holding valid libFirm Professional Edition licenses may use
 * this file in accordance with the libFirm Commercial License.
 * Agreement provided with the Software.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE.
 */

/**
 * @file
 * @date    16.03.2007
 * @brief   Generic hashset functions
 * @author  Matthias Braun
 * @version $Id: hashset.h 20290 2008-06-30 12:12:49Z beck $
 *
 * You have to specialize this header by defining HashSet, HashSetIterator and
 * ValueType
 */
#ifdef HashSet

#include <stdlib.h>

#ifdef DO_REHASH
#define HashSetEntry ValueType
#else
typedef struct HashSetEntry {
	ValueType data;
	unsigned hash;
} HashSetEntry;
#endif

struct HashSet {
	HashSetEntry *entries;
	size_t num_buckets;
	size_t enlarge_threshold;
	size_t shrink_threshold;
	size_t num_elements;
	size_t num_deleted;
	int consider_shrink;
#ifndef NDEBUG
	unsigned entries_version;
#endif
#ifdef ADDITIONAL_DATA
	ADDITIONAL_DATA
#endif
};

#ifndef NO_ITERATOR
struct HashSetIterator {
	HashSetEntry *current_bucket;
	HashSetEntry *end;
#ifndef NDEBUG
	const struct HashSet *set;
	unsigned entries_version;
#endif
};
#endif

#ifdef DO_REHASH
#undef HashSetEntry
#endif

#endif
