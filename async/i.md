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











法对应的不是遍历器生成函数


```js

```

