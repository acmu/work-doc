# my webpack

## 2019-2-2 00:22

```shell
yarn init -y

yarn add webpack webpack-cli webpack-dev-server html-webpack-plugin --dev

yarn add style-loader css-loader less less-loader --dev

yarn add typescript ts-loader --dev

yarn add eslint eslint-loader babel-eslint --dev

```

哇，今天总算自己用了一下wp，还不错嘛，就配置了ts + less，目前来说就够了，config贴一下就睡了，明天继续努力~


```js
// webpack.config.js

const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
  entry: './src/index.ts',
  output: {
    filename: 'bundle.[hash:4].js',
    path: path.resolve('dist')
  },
  mode: 'development',
  plugins: [
    new HtmlWebpackPlugin({
      template: './src/index.html',
      hash: true,
    })
  ],
  module: {
    rules: [
      {
        test: /\.less$/,
        use: ['style-loader', 'css-loader', 'less-loader'],
        exclude: /node_modules/
      },
      {
        test: /\.ts$/,
        use: ['ts-loader'],
        exclude: /node_modules/
      }
    ]
  }
};
```

After having `webpack.config.js`, you can invoke Webpack without any arguments.

Nginx 
- 正向代理，如翻墙，对客户端认证，做缓存
- 反向代理，"它代理的是服务端"，主要用于服务器集群分布式部署的情况下，反向代理隐藏了服务器的信息。

将服务器接收到的请求按照规则分发的过程，称为负载均衡。


output.publicPath 是 devServer 的地址

Loaders: Allow you to preprocess files.

Attention, you have to use two loaders to transform CSS file. First is CSS-loader to read CSS file, and another one is Style-loader to insert `<style>` tag into HTML page.

url-loader transforms image files into `<img>`

html-webpack-plugin could create index.html for you, and open-browser-webpack-plugin could open a new browser tab when Webpack loads.

```js
// 可以定义DEV
var devFlagPlugin = new webpack.DefinePlugin({
  __DEV__: JSON.stringify(JSON.parse(process.env.DEBUG || 'false'))
});


// package.json
{
  // ...
  "scripts": {
    "dev": "cross-env DEBUG=true webpack-dev-server --open",
  },
  // ...
}
```



eslint babel pretter 配一下吧，[一位大神的eslint](./config.js)。

ts + react, node, graphQL



















```shell

```



```shell

```



```shell

```



```shell

```



```shell

```



```shell

```



```shell

```

```shell

```

