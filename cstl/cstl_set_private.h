/*
 *  The private interface of set.
 *  Copyright (C)  2008,2009,2010,2011  Wangbo
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  Author e-mail: activesys.wb@gmail.com
 *                 activesys@sina.com.cn
 */

#ifndef _CSTL_SET_PRIVATE_H_
#define _CSTL_SET_PRIVATE_H_

#ifdef __cplusplus
extern "C" {
#endif

/** include section **/

/** constant declaration and macro section **/

/** data type declaration and struct, union, enum section **/
/* the set use rbtree default */
typedef struct _tagset
{
#ifdef CSTL_SET_AVL_TREE
    _avl_tree_t _t_tree;
#else
    _rb_tree_t  _t_tree;
#endif
}set_t;

/** exported global variable declaration section **/

/** exported function prototype section **/
/**
 * Create set container.
 * @param s_typename        element type name.
 * @return if create set successfully return set pointer, otherwise return NULL.
 * @remarks s_typename == NULL, then the behavior is undefined. s_typename should be C builtin type name, libcstl builtin
 *          typename or registed user defined type name, otherwise the function will return NULL.
 */
extern set_t* _create_set(const char* s_typename);

/**
 * Create set container auxiliary function.
 * @param pt_set            uncreated container.
 * @param s_typename        element type name.
 * @return if create set successfully return true, otherwise return false.
 * @remarks if pt_set == NULL or s_typename == NULL, then the behavior is undefined. s_typename should be C builtin
 *          type name, libcstl builtin typename or registed user defined type name, otherwise the function will return false.
 */
extern bool_t _create_set_auxiliary(set_t* pt_set, const char* s_typename);

/**
 * Destroy set container auxiliary function.
 * @param pt_set        set container.
 * @return void.
 * @remarks if pt_set == NULL, then the behavior is undefined. set must be initialized or created by
 *          _create_set(), otherwise the behavior is undefine.
 */
extern void _set_destroy_auxiliary(set_t* pt_set);

/*
 * Find operation functions.
 */
extern set_iterator_t _set_find(const set_t* cpt_set, ...);
extern set_iterator_t _set_find_varg(const set_t* cpt_set, va_list val_elemlist);

/*
 * Count operation functions.
 */
extern size_t _set_count(const set_t* cpt_set, ...);
extern size_t _set_count_varg(const set_t* cpt_set, va_list val_elemlist);

/*
 * Lower bound, upper bound and equal range operation functions.
 */
extern set_iterator_t _set_lower_bound(const set_t* cpt_set, ...);
extern set_iterator_t _set_lower_bound_varg(const set_t* cpt_set, va_list val_elemlist);
extern set_iterator_t _set_upper_bound(const set_t* cpt_set, ...);
extern set_iterator_t _set_upper_bound_varg(const set_t* cpt_set, va_list val_elemlist);
extern range_t _set_equal_range(const set_t* cpt_set, ...);
extern range_t _set_equal_range_varg(const set_t* cpt_set, va_list val_elemlist);

/*
 * Erase element from set_t.
 */
extern size_t _set_erase(set_t* pt_set, ...);
extern size_t _set_erase_varg(set_t* pt_set, va_list val_elemlist);

/*
 * Insert element from set_t.
 */
extern set_iterator_t _set_insert_hint(set_t* pt_set, set_iterator_t t_hint, ...);
extern set_iterator_t _set_insert_hint_varg(
    set_t* pt_set, set_iterator_t t_hint, va_list val_elemlist);
extern set_iterator_t _set_insert(set_t* pt_set, ...);
extern set_iterator_t _set_insert_varg(set_t* pt_set, va_list val_elemlist);

extern void _set_init_elem_auxiliary(set_t* pt_set, void* pv_value);

#ifdef __cplusplus
}
#endif

#endif /* _CSTL_SET_PRIVATE_H_ */
/** eof **/

