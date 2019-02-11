# Interview

## 找工作

https://www.zhipin.com/job_detail/db5e3672984fa2fb1X1-3tS6GFo~.html?ka=search_list_24

校招请官网投递 投递链接：https://job.bytedance.com/campus/
内推码： XADVXZP
前端（高级）研发工程师
岗位描述
1、负责今日头条相关产品前端业务实现。
2、负责WEB/WAP页面性能优化，打造良好的用户体验。
3、搭建高效的开发环境，review同事代码，确保工程质量。
岗位要求 学历本科及以上
1、熟悉WEB前端技术，对符合WEB标准的网站重构有丰富经验，有大型工程经验优先。
2、至少熟悉一门MVVM框架，熟悉React+Redux+Koa+Webpack+SSR技术栈优先。
3、精通HTML5、CSS3、ES6，熟悉HTTP协议和Node.js开发。
4、计算机基础扎实，熟悉常见的数据结构、算法和设计模式。
5、能够独立开发通用的UI组件，有UI组件开发经验优先。
6、团队精神，性格乐观，能积极面对压力。
7、有较强的逻辑思维能力，善于分析、归纳、解决问题。
8、学习能力强，有一定的技术视野。



## 学技术

6种原始（Primitive）类型
- boolean
- number
- string
- undefined
- null
- symbol

typeof 对于原始类型来说，除了 null 都可以显示正确的类型；typeof 对于对象来说，除了函数都会显示 object，所以说 typeof 并不能准确判断变量到底是什么类型。

如果我们想判断一个对象的正确类型，这时候可以考虑使用 instanceof，因为内部机制是通过原型链来判断的，且他调用的是 `[Symbol.hasInstance]()`.比如，`foo instanceof Foo`在语言内部，实际调用的是`Foo[Symbol.hasInstance](foo)`。


```js
var b = function() {
  function a() {
    console.log(this);
  }

  console.log(this);

  a();
};

b.call({});
// {}
// Window {postMessage: ƒ, blur: ƒ, focus: ƒ, close: ƒ, frames: Window, …}
```

以上证明：call等修改this只能改一层，下面的几层不会改变

箭头函数使用bind等函数无效，且不报错。箭头函数的 this 一旦被绑定，就不会再被任何方式所改变。

闭包：函数 A 内部有一个函数 B，函数 B 可以读写函数 A 中的变量，那么函数 B 就是闭包。

关于是否加分号： https://www.zhihu.com/question/20298345 所以就不加了。


`JSON.parse(JSON.stringify(object))` 深拷贝有如下问题：
- 会忽略 undefined
- 会忽略 symbol
- 不能序列化函数
- 不能解决循环引用的对象

`Reflect.ownKeys()`参数是object，其实 `[]` 也是object：

```js
const a = [1, 2, 3]

console.log(Reflect.ownKeys(a))
// (4) ["0", "1", "2", "length"]
```

当对象是函数时：

```js
let func = (a, b, c) => {
  return 1
}

Reflect.ownKeys(func).forEach(k => {
  console.log(k, func[k])
})
// length 3
// name func
```
