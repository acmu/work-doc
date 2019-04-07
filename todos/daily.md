# 每天都要写日报

- nginx mongodb
- [Docker 从入门到实践](https://docker_practice.gitee.io/image/pull.html)

### 2019-4-7 07:36:31

- [普通人的网页配色方案](http://www.ruanyifeng.com/blog/2019/03/coloring-scheme.html)
  - https://www.materialpalette.com/deep-purple/teal
  - https://flatuicolors.com/palette/defo
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
- GraphQL 搭配 Koa

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
