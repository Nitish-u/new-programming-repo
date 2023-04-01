let array1 = [25,36,49,64,81];
const squareRoot = array1.map(function(currentElement,index,arr){
    return `The value of square root of element at ${index} i.e., ${currentElement} of array ${arr} is ${Math.sqrt(currentElement)}`
});
console.log(squareRoot);
