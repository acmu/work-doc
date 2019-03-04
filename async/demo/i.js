/**
 * @author GitHub: wen98y
 * @name MinYuan
 */

const arrLength = 10
const arrRange = 30
const pillarWidth = 40
const pillarGap = 0.5 * pillarWidth

// 生成数据
const generateArr = () => {
  return Array.from({ length: arrLength }).map(() => Math.ceil(Math.random() * arrRange))
}

// 交换2个元素
function exchange(el1, el2) {
  var ep1 = el1.parentNode,
    ep2 = el2.parentNode,
    index1 = Array.prototype.indexOf.call(ep1.children, el1),
    index2 = Array.prototype.indexOf.call(ep2.children, el2)
  ep2.insertBefore(el1, ep2.children[index2])
  ep1.insertBefore(el2, ep1.children[index1])
}

// 添加active类
const addActive = (i, j) => {
  const block = document.querySelector('#sort')
  Array.from(block.children).forEach((v, idx) => {
    if (idx === i || idx === j) {
      v.className = 'active'
    } else {
      v.className = ''
    }
  })
}

const compare = (x, y) => x - y

const swapTransform = (a, i, j, swap = true) => {
  if (swap) {
    // 交换数据
    a[i] ^= a[j]
    a[j] ^= a[i]
    a[i] ^= a[j]
  }

  addActive(i, j)
  return new Promise((resolve, reject) => {
    const block = document.querySelector('#sort')
    const ti = 500
    return setTimeout(() => {
      if (swap) {
        // 如果要交换，就再等0.5秒
        exchange(block.children[i], block.children[j])
        setTimeout(() => {
          resolve()
        }, ti)
      } else {
        resolve()
      }
    }, ti)
  })
}

// 冒泡排序
const bubbleSort = async a => {
  const len = a.length
  for (let i = 0; i < len; i++) {
    for (let j = 0; j < len - i - 1; j++) {
      await swapTransform(a, j, j + 1, compare(a[j], a[j + 1]) > 0)
    }
  }
  return a
}

// 生成图表
const generateChart = () => {
  const block = document.querySelector('#sort')
  block.style.width = `${arrLength * (pillarGap + pillarWidth)}px`
  // 生成子元素
  for (let i = 0; i < arrLength; i++) {
    const newDiv = document.createElement('div')
    Object.assign(newDiv.style, {
      height: `${((arr[i] / arrRange) * 100).toFixed(0)}%`,
      width: `${pillarWidth}px`,
      marginLeft: `${pillarGap}px`
    })
    newDiv.innerText = arr[i]
    block.append(newDiv)
  }
}

const arr = generateArr()
console.log(arr)

generateChart()

bubbleSort(arr).then(a => {
  console.log('Finish')
  console.log(a)
})
