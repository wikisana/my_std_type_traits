#ifndef MY_STD_TYPE_TRAITS_CORE_INTEGRAL_CONSTANT_HPP
#define MY_STD_TYPE_TRAITS_CORE_INTEGRAL_CONSTANT_HPP

namespace my_std {

template <typename T, T Value>
struct integral_constant{
    using value_type = T;
    using type = integral_constant<T, Value>;
    static constexpr T value = Value;

    constexpr value_type operator()() const {
        return Value;
    }

    constexpr operator value_type() const {
        return Value;
    }
};

using false_type = integral_constant<bool, false>;
using true_type = integral_constant<bool, true>;

}  // namespace my_std

#endif  // MY_STD_TYPE_TRAITS_CORE_INTEGRAL_CONSTANT_HPP
