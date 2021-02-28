function solution(numbers) {
    let answer = [];
    for(let i = 0 ; i < numbers.length - 1 ; i++)
    {
        let temp = numbers[i];
        for(let j = i + 1; j < numbers.length ; j++)
        {
            answer.push(temp + numbers[j]);
        }
    }
    answer = [...new Set(answer)];
    answer.sort((a, b) =>{
        return a - b;
    });
    return answer;
}
let answer = new Set([1,2,3,3])
let answer2 = [new Set([1,2,3,3])];

//console.log(answer);
console.log(answer2[0]);
