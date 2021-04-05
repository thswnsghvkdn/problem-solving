function solution(arr) {
    var answer = [];
    let one  = 0 , zero = 0;
    const add = (len , x , y ) =>
    {
        let o = 0, z = 0 , cnt = 0;
        if(len === 1)
        {
            if(arr[x][y] === 1) {
                one += 1;
                return 1;
            }
            else {
                zero += 1;
                return 0;
            } 
        }
        else 
        {
            len /= 2;
            let t  = 0 ;
            let flag = true;
            t = add(len ,x , y );
            if(t > 1) 
                flag = false;
            else 
                cnt += t;
            t = add(len , x + len , y);
            if(t > 1) 
                flag = false;
            else 
                cnt += t;
            t = add(len , x , y + len);
            if(t > 1) 
                flag = false;
            else 
                cnt += t;
            t = add(len , x + len , y + len);
            if(t > 1) 
             flag = false;
            else 
                cnt += t;
            if(flag)
            {
                if(cnt === 4){
                    one -= 3;
                    return 1;
                }
                else if(cnt ===0){
                    zero -= 3;
                    return 0;
                }
                else 
                    return 2;
            }
            else 
                return 2;
        }
    }
    add(arr.length , 0 , 0);
    answer.push(zero);
    answer.push(one);
    return answer;
}

solution([[1,1,1,1,1,1,1,1],[0,1,1,1,1,1,1,1],[0,0,0,0,1,1,1,1],[0,1,0,0,1,1,1,1],[0,0,0,0,0,0,1,1],[0,0,0,0,0,0,0,1],[0,0,0,0,1,0,0,1],[0,0,0,0,1,1,1,1]]);