function solution(orders, course) {
  let ordered = {};
  let candidate = {};
  let MaxMenu = Array(11).fill(0);
  const makeOrder = (arr , course , start , food) =>{
    if(food.length === course)
    {
      ordered[food] = (ordered[food] || 0) + 1; 
      if(ordered[food] > 1) candidate[food] = ordered[food];
      MaxMenu[course] = Math.max(MaxMenu[course] , ordered[food]);
      return;
    }
    for(let i = start ; i < arr.length ; i++)
    {
      makeOrder(arr, course, i + 1 , food + arr[i]);
    }
  }

  orders.forEach(or =>{
    let ar = or.split('').sort();
    course.forEach(c => {
      makeOrder(ar, c , 0 , "");
    })
   });
   let answer = Object.keys(candidate).filter(x =>{
    return MaxMenu[x.length] === candidate[x];
   })
   answer.sort();
   return answer;
}

  solution(["XYZ", "XWY", "WXA"] , [2,3,4])

  