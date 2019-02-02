promise新建后立即执行

promise的状态，会受返回的promise的状态影响

调用resolve或reject并不会终结 Promise 的参数函数的执行

then方法返回的是一个新的Promise实例（注意，不是原来那个Promise实例）

Promise 内部的错误不会影响到 Promise 外部的代码，通俗的说法就是“Promise 会吃掉错误”。

Promise.prototype.finally() es18引入

它的实现
```js
Promise.prototype.finally = function (callback) {
  let P = this.constructor;
  return this.then(
    value  => P.resolve(callback()).then(() => value),
    reason => P.resolve(callback()).then(() => { throw reason })
  );
};
```



http://es6.ruanyifeng.com/#docs/promise#Promise-all


注意，如果作为参数的 Promise 实例，自己定义了catch方法，那么它一旦被rejected，并不会触发Promise.all()的catch方法。


```js
Promise.resolve('foo')
// 等价于
new Promise(resolve => resolve('foo'))
```



```js
setTimeout(function () {
  console.log('three');
}, 0);

Promise.resolve().then(function () {
  console.log('two');
});

console.log('one');

// one
// two
// three
```

上面代码中，setTimeout(fn, 0)在下一轮“事件循环”开始时执行，Promise.resolve()在本轮“事件循环”结束时执行，console.log('one')则是立即执行，因此最先输出。


下面是另一个类似数组的对象调用数组的Symbol.iterator方法的例子。

```js
let iterable = {
  0: 'a',
  1: 'b',
  2: 'c',
  length: 3,
  [Symbol.iterator]: Array.prototype[Symbol.iterator]
};
for (let item of iterable) {
  console.log(item); // 'a', 'b', 'c'
}
```



next 方法的参数
yield表达式本身没有返回值，或者说总是返回undefined。next方法可以带一个参数，该参数就会被当作上一个yield表达式的返回值。


如果想要第一次调用next方法时，就能够输入值，可以在 Generator 函数外面再包一层。


Generator 函数体外抛出的错误，可以在函数体内捕获；反过来，Generator 函数体内抛出的错误，也可以被函数体外的catch捕获。g.throw 和 throw 的区别


yield*表达式，用来在一个 Generator 函数里面执行另一个 Generator 函数。


从实现上看，在内存中，子例程只使用一个栈（stack），而协程是同时存在多个栈，但只有一个栈是在运行状态，也就是说，协程是以多占用内存为代价，实现多任务的并行。



一个有趣的问题是，为什么 Node 约定，回调函数的第一个参数，必须是错误对象err（如果没有错误，该参数就是null）？

原因是执行分成两段，第一段执行完以后，任务所在的上下文环境就已经结束了。在这以后抛出的错误，原来的上下文环境已经无法捕捉，只能当作参数，传入第二段。



一种意见是"传值调用"（call by value）c语言

另一种意见是“传名调用”（call by name）Haskell


JavaScript 语言是传值调用，它的 Thunk 函数含义有所不同。在 JavaScript 语言中，Thunk 函数替换的不是表达式，而是多参数函数，将其替换成一个只接受回调函数作为参数的单参数函数。



async函数的返回值是 Promise 对象，这比 Generator 函数的返回值是 Iterator 对象方便多了。你可以用then方法指定下一步的操作。

进一步说，async函数完全可以看作多个异步操作，包装成的一个 Promise 对象，而await命令就是内部then命令的语法糖。


async函数 自带执行器的generator


```js
async function getTitle(url) {
  let response = await fetch(url);
  let html = await response.text();
  return html.match(/<title>([\s\S]+)<\/title>/i)[1];
}
getTitle('https://tc39.github.io/ecma262/').then(console.log)  // 这里写的足够骚气，可以的 老铁
```



await 命令
正常情况下，await命令后面是一个 Promise 对象，返回该对象的结果。如果不是 Promise 对象，就直接返回对应的值


Where are variables in a closure stored - stack or heap?

stack [answer](https://stackoverflow.com/questions/29225834/where-are-variables-in-a-closure-stored-stack-or-heap)

[closure](https://stackoverflow.com/questions/111102/how-do-javascript-closures-work?rq=1)



async 函数可以保留运行堆栈。

```js
const a = () => {
  b().then(() => c());
};
```

上面代码中，函数a内部运行了一个异步任务b()。当b()运行的时候，函数a()不会中断，而是继续执行。等到b()运行结束，可能a()早就运行结束了，b()所在的上下文环境已经消失了。如果b()或c()报错，错误堆栈将不包括a()。

现在将这个例子改成async函数。

```js
const a = async () => {
  await b();
  c();
};
```

上面代码中，b()运行的时候，a()是暂停执行，上下文环境都保存着。一旦b()或c()，错误堆栈将包括a()。


虽然 Promise 的写法比回调函数的写法大大改进，但是一眼看上去，代码完全都是 Promise 的 API（then、catch等等），操作本身的语义反而不容易看出来。 （所以说promise也就是个美丽的意外 哈？）


ES2018 引入了”异步遍历器“（Async Iterator），为异步操作提供原生的遍历器接口，即value和done这两个属性都是异步产生。




异步 Generator 函数
就像 Generator 函数返回一个同步遍历器对象一样，异步 Generator 函数的作用，是返回一个异步遍历器对象。

