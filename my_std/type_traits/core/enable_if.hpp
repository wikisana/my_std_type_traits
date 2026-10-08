#ifndef MY_STD_TYPE_TRAITS_CORE_ENABLE_IF_HPP
#define MY_STD_TYPE_TRAITS_CORE_ENABLE_IF_HPP

namespace my_std {

template <bool Condition, typename T = void>
struct enable_if{};

template <typename T>
struct enable_if<true, T> {
    using type = T;
};

template <>
struct enable_if<true>{
    using type = void;
};

template <bool Condition, typename T = void>
using enable_if_t = typename enable_if<Condition, T>::type;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_CORE_ENABLE_IF_HPP
