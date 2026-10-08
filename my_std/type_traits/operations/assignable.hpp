#ifndef MY_STD_TYPE_TRAITS_OPERATIONS_ASSIGNABLE_HPP
#define MY_STD_TYPE_TRAITS_OPERATIONS_ASSIGNABLE_HPP

namespace my_std {

template <typename T, typename U>
struct is_assignable;

template <typename T>
struct is_copy_assignable;

template <typename T>
struct is_move_assignable;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_OPERATIONS_ASSIGNABLE_HPP
