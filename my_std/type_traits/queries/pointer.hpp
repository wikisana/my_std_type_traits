#ifndef MY_STD_TYPE_TRAITS_QUERIES_POINTER_HPP
#define MY_STD_TYPE_TRAITS_QUERIES_POINTER_HPP

#include "my_std/type_traits/core/integral_constant.hpp"
#include "my_std/type_traits/queries/cv.hpp"
#include "my_std/type_traits/queries/reference.hpp"
#include "my_std/type_traits/transformations/remove_cv.hpp"
namespace my_std {

namespace detail {
    template <typename T>
    struct is_pointer : false_type{};
    template <typename T>
    struct is_pointer<T*> :true_type{};
    template <typename Type>
    struct is_member_pointer : false_type{};
    template <typename Type, typename Class>
    struct is_member_pointer<Type Class::*> :true_type{};
    template <typename T>
    struct is_member_function_pointer:false_type{};
    template <typename T, typename Class>
    struct is_member_function_pointer<T Class::*> : bool_constant<!is_const_v<const T> && !is_reference_v<T>>{};
    template <typename T>
    struct is_member_object_pointer : false_type{};
    template <typename T, typename Class>
    struct is_member_object_pointer<T Class::*> : bool_constant<is_const_v<const T> || is_reference_v<T>>{};
}

template <typename T>
struct is_pointer : detail::is_pointer<remove_cv_t<T>> {};
template <typename T>
inline constexpr bool is_pointer_v = is_pointer<T>::value;


template <typename Type>
struct is_member_pointer : detail::is_member_pointer<remove_cv_t<Type>> {};
template <typename T>
inline constexpr bool is_member_pointer_v = is_member_pointer<T>::value;

template <typename T>
struct is_member_function_pointer : detail::is_member_function_pointer<remove_cv_t<T>> {};
template <typename T>
inline constexpr bool is_member_function_pointer_v = is_member_function_pointer<T>::value;

template <typename T>
struct is_member_object_pointer : detail::is_member_object_pointer<remove_cv_t<T>> {};
template <typename T>
inline constexpr bool is_member_object_pointer_v = is_member_object_pointer<T>::value;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_QUERIES_POINTER_HPP
