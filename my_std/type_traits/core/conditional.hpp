#ifndef MY_STD_TYPE_TRAITS_CORE_CONDITIONAL_HPP
#define MY_STD_TYPE_TRAITS_CORE_CONDITIONAL_HPP

namespace my_std {

template <bool Condition, typename TrueType, typename FalseType>
struct conditional;

template <typename TrueType, typename FalseType>
struct conditional<true, TrueType, FalseType> {
    using type = TrueType;
};

template <typename TrueType, typename FalseType>
struct conditional<false, TrueType, FalseType> {
    using type = FalseType;
};


template <bool Condition, typename TrueType, typename FalseType>
using conditional_t = typename conditional<Condition, TrueType, FalseType>::type;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_CORE_CONDITIONAL_HPP
