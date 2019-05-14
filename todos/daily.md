# 每天都要写日报

- [nginx 入门](https://www.bilibili.com/video/av34537494?from=search&seid=10057962381467933650) [Docker 从入门到实践](https://docker_practice.gitee.io/image/pull.html) [dart 入门](https://www.imooc.com/learn/1035) [Flutter 入门](https://www.imooc.com/learn/1090) [3 小时速成 Vue2.x 核心技术](https://www.imooc.com/learn/1091)
- [redux-actions](https://github.com/redux-utilities/redux-actions) [ducks-modular-redux](https://github.com/erikras/ducks-modular-redux) redux-saga `bindActionCreators` & practice `context` & SSR Next & Ts & Vue2.5 学习

* [16 生命周期函数使用](https://blog.bitsrc.io/react-16-lifecycle-methods-how-and-when-to-use-them-f4ad31fb2282)

### 2019-5-14 22:35:54

- 完成论文

### 2019-5-13 00:07:01

- dart `==` 只检查内容是否相等，而不是地址
- flutter 一切都是组件

### 2019-5-12 20:56:50

- dart是面向对象的语言
- ss的PAC模式：只在固定的一些网站翻墙，全局模式：所有网站全翻
- dart内置类型：`Number String Boolean List Map Runes Symbols`
- [vsc快捷键](https://www.cnblogs.com/bindong/p/6045957.html) `Ctrl+Shift+O 或 Ctrl+P @`类的变量或方法

### 2019-5-11 12:38:11

- 在指定目录下生成ssh公钥和私钥 `ssh-keygen -t rsa -C "s1124yy@qq.com"` 之后可以自定义文件路径，`ssh -T git@gitee.com`测试连接
- `git config --list`查看设置项
```
git config --global user.name Yuan # 全局
git config --global user.email wen98y@gmail.com

git config user.email s1124yy@qq.com
```

### 2019-5-8 17:49:29

- 写论文 5000 字
- 学习 Election

### 2019-5-7 10:52:38

- vue 视频 看到 7-3
- `computed` 计算属性会缓存，只有它依赖的属性改变时，它才会重新计算
- vue 对于数组会响应7个方法 `push pop shift unshift splice sort reverse` 或直接改变引用，也可以响应视图
- `<template /> === <Fragment />`
- 动态组件 `<component :is='type'></component>` `v-once` 指令放入内存中，提高性能
- css动画 `fade-enter fade-enter-active fade-enter-to & fade-leave fade-leave-active fade-leave-to`
- js动画，提供了钩子 `@before-enter(el) @enter(el, done) @after-enter(el) @before-leave(el) @leave(el, done) @after-leave(el)`
- `reset.css` 重置浏览器样式 `border.css` 修复移动端1px问题 `npm i -D fastclick` 解决移动端click事件可能会有300毫秒延迟问题

### 2019-5-6 13:08:40

- vue 视频 看到 3-4
  - `new Vue({el: '', data: {}})` 传入的是 Vue 实例配置项
  - 普通的是 MVP 设计模式，如 jQ，presenter 是中转层，有大量 dom 操作，处理 view 和 model；而 mvvm 层，只需要编写 m 和 v 就够了，vm 是 vue 提供的
  - 父向子传值 `v-bind` 和 `props` 接收，子向父传值 `this.$emit()` 触发事件，父组件监听。 `v-bind=:  v-on=@  记法 i对应: o对应@`
  - `beforeMount` 页面还没有渲染， `mounted` 页面渲染完成
  - vue 共 11 个生命周期函数，除了常用的8个 `create mount destory update
- 调教 sublime (只当一个简单编辑器使用， 真不如 vsc 好用)

tool > developer > new snippet

```xml
<snippet>
  <content><![CDATA[
console.log(${1:xiou})
]]></content>
  <!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
  <tabTrigger>clg</tabTrigger>
  <!-- Optional: Set a scope to limit where the snippet will trigger -->
  <scope>source.js</scope>
</snippet>
```

setting

```json
{
  "color_scheme": "Packages/Color Scheme - Default/Monokai.sublime-color-scheme",
  "font_face": "Microsoft YaHei Mono",
  "font_size": 14,
  "theme": "Default.sublime-theme",
  "translate_tabs_to_spaces": true,
  "tab_size": 2,
  "trim_trailing_white_space_on_save": true,
  "ensure_newline_at_eof_on_save": true
}
```

perference > keybinding

```json
[
  { "keys": ["shift+alt+f"], "command": "reindent" },
  { "keys": ["ctrl+s"], "command": "save_all" }
]
```

### 2019-5-5 15:38:02

- 找到一些 chrome [插件](https://www.bilibili.com/video/av43178936)

### 2019-5-2 00:21:26

- `Tagged templates` [标签模版](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Template_literals#Tagged_templates) 第一个参数是字符串数组，其余的是表达式
- 既然用了 `redux` 那么能存到 `redux` 里的，就都要存到 `redux` 里，这对后期维护很好
- `combineReducers` 后， `stateToProps` 要多加一层才能获取到数据，但 `reducer` 不需要多加一层，就可以直接修改这一层下面的数据
- `immutable` 确保 `reducer` 无副作用，即不会修改原始 `store`
- `redux-immutable` 让 `store` 由一个普通对象变成 `immutable` 类型
- `stateless component` 写函数，要在 `stateless component` 外面写 `const foo = () => {}`
- 要使得 `redux` 中，除了 `store` ，其他底下的类型都是 `immutable` 的
- `fromJS` 是深层的，会把每一层都变成 `immutable` 的
- `const mapDispatchToProps = (dispatch, ownProps) => {}` `function mapStateToProps(state, ownProps?)` 所以如果 `Dispatch` 要获取 store 数据，只能从 `mapStateToProps` 当参数传过来
- `immutable` 的 `set OR setIn` 设置 1 个值， `merge({})` 设置多个值
- `react-redux` 的 `Provider BrowserRouter` 下面只能有一个元素

```js
store.merge({
  todoList: fromJS(action.todoList) // 这样写才对，进入 store 前一定变成 immutable 的
});
```

- `PureComponent` 自带了 `shouldComponentUpdate()` 优化 且一定要和 `immutable` 结合使用，否则会有问题
- `styled-components` 要使用 `ref` 时，用 `innerRef` 代替
- `react-router-dom` 有 `withRouter` 方法，可以给组件拿到路由数据
- react-loadable 可以动态加载组件 js 代码
- 1 个 tcp 连接可以对应多个 http 请求，并且 http2 里面 1 个 tcp 连接上，http 的请求可以并发
- 跨域的请求其实是已经发送到服务器了的，并且服务器也响应了，只是到了浏览器，会检查`Access-Control-Allow-Origin` 如果没有这个响应头，浏览器会忽略响应，并报错。所以说这是浏览器的同源策略，即你用 `curl` 的话，是不会出现跨域这一说的。
- 有些跨域会发送预请求，方法是 `OPTIONS` 如果合理再去发送跨域的方法
- 跨域 CORS 默认允许的方法`get post head`，默认允许的`Content-Type` `text/plain multipart/form-data application/x-www-form-urlencoded` 所以服务端可以响应`OPTIONS` 来响应是否让浏览器跨域
- no-catch 有缓存，但是要向服务器协商确认， no-store 不缓存
- catch-control 是客户端缓存，只要 304 就直接拿浏览器的缓存数据，不会管服务器的返回数据
- 302 暂时跳转； 301 永久跳转
- `Content-Security-Policy` 即 CSP 可以现在外链的 src 路径，或 inline script
- `Vary: X-Test-Cache` 当多个请求时，除了 url 相同 `X-Test-Cache` 头在缓存中的值也相同时，才会缓存
- 只有私钥才能解密出公钥加密过的数据，公钥任何人都可以拿到，私钥只放在服务器上。
  - 公钥 私钥 使用在握手过程中，传输的是`加密字符串`，最后基于`加密字符串`加密数据，并且只有 客户端 服务端 知道`加密字符串` 其他人不知道
- chorme 并发 TCP 连接 6 个

### 2019-5-1 11:14:57

- `componentWillReceiveProps` 一个组件要从父组件接收参数，只要父组件的 `render` 重新函数执行了，子组件的这个生命周期函数就会执行
- `shuoldComponentUpdate(nextProps, nextState)` 当父组件的 `render` 执行时，子组件的 `render` 也会执行，所以可以用这个来判断是否真的要执行，以提升性能

```css
.hide {
  animation: hide-item 2s ease-in forwards;
}

@keyframes hide-item {
  0% {
    opacity: 1;
    color: red;
  }
  50% {
    opacity: 0.5;
    color: green;
  }
  100% {
    opacity: 0;
    color: blue;
  }
}
```

- css 动画中 `forwards` 会保存最后一帧的样式，如果不加，则还是原来的样式

```css
.fade-enter,
.fade-appear {
  opacity: 0;
}

.fade-enter-active,
.fade-appear-active {
  opacity: 1;
  transition: opacity 1s ease-in;
}

.fade-enter-done {
  opacity: 1;
}

.fade-exit {
  opacity: 1;
}

.fade-exit-active {
  opacity: 0;
  transition: opacity 1s ease-in;
}

.fade-exit-done {
  opacity: 0;
}
```

- `react-transition-group` 的 `CSSTransition` 使用： `classNames='fade'`
- `createStore` 要传入 `reducer` ，之后可以 `store.getState()` 获取数据
- `reducer` 是一个函数，有 2 个参数：原来的 `state`，和 `action`。返回值是新的 `state`
- `store.dispatch(action)` 接收到 `action` 会自动调用 `reducer`
- `store.subscribe(f => f)` 只要 store 改变，函数就会执行

```js
// immediate 立即执行的
let x = 1 + 2;

// foo is a thunk 没有立即执行，是以后调用的
let foo = () => 1 + 2;
```

- `redux-thunk` 可以把异步代码放到 `action` 中，使 `actionCreator` 可以返回函数： `(dispath, getState) => {}`，即 `action` 可以是函数了，不是只能对象
- `redux` 中间件指 `action` 和 `store` 之间
- 引入 `redux-saga` 之后 `store.dispath(action)` 时，除了 `reducer` 会拿到 `action` 外，`sagas.js` 的 `generator` 中也可以拿到 `action`
- `sagas.js` `export default generator 函数`
  - `takyEvery(actionType, f => f)` 当 dispatch actionType 的 action 时，会调用 f 函数，f 函数里可以用 `put(action)` 来派发 `action` 因为 `sagas.js` 没有 `store` 所以只能用这种方法改变 `store`
- [引入](https://meyerweb.com/eric/tools/css/reset/) `reset.css` 使各个浏览器样式兼容 或 [normalize.css](https://github.com/necolas/normalize.css/)

### 2019-4-30 22:30:00

- 完成物流系统
- `dangerouslySetInnerHTML={{__html: '<h1>sfdf</h1>'}}` 不转义
- 推荐 `setState(previousState => {})` 里面用函数，是异步获取数据，所以 `e.target.value` 会不能用，解决办法是用闭包，在外面把 `value` 保存，之后在传入 `setState` 里的函数
- jQuery 命令式 React 声明式
- 当组件的 `state` 或 `props` 发生改变时， `render` 函数就会重新执行； 当父组件 `render` 函数执行时，子组件 `render` 也会重新执行
- `ref={(ipt) => {this.input = ipt}}` ref 的使用

### 2019-4-29 15:21:31

- mac 中 `open .` 打开目录， win 中用 `start .` 还可以 `start ..`
- cmd 清屏 `cls OR clear`

### 2019-4-26 13:22:55

- 完成客户模块
- `nodemon -- --inspect app.js` nodemon 下 debug node `chrome://inspect`

### 2019-4-24 12:54:14

- 完成前后端登陆功能，退出登陆
- `export default {}` -> `import A from 'xx'` 另外 `export const a` -> `import { a } from 'xx'` 只能这样对应，不能混着用

### 2019-4-23 09:49:17

- rhl 还不支持 hook

### 2019-4-22 11:11:15

- 搭建[react 开发环境](https://github.com/Acmu/transport-man)

### 2019-4-21 16:01:01

- [16 生命周期函数使用](https://blog.bitsrc.io/react-16-lifecycle-methods-how-and-when-to-use-them-f4ad31fb2282)

### 2019-4-20 10:22:06

- 编写第三方库 `output: { libraryTarget: 'umd', library: 'lib' }` `script:src` 时挂在 `window` 上，叫 `lib`
- `externals: ["lodash"]` 忽略这个库的打包
- PWA 可以用 `workbox-webpack-plugin` 插件 `new WorkboxPlugin.GenerateSW({})` 再加上业务代码 `navigator.serviceWorker.register('./server-worker.js')`
- `add-asset-html-webpack-plugin` 添加全局变量 打包第三方库 dll `webpack.DllReferencePlugin`
- 多进程打包 `thread-loader happy-pack`
- 多页面打包，配置多个 `new HtmlWebpackPlugin({ template, filename, chunks })`
- loader 实现国际化 实现异常捕获

### 2019-4-19 09:29:14

- `file-loader` 把文件（png jpg svg txt）等打包，并返回路径字符串
- `file-loader` 与 `url-loader` 类似，但多了 `option.limit 1024(1KB)`
- `@import './b.css';` css 引入 css
- `postcss-loader` + `autoprefixer` plugins 自动补全 css 前缀
- `plugin` 可以在 `webpack` 运行的某一时刻，做一些事情

```
development -> devtool: 'cheap-module-eval-source-map'
production -> devtool: 'cheap-module-source-map'
```

- `webpack --watch` `webpack-dev-server` `node + webpack + webpack-middle-ware` 监听文件变化
- HMR 开启方法

```
devServer -> hot: true, hotOnly: true
plugins -> new new webpack.HotModuleReplacementPlugin()

index.js:
// 要把代码的副作用抵消，这样才不会出现2次
if (module.hot) {
  module.hot.accept('./n', () => {
    document.body.removeChild(document.getElementById('num'))
    number()
  })
}
```

- `@babel/polyfill` 会污染全局环境，所以写类库时，要用 [@babel/runtime](https://babeljs.io/docs/en/babel-runtime)
- `tree shaking` 只支持 ES module `optimization: { usedExports: true }` `import { xxx }` 只加载使用到的 xxx，不加载其他的。 `package.json -> sideEffects: ["*.css"]`: 不对 `.css` 文件进行 `tree shaking`
- `webpack-merge` merge(common, conf)
- `code splitting` 把打包分成几个 js 分别加载 `optimization: { splitChunks: { chunks: 'all' } }` [SplitChunksPlugin](https://webpack.js.org/plugins/split-chunks-plugin/)
- `import()` -> `@babel/plugin-syntax-dynamic-import` `import(/* webpackChunkName:"lodash" */ 'lodash').then( ... )`
- 提高 js 利用率，控制台中 `ctrl + shift + p -> show coverage` 使用更多的 `import()` 并增加 `prefetching/preloading` -> `import( /* webpackPrefech: true */ './click.js).then( ... )`
- css split `mini-css-extract-plugin` 不支持 HMR 所以用在线上环境中
- `output: { filename: '[name].[contenthash].js', chunkFilename: '[name].[contenthash].js' }` 浏览器缓存
- `runtimeChunk: { name: 'runtime' }` 把 minafest 抽离出来，使得老版本 webpack `[content]` 内容不变一定相同
- `Shimming` `new webpack.ProvidePlugin({ $: 'jquery' })`
- `imports-loader` 可以改变模块中的 this

* [前端开发者必备的 Nginx 知识](https://juejin.im/post/5c85a64d6fb9a04a0e2e038c)

### 2019-4-18 05:52:56

- marked 解析 markdown
- 除了 `<Link >` 跳转路由，还可以用 `this.context.router.history.push('/xxx')` 如监听 onClick
- `this.context.router.history.replace('/xxx')` 这个路由不会保存到历史记录，一般判断登陆状态，如果已登录，就 repalce ，这就保证了用户后退的时候不会后退到登陆页面，而是从哪里来，就后退到哪去，保证了正确性
- pm2 管理进程，收集日志，自动重启
- `curl [url]` 拿到 url 的网页字符串形式
- `ssh-copy-id root@47.102.124.140` 生成本地密钥，登陆 remote server 就可以不用每次都输入密码
- nginx 反向代理， 用 cra， `npm start` 测试

```
upstream cra-demo {
    server 127.0.0.1:3000; # 这里的端口号写你node.js运行的端口号，也就是要代理的端口号，我的项目跑在8081端口上
    keepalive 64;
}

server {
    listen 80; #这里的端口号是你要监听的端口号
    server_name 47.102.124.140; # 这里是你的服务器名称，也就是别人访问你服务的ip地址或域名，可以写多个，用空格隔开

    location / {
        proxy_set_header X-Real-IP $remote_addr;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header Host $http_host;
        proxy_set_header X-Nginx-Proxy true;
        proxy_set_header Connection "";
        proxy_pass http://cra-demo; # 这里要和最上面upstream后的应用名一致，可以自定义
    }
}
```

### 2019-4-17 09:27:47

- 删除当前目录下所有文件 `rm -rf *`
- 解压 `tar -zxvf xxx.tar.gz`
- ssr 需要解决的问题
  - 把真正的元素，替换到模版 html `<!-- app -->` 中
  - 使服务端 store 与客户端 store 同步，加入`window.__INITIAL_STATE__`
  - helmet 加入 seo 优化 `meta:description title style link`
- react 16 新特性
  - componentDidCatch
  - render 可以返回 array string
  - RactDOM.createPortal
  - 更好的 ssr

### 2019-4-16 12:19:35

- wp 视频
  - react 16 可以直接返回数组，不用总是一个根组件
  - redux 每次都产生一个新对象，所以每次都重新计算全部 react 组件，但由于 react 的 diff 算法，所以效率还是很高，但如果用 vue 效率就低了
  - mobx 和 vuex 概念类型 是 reactive 的，只有 1 份 store，直接在原来的地方修改
- [为什么写 super(props)](https://overreacted.io/why-do-we-write-super-props/)
  - 如果只写`super(props)`，在`constructor`中就不能用`this.props`

### 2019-4-13 11:46:44

- ubuntu [安装 nvm](https://gist.github.com/d2s/372b5943bce17b964a79)
  - `curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.33.11/install.sh | bash`
  - `nvm install v10.15.3`
- wp re 视频
  - grunt glup 注册任务
  - seajs requirejs
  - npm bower jspm
  - webpack rollup(**tree shaking** -> suck as loadsh) browserify
  - styled-components css in js
  - 架构能力：预期可能出现的问题并在一开始就规避
  - 工程架构：代码 lint，不同环境排除差异，git commit 预处理 项目架构：业务代码分层，更好实现功能，扩展性
  - 网络优化
    - 合并资源文件，减少 http 请求，一般并发 http 请求有限制，浏览器大多是 8 个，移动端 6 个

### 2019-4-12 08:36:57

- 完善 redux todos
- 了解 [cra](https://facebook.github.io/create-react-app/)

### 2019-4-11 22:55:48

- 了解 vscode task
- 修复 [redux todo](https://redux.js.org/basics/example#action-creators)

### 2019-4-10 15:37:50

- 完成 高阶组件 视频
- 完善 https://github.com/Acmu/react-start 加入 redux
- snippets `rce impt rafcp rfcp`

### 2019-4-9 05:50:36

- [React 高级教程之高阶组件](https://www.imooc.com/learn/1075)
  - h5 标签 `header section footer article nav aside`
  - HOC 应用
    - 代理方式 继承自 React.Component (这种使用较多)
    - 继承方式 继承自 WrappedComponent
- [Creating a React App… From Scratch](https://blog.usejournal.com/creating-a-react-app-from-scratch-f3c693b84658)
  - 扩展的项目 https://github.com/Acmu/react-start
  - webpack 配置理解
- get new skill: `xxx site:stackoverflow.com` can search only in the site.

### 2019-4-8 08:35:31

- [GraphQL 搭配 Koa](https://juejin.im/post/5a49e5ccf265da430d585cfd)
  - mongoose

### 2019-4-7 07:36:31

- [普通人的网页配色方案](http://www.ruanyifeng.com/blog/2019/03/coloring-scheme.html)
  - https://flatuicolors.com/palette/defo
  - https://www.materialpalette.com/deep-purple/teal
  - http://www.flatuicolorpicker.com/red-rgba-color-code
  - https://coolors.co/
  - https://www.materialui.co/colors
  - http://brandcolors.net/
  - 收集 http://www.sohu.com/a/234226326_100112198
- [从晋升看阿里层级](https://www.bilibili.com/read/cv1100994)
  - 影响力、培养新人能力、任务，时间优先级分配、解决复杂问题的能力
- [敏捷开发](http://www.ruanyifeng.com/blog/2019/03/agile-development.html)
  - 增量开发加上迭代开发，才算真正的敏捷开发。
- [Grid 布局教程](http://www.ruanyifeng.com/blog/2019/03/grid-layout-tutorial.html)
- [浏览器存储](https://juejin.im/post/5c8e6fa8e51d453ec75168cd)
  - sercure 只能在 https 中携带 cookie
  - same-site 不能在跨域请求中携带 cookie，减少 csrf 攻击
  - sessionStorage 即便是相同域名下的两个页面，只要它们不在同一个浏览器窗口中打开，那么它们的 sessionStorage 内容便无法共享
  - sessionStorage 可以有效对表单信息进行维护，比如刷新时，表单信息不丢失。
- [mongodb 入门](https://www.bilibili.com/video/av24311263?from=search&seid=18225452499749612871)
  - NoSQL 不用 SQL 语言来编写
  - `show dbs; show collections; db.createCollection('posts'); db.posts.insert({}); db.posts.find()`

### 2019-4-6 11:11:57

- [redis 入门](https://www.imooc.com/video/14324)
  - 5 种类型 `string list set hash sort set`
- [git tag](https://www.jianshu.com/p/cdd80dd15593)
  - tag 可以生成 release
  - tag 对应一个 commit id
- [Nginx 容器教程](http://www.ruanyifeng.com/blog/2018/02/nginx-docker.html)
  - `docker run --rm -p 8080:80 -d --name mynx -v $PWD/html:/usr/share/nginx/html nginx`
- [Docker 微服务教程](http://www.ruanyifeng.com/blog/2018/02/docker-wordpress-tutorial.html)
- [Node 定时器详解](http://www.ruanyifeng.com/blog/2018/02/node-event-loop.html)

  - Node 规定，process.nextTick 和 Promise 的回调函数，追加在本轮循环，即同步任务一旦执行完成，就开始执行它们。而 setTimeout、setInterval、setImmediate 的回调函数，追加在次轮循环。
  - 事件循环六个阶段
    1. timers
    2. I/O callbacks
    3. idle, prepare
    4. poll
    5. check
    6. close callbacks

### 2019-4-5 17:11:14

- [写一个 Koa](https://juejin.im/post/5ba48fc4e51d450e704277fa)
- [入门 docker](https://www.imooc.com/learn/867) ghost 搭建博客
- [Docker 从入门到实践](https://docker_practice.gitee.io/image/pull.html)

### 2019-4-4 22:57:52

- 解决我的电脑 win10cpu 占用高问题

### 2019-4-3 14:01:05

- [vsc 自定义主题](https://blog.csdn.net/liaozhenting/article/details/77654722)
  - 进入插件目录`C:\Users\你的用户名\.vscode\extensions\ms-vscode.theme-tomorrowkit-0.1.4\themes` 用编辑器打开，之后修改
- [koa 源码](https://juejin.im/post/5914fdce44d904006c44dfac)

### 2019-4-2 22:14:49

- 加 ssd，升级 win 10
- 看到[这里](http://www.runoob.com/nodejs/nodejs-express-framework.html)
- [多账号 ssh 配置](https://www.cnblogs.com/libin-1/p/5986430.html)
  - `ssh-keygen -t rsa -C "邮箱地址" -f ~/.ssh/github_jslite` 会生成 github_jslite 和 github_jslite.pub 这两个文件
  - `ssh -T git@github.com` #测试是否成功

---

<div align="center"><a href="./d1903.md">更多日报</a></div>
