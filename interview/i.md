# Interview

6种原始（Primitive）类型
- boolean
- number
- string
- undefined
- null
- symbol

typeof 对于原始类型来说，除了 null 都可以显示正确的类型；typeof 对于对象来说，除了函数都会显示 object，所以说 typeof 并不能准确判断变量到底是什么类型。

如果我们想判断一个对象的正确类型，这时候可以考虑使用 instanceof，因为内部机制是通过原型链来判断的，且他调用的是 `[Symbol.hasInstance]()`.比如，`foo instanceof Foo`在语言内部，实际调用的是`Foo[Symbol.hasInstance](foo)`。

