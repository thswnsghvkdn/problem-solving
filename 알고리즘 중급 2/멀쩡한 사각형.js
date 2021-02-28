function gcd(a , b) {
    let n1, n2;
    if(a >= b){
    n1 = a; n2 = b;
    }
    else {
        n1 = b ; n2 = a;
    }
    let n3 = n1 % n2;
    if(n3 === 0)
        return n2;
    else 
        return gcd(n3, n1);
}

function solution(w, h) {
    let answer = 1;
    let t = gcd(w, h);
    let n1 = w / t;
    let n2 = h / t;
    answer = n1 + n2 - 1;
    answer *= t;
    return answer;  
}

solution(8 , 12);