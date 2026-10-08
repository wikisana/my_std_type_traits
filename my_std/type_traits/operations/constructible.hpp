#ifndef MY_STD_TYPE_TRAITS_OPERATIONS_CONSTRUCTIBLE_HPP
#define MY_STD_TYPE_TRAITS_OPERATIONS_CONSTRUCTIBLE_HPP

namespace my_std {

template <typename T, typename... Args>
struct is_constructible;

template <typename T>
struct is_default_constructible;

template <typename T>
struct is_copy_constructible;

template <typename T>
struct is_move_constructible;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_OPERATIONS_CONSTRUCTIBLE_HPP
