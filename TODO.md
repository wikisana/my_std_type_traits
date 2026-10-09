# TODO

## 下一步：补齐 cv 添加变换

优先实现 `my_std/type_traits/transformations/add_cv.hpp`：

- `add_const` / `add_const_t`
- `add_volatile` / `add_volatile_t`
- `add_cv` / `add_cv_t`
- 对普通类型、数组、函数和引用分别与 `std::type_traits` 对照测试
- 确保引用类型不会被错误地添加 cv 限定

选择它作为下一步，是因为实现规模小，并且能与已经完成的
`remove_const`、`remove_volatile` 和 `remove_cv` 形成完整的一组基础变换。

## 后续顺序

1. 实现 `add_reference.hpp`，覆盖 `void` 等无法形成引用的类型。
2. 实现 transformations 下的 `pointer.hpp`：`remove_pointer` 和 `add_pointer`。
3. 实现 transformations 下的 `array.hpp`：`remove_extent` 和 `remove_all_extents`。
4. 为 `is_object`、`is_scalar`、`is_compound` 补齐对应的 `_v` 变量模板。
5. 将根目录测试拆成按模块组织的测试文件，并同时覆盖正例、反例和 cv/ref 边界。
6. 完成 queries 后，再实现 constructible、assignable、destructible 和 invoke_result。

## 每个模块的验收标准

- 可以单独包含对应头文件，不依赖总入口的包含顺序。
- 使用 GCC 的 C++17 模式通过 `-Wall -Wextra -Wpedantic` 编译。
- 对照对应的 `std::type_traits`，覆盖普通类型、cv 类型、引用、数组、函数和成员指针。
- 新增公共 trait 时，同时提供结构体和标准命名形式的 `_t` 或 `_v` 辅助接口。
