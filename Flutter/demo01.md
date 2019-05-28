
### Usage

直接复制到 lib/main.dart 中，效果如图：

[![Vnm90g.md.png](https://s2.ax1x.com/2019/05/29/Vnm90g.md.png)](https://imgchr.com/i/Vnm90g)

```dart
import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: '电影海报',
      home: Scaffold(
        appBar: AppBar(
          title: Text('电影海报'),
        ),
        body: GridView.count(
          padding: const EdgeInsets.all(10.0),
          crossAxisSpacing: 10.0,
          mainAxisSpacing: 5.0,
          crossAxisCount: 3,
          childAspectRatio: 0.7,
          children: <Widget>[
            new Image.network(
              'http://img5.mtime.cn/mg/2019/03/21/105842.67810645_170X256X4.jpg',
              fit: BoxFit.cover,
            ),
            new Image.network(
              'http://img5.mtime.cn/mg/2019/04/10/102844.93012572_170X256X4.jpg',
              fit: BoxFit.cover,
            ),
            new Image.network(
              'http://img5.mtime.cn/mg/2019/04/19/092928.24468397_170X256X4.jpg',
              fit: BoxFit.cover,
            ),
            new Image.network(
              'http://img5.mtime.cn/mg/2019/03/29/095612.14234221_170X256X4.jpg',
              fit: BoxFit.cover,
            ),
            new Image.network(
              'http://img5.mtime.cn/mg/2019/04/01/170857.92282290_170X256X4.jpg',
              fit: BoxFit.cover,
            ),
            new Image.network(
              'http://img5.mtime.cn/mg/2019/04/16/103242.17522323_170X256X4.jpg',
              fit: BoxFit.cover,
            ),
            new Image.network(
              'http://img5.mtime.cn/mg/2019/04/04/092846.29725044_1280X720X2.jpg',
              fit: BoxFit.cover,
            ),
            new Image.network(
              'http://img5.mtime.cn/mg/2019/01/31/100731.93352385_1280X720X2.jpg',
              fit: BoxFit.cover,
            ),
            new Image.network(
              'http://img5.mtime.cn/mg/2019/04/15/095157.26388695_1280X720X2.jpg',
              fit: BoxFit.cover,
            ),
            new Image.network(
              'http://img5.mtime.cn/mg/2019/03/21/105842.67810645_170X256X4.jpg',
              fit: BoxFit.cover,
            ),
            new Image.network(
              'http://img5.mtime.cn/mg/2019/04/10/102844.93012572_170X256X4.jpg',
              fit: BoxFit.cover,
            ),
            new Image.network(
              'http://img5.mtime.cn/mg/2019/04/19/092928.24468397_170X256X4.jpg',
              fit: BoxFit.cover,
            ),
          ],
        ),
      ),
    );
  }
}
```
