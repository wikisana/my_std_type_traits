#ifndef MY_STD_TYPE_TRAITS_QUERIES_PROPERTIES_HPP
#define MY_STD_TYPE_TRAITS_QUERIES_PROPERTIES_HPP

namespace my_std {

template <typename T>
struct is_trivial;

template <typename T>
struct is_trivially_copyable;

template <typename T>
struct is_standard_layout;

template <typename T>
struct is_empty;

template <typename T>
struct is_polymorphic;

template <typename T>
struct is_abstract;

template <typename T>
struct is_final;

template <typename T>
struct is_signed;

template <typename T>
struct is_unsigned;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_QUERIES_PROPERTIES_HPP
