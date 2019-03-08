Function.prototype.bind2 = function(context) {
  let self = this;
  let [, ...args] = [...arguments];
  let ftem = function() {};
  let fbound =  function() {
    self.apply(this instanceof self ? this : context, args.concat([...arguments]));
  };
  ftem.prototype = this.prototype;
  fbound.prototype = ftem.prototype;
  return fbound;
}


var value = 2;

var foo = {
    value: 1
};

function bar(name, age) {
    this.habit = 'shopping';
    console.log(this.value);
    console.log(name);
    console.log(age);
}

bar.prototype.friend = 'kevin';

var bindFoo = bar.bind2(foo, 'daisy');

var obj = new bindFoo('18');
// undefined
// daisy
// 18
console.log(obj.habit);
console.log(obj.friend);
// shopping
// kevin
