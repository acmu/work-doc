# 每天都要写日报


#### 2019-3-25 23:37

面试过后，我也放松了两天，找同学玩了一下，还是很怀念那段时光。

其实能面试到三面，已经不错了，但最后没过，还是有些不甘心，尤其是问的进程线程，和内核态用户态，能问到操作系统去，也是厉害。还问hook使用限制的原理，我也知道深层原理重要，但面试大多不问啊，如果我花大段时间去这个深层原理，结果你考的是那个，那你让我怎么办？真的很恶心。

那好，现在就主**实践、深层原理、写文章总结**这3方面。

#### 2019-3-22 00:30

- [React 进阶](https://juejin.im/post/5c92f499f265da612647b754)
- [2个数之和，二分代码](https://gist.github.com/wen98y/a0975c31f8a8d3a2ae2b252deb9fc558) - [掘金文章](https://juejin.im/post/5c9437755188252da55958f4)
- async balel 怎么转的 -> @babel/plugin-transform-async-to-generator
- 一句话概述下什么是 promise http://es6.ruanyifeng.com/#docs/promise
  - 所谓Promise，简单说就是一个容器，里面保存着某个未来才会结束的事件（通常是一个异步操作）的结果。从语法上说，Promise 是一个对象，从它可以获取异步操作的消息。Promise 提供统一的 API，各种异步操作都可以用同样的方法进行处理。
  - 对象的状态不受外界影响，有三种状态：pending（进行中）、fulfilled（已成功）和rejected（已失败）
  - 一旦状态改变，就不会再变，任何时候都可以得到这个结果
- 前端存储方式，以及它们之间的优缺点。
  - cookie / local storage / session storage / Web SQL / indexedDB / service works + manifest
- 数组 拉平
```js
let arr = [1, [2, [3, 4]]]

function flattern(arr) {
  let result = []
  for (let i = 0; i < arr.length; i++) {
    if (Array.isArray(arr[i])) {
      flattern(arr[i])
    } else {
      result.push(arr[i])
    }
  }
  return result
}

function flatten(arr) {
  return arr
    .toString()
    .split(',')
    .map(function(item) {
      return +item
    })
}

function flatten(arr) {
  return arr.reduce(function(prev, next) {
    return prev.concat(Array.isArray(next) ? flatten(next) : next)
  }, [])
}

console.log(flattern(arr))
```

- [深拷贝 浅拷贝 赋值](https://juejin.im/post/59ac1c4ef265da248e75892b)
  - 浅拷贝是只深拷贝第一层，赋值是直接改
```js
function deepCopy(obj) {
  var result = Array.isArray(obj) ? [] : {}
  for (var key in obj) {
    if (obj.hasOwnProperty(key)) {
      if (typeof obj[key] === 'object') {
        result[key] = deepCopy(obj[key]) //递归复制
      } else {
        result[key] = obj[key]
      }
    }
  }
  return result
}
```
- [xss 跨站脚本攻击 xsrf 跨站请求伪造](https://juejin.im/post/5b6b08956fb9a04fc67c2263)
  - xss本质是html注入,和sql注入差不多
  - 预防xsrf：1.验证 Referer 2.Token
- [css 3列布局](https://gist.github.com/wen98y/3e5f4a2e39f8c65e9d2e889ca351a73f)
  - `flex grid position float:left+calc(a - b)`


- js继承
```js
// 寄生组合继承
function Parent(value) {
  this.val = value
}
Parent.prototype.getValue = function() {
  console.log(this.val)
}

function Child(value) {
  Parent.call(this, value)
}
Child.prototype = Object.create(Parent.prototype, {
  constructor: {
    value: Child,
    // enumerable: false, 默认是false
    writable: true,
    configurable: true
  }
})

const child = new Child(1)

child.getValue() // 1
child instanceof Parent // true

// 组合继承
function Parent(value) {
  this.val = value
}
Parent.prototype.getValue = function() {
  console.log(this.val)
}
function Child(value) {
  Parent.call(this, value)
}
Child.prototype = new Parent()

const child = new Child(1)

child.getValue() // 1
child instanceof Parent // true
```


#### 2019-3-21 08:56

- [写给初级前端的面试经验](https://juejin.im/post/5c8bb79e6fb9a04a006fe79a)
- [阿里CBU事业部前端社招面试总结](https://juejin.im/post/5c90f573e51d450a7d7dfc75)
```js
// transform('=g1.23 联调(-1)=，=g1.25 发布(+1)=') => `<g>1.23 联调(-1)</g>，<g>1.25 发布(+1)</g>`

transform = x => x.replace(/=g([^=]*)=/g, `<g>$1</g>`)

// merge([2, 2, 3, 4, 4, 2]) => [2, 3, 4, 2] 把后面的且相同的合并

merge = x => x.filter((num, idx, arr) => !idx || arr[idx] != arr[idx-1])

merge = x => (x + ',').replace(/(\d+,)\1+/g, '$1').split(',').slice(0, -1)

// 函数式编程中的组合函数 redux源码中有 https://github.com/reduxjs/redux/blob/master/src/compose.js
composeFunctions = (...funcs) => {
 if (funcs.length === 1) return funcs[0];
 return funcs.reduce((a, b) => (...args) => b(a(...args)))
}

```
  - 有成就感的项目，哪些地方让你特有成就感，还有遇到的困难是什么，如何解决的
  - 问问题：想要招什么样的人
  - 对于boss面问到的问题，我总结了一下其实这两个问题都很大。首先第一个问题，你在做什么？其实潜台词就是问你都做了什么项目，此时正确的做法是介绍自己参与的项目、所在项目的角色，然后详细讲解你参与项目的技术方案，开发过程中遇到的问题以及如何去解决这些问题，将主动权完全交给你，你可以自由发挥把面试官带到你的思路中。其实面试官更关心的是你解决问题的过程，而不是像我一样两句话搞定。第二个问题就是要详细介绍自己的产品，产品和其他竞品的优势在哪里？以及你贡献的内容和目前取得了什么样的成就等等。这种开放性的问题说好答也好答，说不好答也不好答，完全看自己的语言组织能力。
- [当我有一台云服务器时，我做了些什么](https://juejin.im/post/5c9232a8e51d45729b3b71e1)
  - 想学docker


#### 2019-3-20 08:03

- [面试总结](https://juejin.im/post/5c90ac91e51d45285210b4c9)
  - 写代码时不能只完成功能就行，还要注意代码可读性、复杂度
- [Spoon-Knife](https://github.com/octocat/Spoon-Knife)
  - practice pull request
- [学不进去，没时间学怎么办](https://mp.weixin.qq.com/s/aubZqAvinC9nZ8S8jq1fJw)
  - 如果学累了，就去看些有趣且有用的文章，而不是娱乐
- [git rebase](https://www.cnblogs.com/pinefantasy/articles/6287147.html)
  - 通过git rebase衍合（即合并分支）能产生一个更为整洁的提交历史。
  - 把解决分支补丁同最新主干代码之间的冲突的责任，划转给由提交补丁的人来解决。
- [玩一下github pages](https://blog.csdn.net/KNIGH_YUN/article/details/79774344)
  - 即只是搭了一个静态服务器，所以没有数据库，但如今前后端分离，还是有[解决办法](https://blog.csdn.net/baidu_25464429/article/details/80805237)，如leancloud
  - [还是挺好玩的](https://wen98y.github.io/pages-demo/)，可以写些项目或demo在上面

#### 2019-3-19 09:09

- node debug
  - `node --inspect-brk=9229 app.js` or `node --inspect app.js` and then check `about:inspect` in chrome
- `box-sizing: content-box | border-box | inherit`
- [ajax 状态码](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/readyState)

| Value | State              | Description                                                   |
| :---- | :----------------- | :------------------------------------------------------------ |
| 0     | `UNSENT`           | Client has been created. open() not called yet.               |
| 1     | `OPENED`           | open() has been called.                                       |
| 2     | `HEADERS_RECEIVED` | send() has been called, and headers and status are available. |
| 3     | `LOADING`          | Downloading; responseText holds partial data.                 |
| 4     | `DONE`             | The operation is complete.                                    |

- prevent xsrf: check cookie and token

#### 2019-3-18 09:07

- [bfc margin重叠](https://github.com/zuopf769/notebook/blob/master/fe/BFC%E5%8E%9F%E7%90%86%E5%89%96%E6%9E%90/README.md)
  - CSS2.1 中只有BFC和IFC, CSS3中还增加了G（grid）FC和F(flex)FC

```html
左右定宽，中间自适应
.le {
  float: left;
}
.ri {
  float: right:
}
.cen {
  overflow: hidden;
}

<div class="le"></div>
<div class="ri"></div>
<div class="cen"></div>
```


```html
css grid 居中
<style>
  .wrap {
    width: 400px;
    height: 400px;
    background-color: #cfc;
    display: grid;
  }
  .son {
    align-self: center;
    justify-self: center;
    background-color: #fcc;
  }
</style>
<body>
  <div class="wrap">
    <div class="son">sdf</div>
  </div>
</body>

flex 居中
display: flex;
align-items: center;
justify-content: center;

translate居中
position: absolute;
top: 50%;
left: 50%;
transform: translate(-50%, -50%);
```
- [redux source code](https://juejin.im/post/5b9617835188255c781c9e2f)


#### 2019-3-17 10:37

- [复习面试题和总结](https://github.com/LiangJunrong/document-library/blob/master/other-library/Interview/PersonalExperience/2019-InterviewPreparation.md#chapter-two-three)
  - 模块化：commonjs同步加载 AMD异步加载 CMD按需加载
  - write `call bind new Object.create` *gist add*


```js
Function.prototype.myCall = function(context) {
  // 判断是否是undefined和null
  if (typeof context === 'undefined' || context === null) {
    context = window
  }
  context.fn = this
  let args = [...arguments].slice(1)
  let result = context.fn(...args)
  delete context.fn
  return result
}

Function.prototype.myBind = function(context) {
  if (typeof this !== 'function') {
    throw new TypeError('Error')
  }
  let _this = this
  let args = [...arguments].slice(1)
  return function F() {
    // 判断是否被当做构造函数使用
    if (this instanceof F) {
      return _this.apply(this, args.concat([...arguments]))
    }
    return _this.apply(context, args.concat([...arguments]))
  }
}


Object.create =  function (o) {
    var F = function () {};
    F.prototype = o;
    return new F();
};


var obj = new Base();

var obj  = {};
obj.__proto__ = Base.prototype;
Base.call(obj);
```
  - Object deepClone 循环引用
  - 继承
  - 防抖与节流

#### 2019-3-16 07:01

- 编程题
- [js extends](http://www.ruanyifeng.com/blog/2011/06/designing_ideas_of_inheritance_mechanism_in_javascript.html)


```js
function Foo() {}
console.log(Foo.prototype.constructor === Foo) //true
var a = new Foo()
console.log(a.constructor === Foo) //true
```

#### 2019-3-15 01:18

- 笔试编程题 做完牛客网上以前的编程题
- [css grid](https://www.zhangxinxu.com/wordpress/2018/11/display-grid-css-css3/)
- js 继承
  - 深拷贝要记得特殊判断 Array
- [react life cycle: 16.3 and before](https://segmentfault.com/a/1190000016617400)

#### 2019-3-14 06:28

- [浏览器 import](https://www.zhangxinxu.com/wordpress/2018/08/browser-native-es6-export-import-module/)
  - 传统的内联 `<script>` 是没有 defer 这种概念的，从不异步
  - `access-control-allow-origin: https://www.zhangxinxu.com` 通过这个跨域，可设为 \*
  - import()返回一个 promise
- [Symbol tutorial](https://www.zhangxinxu.com/wordpress/2018/04/known-es6-symbol-function/)

```js
console.log(Symbol.for('a') === Symbol.for('a'))

let a = Symbol.for('b')

console.log(Symbol.keyFor(a))
// true
// b

var smy = Symbol()
var info = {
  smy: 'x',
  [smy]: 'y'
}

console.log(info.smy) // 输出'x'
console.log(info['smy']) // 输出'x'
console.log(info[smy]) // 输出'y'
```

- [script defer async](https://segmentfault.com/q/1010000000640869)

#### 2019-3-11 10:06

- css
  - absolute 和 float 同时存在时，float 无效果
- [从一个数组中找出 N 个数，其和为 M 的所有可能](https://mp.weixin.qq.com/s/2pJkk0avrTF3Vo1FEslRrQ)
  - `getState()` 返回 currentState 的引用，可以直接修改 state，但官方不建议

#### 2019-3-10 09:35

[北大算法课](https://www.coursera.org/learn/algorithms)

- [exports vs module.exports](https://github.com/nswbmw/N-blog/blob/master/book/2.2%20exports%20%E5%92%8C%20module.exports.md)
- [[1, 2].mul -> 1 2 1 4](https://gist.github.com/wen98y/26d2374a3f5c3b5c8032b61e61f83f0b)
- [一文读懂 HTTP/2 及 HTTP/3 特性](https://github.com/ljianshu/Blog/issues/57)

#### 2019-3-9 20:50

- node 书全部看完
- exports vs module.exports ?
- [1, 2].mul -> 1 2 1 4 ?

#### 2019-3-8 09:12

- react 文档
- redex 文档

#### 2019-3-7 09:43

- ts react

#### 2019-3-6 11:58

- [我在淘宝做前端的这三年 — 第二年](https://juejin.im/post/5c7dafe8f265da2de25bab27)

#### 2019-3-5 08:22

- node 看到 239

#### 2019-3-4 08:22

- 完成一篇文章 [js 冒泡排序动画](https://juejin.im/post/5c7cb5a6e51d4558d360609a)

#### 2019-3-3 06:09

- node 95 - 117

#### 2019-3-2 08:23

- [304 缓存](https://blog.csdn.net/canot/article/details/76359917)
  - Entity Tag -> If-None-Match
  - Catch-Control max-age public private no-catch no-store
- [强缓存 协商缓存](https://www.cnblogs.com/wonyun/p/5524617.html)
  - 协商缓存 Last-Modified/If-Modified-Since 和 Etag/If-None-Match
  - 强缓存 cache-control(请求头) expires
- [百度 前车之鉴](https://www.zhihu.com/question/311212158)
- [前端工程 cdn 部署](https://www.zhihu.com/question/20790576)
- hook: 完成 Using the State Hook
- render props

**todo**

- node 95 - 136

#### 2019-3-1 07:15

- [React hook](https://react.docschina.org/docs/hooks-intro.html)
- [CSS Grid](https://www.cnblogs.com/moqiutao/p/8682142.html)
- [我在淘宝做前端的这三年](https://zhuanlan.zhihu.com/p/55272391)
- [为前端工程之崛起而编程](https://juejin.im/post/5c77eecbf265da2d8532f345) 前端处于软件系统最上游，如果想提高影响力，那就要到下游

**todo**

- hook https://reactjs.org/docs/hooks-state.html#declaring-a-state-variable
- node 书每天 50 页，css 每天 30 页
- promise 封装 ajax
- context & render props

去年今日此门中，人面桃花相映红。人面不知何处去，桃花依旧笑春风。

**2019-2-28 09:29**

上次面试题复习完，敢于要提示。

- [String.prototype.replace()](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/String/replace#%E6%8F%8F%E8%BF%B0) \$n 假如第一个参数是 RegExp 对象，并且 n 是个小于 100 的非负整数，那么插入第 n 个**括号匹配**的字符串。提示：索引是从 1 开始

结论：要表达清晰，总结到位，即语言上的精炼

**2019-2-20 20:52**

完成了面试[css 总结](https://juejin.im/post/5c6b89386fb9a049e12ac56b)

**2019-2-19 07:39**

把面试内容深入复习一下。ts 和网络一点都没问，主要是 css、node 和 wp

努力，2020 年一定要迎来一个厉害的自己。

技术：

- 学习 position flex

**2019-2-17 17:11**

过几天要一直学车了，所以这几天一定要好好学

**2019-2-15 09:38**

主要看小册。深入 React 技术栈，wp 暂时放一下。

**2019-2-14 07:14**

最近感觉时间不够了，为了我想要的，有好多东西要学，所以效率很重要。

**2019-2-13 09:18**

这回是真的要准确完成任务了。把昨天的完成。

**2019-2-12 07:32**

今天用了 setup vpn 插件，很好用，以后可以买个服务器，用影梭玩玩。还看了 44 道 js 题，挺有意思的。

- node 40 页 95 - 135
- 小册 5 章 3 - 8
- wp 文档

**2019-2-11 10:52**

今天看面试小册，还是能学到些东西的。

**2019-2-10 08:56**

今天买了个掘金小册，关于面试的，这几天看下，还有 re + ts 熟悉下，之后 node 书，css 书。

**2019-2-9 08:28**

今天 ts handbook 部分看完。

**2019-2-8 08:20**

考虑到整体进度，英文文档确实有些慢，所以回到中文。

**2019-2-7 21:19**

多关注一下牛客网。

**2019-2-6 10:23**

不能只看 ts 啊，还要复习基础，刷面试题，写简历啊，这些都要并行啊。

总结：

- 再提高效率（专心致志做事），面试东西要准备一下了。

**2019-2-5 21:56**

今天回家了，确实有挺多事的，专心做事的时间就少了，所以好好弄啊，不要忘了自己想要的是什么！早点睡吧

**2019-2-4 13:56**

了解了一下 Dart，Flutter 和 JIT，AOT。感觉语言也就是那点事啊，还行学精了才厉害，还有确实强类型比弱类型爽。

看到 Generic Types

**2019-2-3 21:04**

哇，有些着急了，感觉自己的效率好低啊，需要提升啊。

**2019-2-2 10:33**

今天看完 ts 的 3 章吧，这周尽量把 ts 看完。handbook 还有 20 部分，5 天看完的话，每天要看 4 部分哦。

**2019-2-1 12:16**

今天把 ts 的 Basic Types 和 Variable Declarations 看完了，确实英文看着慢一些，但没办法啊，终究是要读的，等下把 wp + ts 弄好，明天要加快读文档的速度。

- 我真的有尽全力去学习吗？还差好多啊，你要知道你想要的是什么啊。
- 人生真的很短，时间过的真的很快，所以珍惜每一秒，不要浪费。

**2019-2-1 00:01**

今天做了一些准备工作，调整的一下心态，还不错吧。这周的主要目标是：ts 文档、wp 文档、node 书、css 书。还有就是看完的东西一定要有总结，有产出。
